# Dynobjects tests

cmake_minimum_required(VERSION 2.8)

set (TEST_NAME test_objects)

# Add tests directory
add_definitions(-DTEST_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR})

#Find all source files in unit test
file(GLOB TEST_RUNNER "TestRunner.cpp")
file(GLOB UNIT_TESTS "*.cpp")

list(REMOVE_ITEM UNIT_TESTS ${TEST_RUNNER})

# Generate test executable
add_executable(${TEST_NAME} ${TEST_RUNNER} ${UNIT_TESTS})
target_link_libraries (${TEST_NAME} dynobjects ${CPPUNIT_LIBRARIES})

# Add tests for CMake
message(STATUS "Adding 'external' tests...")

# Adding all tests
foreach(test ${UNIT_TESTS})
    get_filename_component(TestName ${test} NAME_WE)
    add_test(${TestName} ${TEST_NAME} ${TestName})
    message(STATUS "| Adding test external/" ${TestName})
endforeach(test)
