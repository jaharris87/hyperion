add_executable(test_burner test_burner.cpp)
target_link_libraries(test_burner PRIVATE burner_gpu core)
add_test(NAME test_burner COMMAND test_burner)

