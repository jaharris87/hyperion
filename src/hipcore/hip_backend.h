#pragma once

#ifndef HIP_BACKEND_H
#define HIP_BACKEND_H


/* Initialize HIP backend:
 *  - select device
 *  - prepare runtime
 */
int hip_backend_init(int zones);

/* Finalize HIP backend:
 *  - free all device allocations
 *  - reset backend state
 */
int hip_backend_finalize(void);

static int test_device(struct hipDeviceProp_t* device);

#endif
