#include "bn_burner.h"

#include <stdio.h>
#include <stdlib.h>

// TODO: I'm not exactly sure how these map out... I'm using some wrong on
// "purpose"
void hyperion_burner_(double* tstep, double* temp, double* dens, double* xin,
                      double* xout, double* sdotrate, uchar* burned_zone,
                      int* zone, int* kstep, int* size) {

    // xin, xOut, zone <-- are array types
    // (thus they are treated as generic 1-dim ptrs here)

    printf("values: \n");
    printf("tstep: %f\n", *tstep);
    printf("temp: %f\n", *temp);
    printf("dens: %f\n", *dens);
    printf("sdotrate: %f\n", *sdotrate);
    printf("burned zone: %b\n", *burned_zone);
    printf("kstep: %i\n", *kstep);
    printf("size: %i\n", *size);

    // *size = *size + 100;
    
    for (int i = 0; i < *size; i++) {
        printf("xin[%i]: %f\n", i, xin[i]);
    }
    for (int i = 0; i < *size; i++) {
        printf("xout: %f\n", xout[i]);
    }
    for (int i = 0; i < *size; i++) {
        printf("zone: %i\n", zone[i]);
    }

    exit(1);

    return;
}
