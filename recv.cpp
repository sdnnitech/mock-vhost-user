#include "buffer.hpp"
#include "shm.hpp"

//#define PRINT

void send_packet(ring&, packet[], info_opt);
void recv_packet(ring&, packet[], info_opt);
void check_verification(packet);
void judge_packet(packet[], int_fast32_t);
void init_resource();

int main(int argc, char **argv) {
	// 初期設定
	int bfd = open_shmfile("shm_buf", SIZE_SHM, false);
	packet *pool = (packet*)mmap(NULL, SIZE_SHM, PROT_READ | PROT_WRITE, MAP_SHARED, bfd, 0);
	ring *csring = (ring*)(pool + SIZE_POOL);
	ring *scring = (ring*)(csring + 1);

	info_opt opt = get_opt(argc, argv);
//	assert(opt.size_batch < SIZE_POOL);

	bool *flag = (bool*)(scring + 1);
	*flag = true;

	recv_packet(*scring, pool, opt);

	shm_unlink("shm_buf");

	return 0;
}

void recv_packet(ring &scring, packet pool[SIZE_POOL], info_opt opt) {
#ifdef CPU_BIND
	bind_core(6);
#endif

	int_fast32_t num_fin = opt.size_batch;
	bool is_stream = (opt.stream == ON) ? true : false;
#ifndef AVOID_CLT
	packet *parray;
	parray = new (std::align_val_t{64}) packet[opt.size_batch];
	assert((intptr_t(pool) & 63) == 0);
	assert((intptr_t(parray) & 63) == 0);
#endif

	for(int_fast32_t i = NUM_PACKET; 0 < i; i -= num_fin) {
		// 受信パケット数の決定
		if(unlikely(i < num_fin)) {
			num_fin = i;
		}
		
		// パケット受信
#ifdef AVOID_CLT
		scring.pull_avoid(num_fin);
#else
		scring.pull(parray, pool, num_fin, is_stream);
#endif

//		// パケット検証
//#ifdef AVOID_CLT
//		for(volatile int_fast32_t i = 0; i < num_fin; i++) {
//			;
//		}
//#else
//		
//		judge_packet(parray, num_fin);
//#endif
	}

#ifndef AVOID_CLT
	delete(parray);
#endif
}

inline void check_verification(packet p) {
#ifdef READ_SRV
	if(unlikely(p.id == -1)) {
#else
	if(unlikely(p.id != static_cast<signed>(p.verification ^ 0xffffffff))) {
#endif
		std::printf("verification error\n");
		p.print();
		std::printf("not 0x%x\n", (p.id ^ 0xffffffff));
		exit(1);
	}
}

inline void judge_packet(packet parray[], int_fast32_t num_fin) {
	for(volatile int_fast32_t i = 0; i < num_fin; i++) {
		check_verification(parray[i]);

#ifndef READ_SRV
		if(unlikely((parray[i].id & 8388607) == 0)) {
#if INFO_CPU == PROC_CLT_R
			std::printf("%g%%\n", getCurrentValue_p());
#elif INFO_CPU == TOTAL_CLT
			std::printf("%g%%\n", getCurrentValue_t());
#endif
#ifdef PRINT
			parray[i].print();
#endif
		}
#endif
	}
}

void init_resource() {
#if INFO_CPU == PROC_CLT_S || INFO_CPU == PROC_CLT_R || INFO_CPU == PROC_SRV
	init_p();
#elif INFO_CPU == TOTAL_CLT || INFO_CPU == TOTAL_SRV
	init_t();
#endif

#ifdef DUMMY_FULL
	set_global_dummy();
#endif
}