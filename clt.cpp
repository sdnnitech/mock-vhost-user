#include <chrono>
#include "buffer.hpp"
#include "shm.hpp"

void send_packet(ring*, packet*, int);
void recv_packet(ring*, packet*, int);
bool check_verification(packet*);

static const std::string base_text = "take";

int main() {
	puts("begin");

	int bfd = open_shmfile("shm_buf", SIZE_SHM, true);
	ring *csring = (ring*)mmap(NULL, SIZE_SHM, PROT_READ | PROT_WRITE, MAP_SHARED, bfd, 0);
	*csring = ring();
	ring *scring = (ring*)(csring + 1);
	*scring = ring();
	packet *pool = (packet*)(scring + 1);
	memset(pool, 0, sizeof(packet) * SIZE_POOL);
	volatile bool *flag = (volatile bool*)(pool + SIZE_POOL);
	*flag = false;

	set_packet_nums(nums);
	std::cout << "size: " << sizeof(ring) * 2 + sizeof(packet) * SIZE_POOL << std::endl;

	while(!*flag) {
		;
	}

	int nthread = NUM_THREAD * 2 - 1;
	std::thread threads[nthread];
	for(int i = 0; i < NUM_THREAD; i++) {
		threads[i] = std::thread(send_packet, std::ref(csring), std::ref(pool), i);
	}
	for(int i = NUM_THREAD; i < nthread; i++) {
		threads[i] = std::thread(recv_packet, std::ref(scring), std::ref(pool), i - NUM_THREAD);
	}

	std::chrono::system_clock::time_point start, end;
	start = std::chrono::system_clock::now();
	recv_packet(scring, pool, NUM_THREAD - 1);
	for(int i = 0; i < nthread; i++) {
		threads[i].join();
	}
	end = std::chrono::system_clock::now();

	shm_unlink("shm_buf");
	double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << elapsed / 1000 << "sec" << std::endl;

	return 0;
}

void send_packet(ring *csring, packet *pool, int id) {
	int index_begin = nums[id];
	int index_end = nums[id + 1];
	std::string text;
	packet parray[64];

	for(int i = index_begin; i < index_end; i += 64) {
		int idx = i + 64;
		if(index_end < idx) {
			idx = index_end;
		}
		for(int j = i; j < idx; j++) {
			parray[j - i] = packet(j);
		}

		idx -= i;
		for(int j = 0; j < idx;) {
			if(csring->dinit(id)) {
				while(true) {
					if(csring->push(parray[j], pool, CLT, id)) {
						j++;
						break;
					}
				}
			}
		}
	}
}

void recv_packet(ring *scring, packet *pool, int id) {
	int index_begin = nums[id];
	int index_end = nums[id + 1];

	for(int i = index_begin; i < index_end;) {
		packet p = scring->pull(pool, id);
		if(0 < p.len) {
			if(!check_verification(&p)) {
				puts("verification error");
				exit(1);
			}

#if 1
			if(p.id % 5000000 == 0) {
					p.print();
			}
#endif
			i++;
		}
	}
}

bool check_verification(packet *p) {
	return p->verification ^ 0xffffffff == p->id;
}
