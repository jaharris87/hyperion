add_library(core STATIC init.c store.c kill.c)
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(core PUBLIC SIZE=${SIZE})

