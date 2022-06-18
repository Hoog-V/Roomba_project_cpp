cmake_minimum_required(VERSION 3.8)

set(This UART_tests)

set(Sources
        init_test.cpp
        ChangeBaud_test.cpp
        SendBytes_test.cpp
        ReadBytes_test.cpp
        )

# We need this directory, and users of our library will need it too


add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
        gtest_main
        UART_lib
        )
target_link_libraries(${This} PRIVATE boost_asio)

target_include_directories(${This} PUBLIC ${PROJECT_SOURCE_DIR}/tests/UART_tests)
add_test(
        NAME ${This}
        COMMAND ${This}
)

