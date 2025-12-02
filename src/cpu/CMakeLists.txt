add_library(burner_cpu STATIC burner_cpu.c)
target_compile_definitions(burner_cpu PUBLIC SIZE=${SIZE})
target_include_directories(burner_cpu PUBLIC ${CMAKE_SOURCE_DIR}/src/gpu)

