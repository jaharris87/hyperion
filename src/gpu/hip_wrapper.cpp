// hip_wrapper.cpp
#include "bn_burner_gpu.h"
#include <hip/hip_runtime.h>
#include <cstdio>
#include <cstdlib>

extern "C" void hyperion_burner_(double* tstep, double* temp, double* dens,
                                 double* xin, double* xout, double* sdotrate,
                                 unsigned char* burned_zone, int* size);

// Forward declare the kernel (signature must match bn_burner_gpu.hip)
extern "C" __global__ void hyperion_burner_dev_kernel(
    /* kernel args... */);

// Simple wrapper that launches the kernel (one-block-per-zone)
extern "C" void hyperion_burner_(double* tstep, double* temp, double* dens,
                                 double* xin, double* xout, double* sdotrate,
                                 unsigned char* burned_zone, int* size) {
    int zones = *size;
    // Copy to device pointers previously allocated by device_init
    // We assume device_init set device pointers in global args[] (see earlier)
    // For clarity, you'll implement explicit device pointers and pass them.

    const int threadsPerBlock = 256;
    dim3 block(threadsPerBlock);
    dim3 grid(zones);

    // Launch kernel: adapt parameters to your actual kernel args
    hipLaunchKernelGGL((hyperion_burner_dev_kernel), grid, block, 0, 0,
                       /* kernel args: device pointers and meta ints */);

    hipError_t err = hipGetLastError();
    if (err != hipSuccess) {
        fprintf(stderr, "hipLaunchKernelGGL failed: %s\n", hipGetErrorString(err));
        abort();
    }
}

