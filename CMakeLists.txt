cmake_minimum_required(VERSION 3.10)
project(HelloSystemC CXX)
set(CMAKE_CXX_STANDARD 17)

# Check if SYSTEMC_HOME is set
if(DEFINED SYSTEMC_HOME OR DEFINED ENV{SYSTEMC_HOME})
    if (DEFINED $ENV{SYSTEMC_HOME})
        set(SYSTEMC_HOME $ENV{SYSTEMC_HOME})
    endif()
else()
    message(FATAL_ERROR "SYSTEMC_HOME is not set. Please set the SYSTEMC_HOME variable.")
endif()

# Include the SystemC headers
include_directories(${SYSTEMC_HOME}/include)

# Link the SystemC library
link_directories(${SYSTEMC_HOME}/lib)

# Add GoogleTest using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Enable testing and add the test executable
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


# Download ac_types from GitHub
include(FetchContent)
FetchContent_Declare(
    ac_types
    GIT_REPOSITORY https://github.com/hlslibs/ac_types.git
)
FetchContent_MakeAvailable(ac_types)

# Add the ac_types library
add_library(ac_types INTERFACE)

target_include_directories(ac_types INTERFACE ${ac_types_SOURCE_DIR}/include)

# Add the executable
add_executable(hello_systemc main.cpp)

# Link the SystemC library to the executable
target_link_libraries(hello_systemc systemc gtest ac_types)