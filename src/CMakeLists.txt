add_subdirectory(core)
add_subdirectory(cpu)
add_subdirectory(gpu)

# Example top-level executable for testing
add_executable(hyperion_test main_gpu.c)
target_include_directories(hyperion_test PRIVATE ${CMAKE_SOURCE_DIR}/src/gpu)
target_link_libraries(hyperion_test PRIVATE burner_gpu)

