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

/// Internal livs includes
#include "dynobjects/Utils.h"

std::string DynObjects::DemangleObjectName(const char* name)
{
#ifdef __GNUG__
    int status = 0;
    std::unique_ptr<char, void(*)(void*) > res{
        abi::__cxa_demangle(name, NULL, NULL, &status),
        std::free};

    return (status == 0) ? res.get() : name;
#else
    return name;
#endif
}