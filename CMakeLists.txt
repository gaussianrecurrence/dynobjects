cmake_minimum_required(VERSION 2.8)

IF(PROJECT_NAME)
    set(SUBPROJECT ON)
endif()

if(POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif()

project(dynobjects)

message("Compiling dynobjects...")

# Set includes dir
include_directories(include)

# Set project global configuration

# C++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++11")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g")
SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Add PkgConfig
find_package(PkgConfig)

# Include source
add_subdirectory (src)

# Include tests
add_subdirectory (tests)