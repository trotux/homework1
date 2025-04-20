set(test_name "quadratic-equation-tests")

add_executable(${test_name}
    ${CMAKE_SOURCE_DIR}/tests/main.cpp
)

target_link_libraries(${test_name}
    gtest_main
    otus::homework1
)

target_compile_definitions(${test_name} PRIVATE USE_DETAILED_LOG)

set_target_properties(
    ${test_name}
    PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

add_test(NAME ${test_name} COMMAND ${test_name})
