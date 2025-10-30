#include "read_values.h"
#include "store.h"

#include <string.h>

void get_x_(double* dest, int size) {
    memcpy(dest, x, size * sizeof(double));
    return;
}
