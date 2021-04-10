cmake_minimum_required(VERSION 3.14)

project(hello-1c)

option(ASAN "Sanitize with Address Sanitizer" ON)

include(cmake/CompileOptions.cmake)
include(cmake/Development.cmake)
include(cmake/Sanitize.cmake)

add_subdirectory(src)
