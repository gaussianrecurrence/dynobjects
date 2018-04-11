# Tests

# Enable tests
enable_testing()

# Libraries versions
set (CPPUNIT_REQUIRED 1.13.0)

# Check for CppUnit library
pkg_check_modules(CPPUNIT REQUIRED cppunit>=${CPPUNIT_REQUIRED})

# Use CppUnit
include_directories(${CPPUNIT_INCLUDE_DIR})

# Scan tests
add_subdirectory(dynobjects)

IF(SUBPROJECT)
    # Add make 'dynobjects/test' target
    add_custom_target(test_dynobjects COMMAND ${CMAKE_CTEST_COMMAND}
    DEPENDS test_objects)
else()
    # 'test' target policy workaround
    if(POLICY CMP0037)
        cmake_policy(SET CMP0037 OLD)
    endif()

    # Add make 'test' target
    add_custom_target(test COMMAND ${CMAKE_CTEST_COMMAND}
    DEPENDS test_objects)
endif()