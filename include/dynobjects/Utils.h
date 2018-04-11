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
 * File:   Utils.h
 * Author: Mario Salazar de Torres
 *
 * Created on 06/22/2017, 11:30
 */

#ifndef DYNOBJECTS_UTILS_H
#define DYNOBJECTS_UTILS_H

/// External libs includes

// C++11 standard
#include <string>
#include <type_traits>

#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>
#endif

/**
 * DynObjects library namespace
 */
namespace DynObjects
{
    /**
     * Demangles an object name
     * @param name Object name to be demangled
     * @return Demangled object name
     */
    std::string DemangleObjectName(const char* name);
}

#endif /* DYNOBJECTS_UTILS_H */

