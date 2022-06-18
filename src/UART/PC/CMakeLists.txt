# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
#file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}}/include/UART/*.hpp")
set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/UART/UART.hpp" )
# Make an automatic library - will be static or dynamic based on user setting
add_library(UART_lib UART.cpp ${HEADER_LIST} "${PROJECT_SOURCE_DIR}/include/UART/PC/UARTPC.hpp")

# We need this directory, and users of our library will need it too
target_include_directories(UART_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Under linux/mac we need pthreads to be able to use boost
# Let check and include!
if (UNIX)
    find_package( Threads )
    if(Threads_FOUND)
        target_link_libraries( UART_lib PRIVATE ${CMAKE_THREAD_LIBS_INIT} )
    else()
        message(STATUS "pthreads not found.. May introduce compilation errors!")
    endif()
endif (UNIX)


# Library needs Boost if compiling under Posix platform (Windows, Linux, Mac)
target_link_libraries(UART_lib PRIVATE boost_asio)
# All users of this library will need at least C++11
target_compile_features(UART_lib PUBLIC cxx_std_20)


# IDEs should put the headers in a nice place
source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST})
