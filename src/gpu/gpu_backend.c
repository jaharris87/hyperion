#include "gpu_backend.h"
#include <stdio.h>

#if defined(ENABLE_GPU)

/* ================= HIP BACKEND ================= */

#if defined(USE_HIP)

#include "hipcore/bn_burner_gpu.h"
#include "hipcore/hip_backend.h"

/* Fortran interface */
void hyperion_burner_(double* tstep,
                      double* temp,
                      double* dens,
                      double* xin,
                      double* xout,
                      double* sdotrate,
                      unsigned char* burned_zone,
                      int* zones);

int gpu_backend_init(int zones)
{
    fprintf(stderr, "GPU_BACKEND_INIT (HIP) entered\n");
    fflush(stderr);

    return hip_backend_init(zones);
}

int gpu_backend_finalize(void)
{
    return hip_backend_finalize();
}

void gpu_burner(double* tstep,
                double* temp,
                double* dens,
                double* xin,
                double* xout,
                double* sdotrate,
                unsigned char* burned_zone,
                int* zones)
{
    hyperion_burner_(tstep, temp, dens, xin, xout,
                     sdotrate, burned_zone, zones);
}

#else
#error "ENABLE_GPU defined but USE_HIP is not set"
#endif  /* USE_HIP */

#else  /* ================= CPU FALLBACK ================= */

#include "burner_cpu.h"

int gpu_backend_init(int zones)
{
    (void)zones;
    fprintf(stderr, "GPU backend disabled, using CPU\n");
    fflush(stderr);
    return 0;
}

int gpu_backend_finalize(void)
{
    return 0;
}

void gpu_burner(double* tstep,
                double* temp,
                double* dens,
                double* xin,
                double* xout,
                double* sdotrate,
                unsigned char* burned_zone,
                int* zones)
{
    hyperion_burner_cpu(tstep, temp, dens, xin, xout,
                        sdotrate, burned_zone, zones);
}

#endif /* ENABLE_GPU */

