cmake_minimum_required(VERSION 3.21)

project(hyperion LANGUAGES C CXX HIP)

option(ENABLE_GPU "Enable GPU build" ON)
set(USE_GPU "HIP" CACHE STRING "GPU backend (HIP or CUDA)")

# Define reaction network size
if (NOT DEFINED SIZE)
	set(SIZE 16 CACHE STRING "Reaction network size")
endif()

add_compile_definitions(SIZE=${SIZE})

# Add main source directory
add_subdirectory(src)
#add_subdirectory(tests)

