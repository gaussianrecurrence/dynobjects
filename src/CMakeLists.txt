# Dynobjects library impl cmake

cmake_minimum_required(VERSION 2.8)

# Find all sources and compile shared library
file(GLOB_RECURSE LIB_SRCS "*.cpp")

# Create static library
add_library(dynobjects STATIC ${LIB_SRCS})

