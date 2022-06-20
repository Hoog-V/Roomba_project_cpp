# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
#file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}}/include/Roomba/*.hpp")
set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/Roomba/Roomba.hpp")
file(GLOB source_list CONFIGURE_DEPENDS "%{PROJECT_SOURCE_DIR}/src/Roomba/*.cpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(Roomba_lib ${source_list} ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(Roomba_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# This depends on (header only) boost
target_link_libraries(Roomba_lib PRIVATE boost_chrono)
target_link_libraries(Roomba_lib PRIVATE boost_asio)
target_link_libraries(Roomba_lib PRIVATE UART_lib)
target_link_libraries(Roomba_lib PRIVATE IO_lib)

# All users of this library will need at least C++11
target_compile_features(Roomba_lib PUBLIC cxx_std_20)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
