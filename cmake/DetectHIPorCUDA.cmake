# DetectHIPorCUDA.cmake
# Provides HIP_FOUND, CUDA_FOUND, and helper interface `gpu_backend_target`

if(NOT DEFINED USE_GPU)
  set(USE_GPU "HIP" CACHE STRING "")
endif()

if(USE_GPU STREQUAL "HIP")
  find_package(HIP REQUIRED)
  set(HIP_FOUND TRUE)
  set(CUDA_FOUND FALSE)
  message(STATUS "HIP found: ${HIP_VERSION}")
elseif(USE_GPU STREQUAL "CUDA")
  find_package(CUDA REQUIRED)
  set(CUDA_FOUND TRUE)
  set(HIP_FOUND FALSE)
  message(STATUS "CUDA found")
else()
  set(HIP_FOUND FALSE)
  set(CUDA_FOUND FALSE)
  message(STATUS "No GPU backend selected (CPU-only build)")
endif()

