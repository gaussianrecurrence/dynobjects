/*
 * Copyright (C) 2017 Mario Salazar de Torres
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * File:   TestBasic.h
 * Author: Mario Salazar de Torres
 *
 * Created on 19-jun-2017, 16:09:01
 */

#ifndef TESTBASIC_H
#define TESTBASIC_H

/// Internal libs includes
#include "dynobjects/Standard.h"
#include "dynobjects/BasicTypes.h"

/// External libs includes

// CppUnit
#include <cppunit/extensions/HelperMacros.h>

class TestBasic : public CPPUNIT_NS::TestFixture
{
private:
    
    /// Types definitions
    typedef DynObjects::Map<std::string, DynObjects::ObjectPtr> StringMap;

    /// Test registration

    CPPUNIT_TEST_SUITE(TestBasic);

    CPPUNIT_TEST(testComparatorMethod);
    CPPUNIT_TEST(testDereferenceMethod);
    CPPUNIT_TEST(testEncapsulatedComparatorMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    TestBasic();
    virtual ~TestBasic();
    void setUp();
    void tearDown();

private:
    void testComparatorMethod();
    void testDereferenceMethod();
    void testEncapsulatedComparatorMethod();
};

#endif /* TESTGENERIC_H */

