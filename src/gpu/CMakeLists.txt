# gpu target library (HIP or CUDA)
if(USE_GPU STREQUAL "HIP")
  # compiles .hip with HIP
  add_library(burner_gpu STATIC hip_wrapper.cpp bn_burner_gpu.hip)
  target_compile_definitions(burner_gpu PUBLIC SIZE=${SIZE})
  target_include_directories(burner_gpu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
  target_link_libraries(burner_gpu PUBLIC core)
  # pass HIP-specific compile options if needed
elseif(USE_GPU STREQUAL "CUDA")
  add_library(burner_gpu STATIC hip_wrapper.cpp bn_burner_gpu.hip)
  target_compile_definitions(burner_gpu PUBLIC SIZE=${SIZE})
  target_include_directories(burner_gpu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
  target_link_libraries(burner_gpu PUBLIC core)
else()
  add_library(burner_gpu INTERFACE) # no GPU
  target_link_libraries(burner_gpu INTERFACE burner_cpu)
endif()

