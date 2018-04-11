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
 * File:   TestGeneric.cpp
 * Author: Mario Salazar de Torres
 *
 * Created on 06/19/2017, 16:09:02
 */

/// Internal libs includes

#include "TestGeneric.h"
#include "dynobjects/BasicTypes.h"

using namespace DynObjects;

CPPUNIT_TEST_SUITE_REGISTRATION(TestGeneric);

TestGeneric::TestGeneric()
{
}

TestGeneric::~TestGeneric()
{
}

void TestGeneric::setUp()
{
}

void TestGeneric::tearDown()
{
}

void TestGeneric::testDictionaryMethod()
{
    Dictionary pContext;

    (*pContext)[Integer(0)] = String("VALUE_INTEGER");
    (*pContext)[String("4")] = String("VALUE_STRING");

    CPPUNIT_ASSERT((*pContext)[String("4")] == String("VALUE_STRING") && 
                   (*pContext)[Integer(0)] == String("VALUE_INTEGER"));
}

void TestGeneric::testDereferenceMethod()
{
    StringMap pContext = StringMap();
    StringMap pKeyStore = StringMap();
    
    (*pKeyStore)["PRIVATE"] = String("PRIVATE");
    (*pKeyStore)["PUBLIC"] = String("PUBLIC");
    
    (*pContext)["KEY_STORE"] = pKeyStore;
    CPPUNIT_ASSERT(*String((*StringMap(
    (*pContext)["KEY_STORE"]))["PRIVATE"]) == "PRIVATE" );
}

void TestGeneric::testEncapsulatedComparatorMethod()
{
    StringMap pContext = StringMap();
    StringMap pKeyStore = StringMap();
    
    (*pKeyStore)["PRIVATE"] = String("PRIVATE");
    (*pKeyStore)["PUBLIC"] = String("PUBLIC");
    
    (*pContext)["KEY_STORE"] = pKeyStore;
    CPPUNIT_ASSERT(String((*StringMap(
    (*pContext)["KEY_STORE"]))["PRIVATE"]) == String("PRIVATE"));
}

void TestGeneric::testComparatorMethod()
{
    StringMap pContext = StringMap();
    StringMap pKeyStore = StringMap();
    
    (*pKeyStore)["PRIVATE"] = String("PRIVATE");
    (*pKeyStore)["PUBLIC"] = String("PUBLIC");
    
    (*pContext)["KEY_STORE"] = pKeyStore;
    CPPUNIT_ASSERT(String((*StringMap(
    (*pContext)["KEY_STORE"]))["PRIVATE"]) == std::string("PRIVATE"));
}