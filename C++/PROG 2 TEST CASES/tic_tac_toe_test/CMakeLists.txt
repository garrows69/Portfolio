add_executable(tic_tac_toe_tests "tic_tac_toe_test.cpp")
target_link_libraries(tic_tac_toe_tests tic_tac_toe_library)
add_test(NAME tic_tac_toe_tests COMMAND tic_tac_toe_tests -s)