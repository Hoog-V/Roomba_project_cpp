add_executable(app app.cpp)
target_compile_features(app PRIVATE cxx_std_20)
target_link_libraries(app PRIVATE boost_chrono)
target_link_libraries(app PRIVATE boost_asio)
target_link_libraries(app PRIVATE UART_lib)
target_link_libraries(app PRIVATE Roomba_lib)

add_subdirectory(examples)