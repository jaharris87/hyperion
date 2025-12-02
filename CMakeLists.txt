cmake_minimum_required(VERSION 3.24)
project(hyperion_burner LANGUAGES C CXX)

# Allow user to select backend at configure time
set(USE_GPU "HIP" CACHE STRING "GPU backend: HIP | CUDA | NONE")
set_property(CACHE USE_GPU PROPERTY STRINGS "HIP" "CUDA" "NONE")

# Option to compile device code in debug
option(DEVICE_DEBUG "Compile device code with debug symbols" OFF)
option(BUILD_TESTS "Build unit tests" ON)

# Add cmake helper modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Detect HIP or CUDA if requested
include(DetectHIPorCUDA)

# Setup compiler flags per backend
if(USE_GPU STREQUAL "HIP")
  enable_language(HIP)
  set(DEVICE_COMPILER HIP)
elseif(USE_GPU STREQUAL "CUDA")
  enable_language(CUDA)
  set(DEVICE_COMPILER CUDA)
else()
  set(DEVICE_COMPILER NONE)
endif()

# Common options
add_compile_options(-Wall -Wextra -fPIC)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type (Release/Debug)" FORCE)
endif()

# Expose a compile-time SIZE macro default (override with -DSIZE=150)
if(NOT DEFINED SIZE)
  set(SIZE 16 CACHE STRING "Number of species (compile-time)")
endif()
message(STATUS "Configured SIZE = ${SIZE}, USE_GPU = ${USE_GPU}")

# Subdirectories
add_subdirectory(src)
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

