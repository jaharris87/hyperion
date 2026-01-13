add_subdirectory(parse-data)
add_subdirectory(core)

if(ENABLE_GPU)
	#add_subdirectory(gpu) # <-- this defines burner_gpu
	add_subdirectory(hipcore)
endif()

add_subdirectory(gpu) #Nessisary to build even if only cpu

add_executable(hyperion_test main_gpu.c)
add_dependencies(hyperion_test gpu_backend)

target_link_libraries(hyperion_test
    PRIVATE
        gpu_backend
        hyperion_core
        hyperion_parse
)
