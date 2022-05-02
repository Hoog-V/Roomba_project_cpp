cmake_minimum_required(VERSION 3.8)

set(This UART_tests)

set(Sources
        init_test.cpp
        ChangeBaud_test.cpp
        SendBytes_test.cpp
        ReadBytes_test.cpp
        )

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
        gtest_main
        UART_lib
        )
target_link_libraries(${This} PRIVATE boost_asio)

add_test(
        NAME ${This}
        COMMAND ${This}
)