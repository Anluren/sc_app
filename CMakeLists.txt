cmake_minimum_required(VERSION 3.10)
project(HelloSystemC CXX)
set(CMAKE_CXX_STANDARD 17)

# Set the SystemC installation path
# set(SYSTEMC_HOME xxx)

# Include the SystemC headers
include_directories(${SYSTEMC_HOME}/include)

# Link the SystemC library
link_directories(${SYSTEMC_HOME}/lib)

# Add the executable
add_executable(hello_systemc main.cpp)

# Link the SystemC library to the executable
target_link_libraries(hello_systemc systemc)