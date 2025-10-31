#include "tickertape.h"
#include <stdlib.h>

FILE *tickertape_file = NULL;

void tickertape_init(const char *filename) {
    tickertape_file = fopen(filename, "w");
    if (!tickertape_file) {
        perror("Tickertape: Error opening file");
        exit(EXIT_FAILURE);
    }
}

void tickertape_log(const char *fmt, ...) {
    if (!tickertape_file) return;  // do nothing if not initialized

    va_list args;
    va_start(args, fmt);
    vfprintf(tickertape_file, fmt, args);
    fprintf(tickertape_file, "\n");  // optional newline
    fflush(tickertape_file);
    va_end(args);
}

void tickertape_close(void) {
    if (tickertape_file) {
        fclose(tickertape_file);
        tickertape_file = NULL;
    }
}

