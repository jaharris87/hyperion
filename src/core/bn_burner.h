#ifndef __BN_BURNER_H
#define __BN_BURNER_H

typedef unsigned char uchar; // Boolean workaround for cython

void hyperion_burner_(double* tstep, double* temp, double* dens, double* xin,
                      double* xout, double* sdotrate, uchar* burned_zone,
                      int* size);

#endif
