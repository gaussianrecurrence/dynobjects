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
 * File:   BasicTypes.h
 * Author: Mario Salazar de Torres
 *
 * Created on 06/19/2017, 11:52
 */

#ifndef DYNOBJECTS_BASICTYPES_H
#define DYNOBJECTS_BASICTYPES_H

/// Internal libs includes
#include "Basic.h"

/// External libs includes

// C++11 standard
#include <cstdint>
#include <ostream>



/**
 * DynObjects library namespace
 */
namespace DynObjects
{
    /// Standard basic types definitions

    // Signed types
    typedef BasicInstance<char> Char;
    typedef BasicInstance<short> Short;
    typedef BasicInstance<int> Integer;
    typedef BasicInstance<long> Long;

    typedef BasicInstance<int8_t> Int8;
    typedef BasicInstance<int16_t> Int16;
    typedef BasicInstance<int32_t> Int32;
    typedef BasicInstance<int64_t> Int64;

    // Unsigned types
    typedef BasicInstance<unsigned char> UChar;
    typedef BasicInstance<unsigned short> UShort;
    typedef BasicInstance<unsigned int> UInteger;
    typedef BasicInstance<unsigned long> ULong;

    typedef BasicInstance<uint8_t> UInt8;
    typedef BasicInstance<uint16_t> UInt16;
    typedef BasicInstance<uint32_t> UInt32;
    typedef BasicInstance<uint64_t> UInt64;

    // Misc types
    typedef BasicInstance<bool> Boolean;

    // FPU types
    typedef BasicInstance<float> Float;
    typedef BasicInstance<double> Double;
}

#endif /* DYNOBJECTS_BASICTYPES_H */

