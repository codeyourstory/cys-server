CMAKE_MINIMUM_REQUIRED( VERSION 2.8.5 )

SET(CMAKE_SYSTEM_NAME "Linux")

# Project Declaration

project(cys-engine)

# enable c++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(-m64 -Wall -Wno-unused-function)

# Get source files

file(
  GLOB_RECURSE source_files 
  # ngengine
  ../../src/*
)

include_directories(
  ../../include/
)

add_library(cysengine ${source_files})

add_custom_command(TARGET cysengine POST_BUILD 
  COMMAND ${CMAKE_COMMAND} -E copy libcysengine.a ../../bin/libcysengine.a
)

