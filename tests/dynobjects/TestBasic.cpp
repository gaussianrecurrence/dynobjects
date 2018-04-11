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
 * File:   TestBasic.cpp
 * Author: Mario Salazar de Torres
 *
 * Created on 06/20/2017, 16:09:02
 */

/// Internal libs includes

#include "TestBasic.h"

using namespace DynObjects;

CPPUNIT_TEST_SUITE_REGISTRATION(TestBasic);

TestBasic::TestBasic()
{
}

TestBasic::~TestBasic()
{
}

void TestBasic::setUp()
{
}

void TestBasic::tearDown()
{
}

void TestBasic::testDereferenceMethod()
{

    StringMap pContext = StringMap();
    (*pContext)["INTERVAL"] = Integer(-2);
    CPPUNIT_ASSERT((*pContext)["INTERVAL"] == Integer(-2));
}

void TestBasic::testEncapsulatedComparatorMethod()
{
    Integer integer = -6;
    CPPUNIT_ASSERT(integer == Integer(-6));
}

void TestBasic::testComparatorMethod()
{
    Integer integer = -6;
    CPPUNIT_ASSERT(integer == -6);
}