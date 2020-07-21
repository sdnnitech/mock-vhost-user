#include "packet.hpp"

#define PROC_CLT_S 0
#define PROC_CLT_R 1
#define PROC_SRV 2
#define TOTAL_CLT 3
#define TOTAL_SRV 4
#define NONE 5

#define INFO_CPU NONE

#define CPU_BIND

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

constexpr int_fast32_t SIZE_BATCH = 32;
constexpr int_fast32_t SIZE_RING = 128;
constexpr int_fast32_t SIZE_POOL = 128;

constexpr int_fast32_t NUM_MOD = SIZE_RING - 1;
constexpr int_fast32_t NUM_PMOD = SIZE_POOL / 2;

enum rsource {
	CLT = 0,
	SRV = NUM_PMOD,
};

class desc {
public:
	int_fast32_t id;
	packet *entry;

	void set_param(int_fast32_t, packet*);
	void delete_info();
};

class ring {
public:
	int_fast32_t rsrv_idx;
	int_fast32_t recv_idx;
	int_fast32_t proc_idx;
	int_fast32_t pindex;
	int_fast8_t size;
	desc descs[SIZE_RING];

	ring();
	void operator=(ring&&);

	void ipush(packet[], packet[], rsource, int_fast8_t);
	void pull(packet[], packet[], int_fast8_t);
	void init_descs();
	void wait_push(int_fast32_t, int_fast32_t, packet[]);
	void wait_pull(int_fast32_t);
};

#include "cbuffer.hpp"
