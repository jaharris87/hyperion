# Toolchain-Frontier-HIP.cmake
# Example toolchain; invoked as -DCMAKE_TOOLCHAIN_FILE=...

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER cc)
set(CMAKE_CXX_COMPILER CC)
set(CMAKE_HIP_COMPILER hipcc)

# Set target GPU architecture for ROCm (update if hardware changes)
set(CMAKE_HIP_ARCHITECTURES "gfx90a" CACHE STRING "HIP arch")
message(STATUS "Toolchain: Frontier HIP; HIP arch = ${CMAKE_HIP_ARCHITECTURES}")

