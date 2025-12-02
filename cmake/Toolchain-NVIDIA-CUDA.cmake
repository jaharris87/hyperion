# Toolchain-Frontier-CUDA.cmake
# Example toolchain; invoked as -DCMAKE_TOOLCHAIN_FILE=...

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER cc)
set(CMAKE_CXX_COMPILER CC)
set(CMAKE_HIP_COMPILER nvgcc)

# Set target GPU architecture for NVIDIA (update if hardware changes)
set(CMAKE_CUDA_ARCHITECTURES "H100" CACHE STRING "CUDA arch")
message(STATUS "Toolchain: NVIDIA CUDA; CUDA arch = ${CMAKE_CUDA_ARCHITECTURES}")

