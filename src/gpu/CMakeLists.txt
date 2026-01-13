add_library(gpu_backend
    gpu_backend.c
)

target_include_directories(gpu_backend
    PUBLIC ${PROJECT_SOURCE_DIR}/src
)

# Always build HIP backend
target_compile_definitions(gpu_backend PUBLIC ENABLE_GPU USE_HIP)
target_link_libraries(gpu_backend PUBLIC burner_gpu)

target_compile_features(gpu_backend PUBLIC c_std_11)

