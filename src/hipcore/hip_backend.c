#include "bn_burner_gpu.h"
#include "hip_debug_kernel.h"
#include <hip/hip_runtime.h>
#include <stdio.h>

int select_best_device(void);

int hip_backend_init(int zones)
{
    fprintf(stderr, ">>> ENTERED hip_backend_init (zones=%d)\n", zones);
    fflush(stderr);
    int dev = select_best_device();
    if (dev < 0) {
	fprintf(stderr, "No suitable HIP device found\n");
        return EXIT_FAILURE;
    }

    hipDeviceProp_t prop;
    hipError_t err = hipGetDeviceProperties(&prop, dev);
    if (err != hipSuccess) {
        fprintf(stderr, "hipGetDeviceProperties failed: %d\n", err);
        return EXIT_FAILURE;
    }
    printf("Using HIP device %d: %s\n", dev, prop.name);
    fflush(stderr);

    return EXIT_SUCCESS;

}

int hip_backend_finalize(void)
{
    hip_killall_device_ptrs();
    return 0; 
}

int select_best_device(void)
{
    int num_devices = 0;
    hipError_t err = hipGetDeviceCount(&num_devices);
    fprintf(stderr, "hipGetDeviceCount returned %d devices, err=%d\n", num_devices, err);
    fflush(stderr);

    if (num_devices == 0) {
        fprintf(stderr, "No HIP devices found\n");
        return -1;
    }

    int best_device = 0;
    double best_score = 0.0;

    for (int i = 0; i < num_devices; i++) {
        hipDeviceProp_t prop;
        err = hipGetDeviceProperties(&prop, i);
        if (err != hipSuccess) {
            fprintf(stderr, "hipGetDeviceProperties(%d) failed: %d\n", i, err);
            continue;
        }

        double score = (double)prop.clockRate * prop.multiProcessorCount;
        if (score > best_score) {
            best_score = score;
            best_device = i;
        }
    }

    err = hipSetDevice(best_device);
    if (err != hipSuccess) {
        fprintf(stderr, "hipSetDevice(%d) failed: %d\n", best_device, err);
        return -1;
    }
    fprintf(stderr, "Selected device %d\n", best_device);
    fflush(stderr);

    return best_device;
}


int test_device(struct hipDeviceProp_t* device) {
    int error;

    printf("beginning benchmark (%s)\n", device->name);

    double* h_A = malloc(3 * sizeof(double));
    h_A[0] = 2.0;
    h_A[1] = 4.0;
    h_A[2] = 6.0;
    double* h_B = malloc(3 * sizeof(double));
    h_B[0] = 0.0;
    h_B[1] = 1.0;
    h_B[2] = 2.0;
    double* h_C = malloc(3 * sizeof(double));

    void** arg = malloc(sizeof(void*) * 3);
    hipMalloc(&arg[0], sizeof(double) * 3);
    hipMalloc(&arg[1], sizeof(double) * 3);
    if ((error = hipMalloc(&arg[2], sizeof(double) * 3)) != hipSuccess) {
        printf(
            "ERROR: encountered error allocating device mem: %i\n",
            error);
        return EXIT_FAILURE;
    }

    hipMemcpy(arg[0], h_A, 3 * sizeof(double), hipMemcpyHostToDevice);
    hipMemcpy(arg[1], h_B, 3 * sizeof(double), hipMemcpyHostToDevice);
    if ((error = hipMemcpy(arg[2], h_C, 3 * sizeof(double),
                           hipMemcpyHostToDevice)) != hipSuccess) {
        printf("ERROR: encountered error hip memcpy: %i\n", error);
        return EXIT_FAILURE;
    }

    int sharedmem_allocation = 0 * sizeof(double);
    
    struct dim3 blockdim = {3, 1, 1};
    struct dim3 griddim = {1, 1, 1};
    if ((error = hipConfigureCall(griddim, blockdim, sharedmem_allocation,
                                  hipStreamDefault)) != hipSuccess) {
        printf("ERROR: encountered error configuring kernel: %i\n",
               error);
        return EXIT_FAILURE;
    }

    void** truearg = malloc(sizeof(void*) * 3);
    truearg[0] = &arg[0];
    truearg[1] = &arg[1];
    truearg[2] = &arg[2];
    
    if ((error = hipLaunchKernel(vec_mul, griddim, blockdim, truearg,
                                 sharedmem_allocation, hipStreamDefault)) !=
        hipSuccess) {
        printf("ERROR: encountered error launching kernel: %i\n",
               error);
        return 0;
    }

    hipMemcpy(h_C, arg[2], 3 * sizeof(double), hipMemcpyDeviceToHost);

    printf("Output: {  ");
    for (int i = 0; i < 3; i++) {
        printf("%f  ", h_C[i]);
    }
    
    printf("}\n");
    hipFree(arg[0]);
    hipFree(arg[1]);
    hipFree(arg[2]);
    free(arg);

    return EXIT_SUCCESS;
}
