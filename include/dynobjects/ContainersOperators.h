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
 * File:   ContainersOperators.h
 * Author: Mario Salazar de Torres
 *
 * Created on 07/13/2017, 13:36
 */

#ifndef DYNOBJECTS_CONTAINERS_OPERATORS_H
#define DYNOBJECTS_CONTAINERS_OPERATORS_H

/// Internal libs includes
#include "Operators.h"

/// External libs includes

//C++11 standard
#include <vector>

/**
 * DynObjects library namespace
 */
namespace DynObjects
{
    /**
     * Operators namespace
     */
    namespace Operators
    {
        /// Comparators types (specialization for STL vectors)

        // Equalty comparator
        template<typename _Tp>
        class Equals<std::vector<_Tp>> : public Impl::Equals<
            std::vector<_Tp>, Checks::Equals<_Tp>::value> {};

        // Non-equalty comparator
        template<typename _Tp>
        class NotEquals<std::vector<_Tp>> : public Impl::NotEquals<
                std::vector<_Tp>, Checks::NotEquals<_Tp>::value> {};

        // Less comparator
        template<typename _Tp>
        class Less<std::vector<_Tp>> : public Impl::Less<
            std::vector<_Tp>, Checks::Less<_Tp>::value> {};

        // Greater comparator
        template<typename _Tp>
        class Greater<std::vector<_Tp>> : public Impl::Greater<
                std::vector<_Tp>, Checks::Greater<_Tp>::value> {};

        // Less or equals comparator
        template<typename _Tp>
        class LessEquals<std::vector<_Tp>> : public Impl::LessEquals<
                std::vector<_Tp>, Checks::LessEquals<_Tp>::value> {};

        // Greater or equals comparator
        template<typename _Tp>
        class GreaterEquals<std::vector<_Tp>> : public Impl::GreaterEquals<
                    std::vector<_Tp>, Checks::GreaterEquals<_Tp>::value> {};
    }
}

#endif /* DYNOBJECTS_CONTAINERS_OPERATORS_H */

