#include "init.h"

#include "store.h"

#if SIZE == 16
#define NETWORK_SIZE 16
#define NUM_REACTIONS 48
#define NETWORK_FILE "data/network-alpha.txt"
#define RATE_FILE "data/ratelibrary-alpha.txt"
#endif // __SIZE_16

#if SIZE == 150
#define NETWORK_SIZE 150
#define NUM_REACTIONS 1604
#define NETWORK_FILE "data/network-150.txt"
#define RATE_FILE "data/ratelibrary-150.txt"
#endif // __SIZE_150

#if SIZE == 365
#define NETWORK_SIZE 365
#define NUM_REACTIONS 4395
#define NETWORK_FILE "data/network-365.txt"
#define RATE_FILE "data/ratelibrary-365.txt"
#endif // __SIZE_365

#include "../parse-data/parser.h"

void hyperion_init_() {
    
    rate_library_create(RATE_FILE, NUM_REACTIONS);
    network_create(NETWORK_FILE, NETWORK_SIZE);
    data_init();

    return;
}
