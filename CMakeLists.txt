cmake_minimum_required(VERSION 2.8.0)

set(CMAKE_CXX_STANDARD "14")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "-g")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "-O2")
endif()

project(bcm2837)
include(CMakeToolsHelpers OPTIONAL)

file(GLOB srcs "${CMAKE_SOURCE_DIR}/src/*.cpp")
include_directories("${CMAKE_SOURCE_DIR}/include")

add_library(bcm2837 ${srcs})
# target_link_libraries(bcm2837 )