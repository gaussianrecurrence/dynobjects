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
 * File:   Operators.h
 * Author: Mario Salazar de Torres
 *
 * Created on 06/22/2017, 17:35
 */

#ifndef DYNOBJECTS_OPERATORS_H
#define DYNOBJECTS_OPERATORS_H

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
        /**
         * Operator checks namespace
         */
        namespace Checks
        {
            // Equalty operator check
            template<class T, class = decltype(std::declval<T>() == std::declval<T>() )> 
            std::true_type  EqualsTest(const T&);
            std::false_type EqualsTest(...);

            template<class T> using Equals = decltype(EqualsTest(std::declval<T>()));


            // Non-equalty operator check
            template<class T, class = decltype(std::declval<T>() != std::declval<T>() )> 
            std::true_type  NotEqualsTest(const T&);
            std::false_type NotEqualsTest(...);

            template<class T> using NotEquals = decltype(NotEqualsTest(std::declval<T>()));


            // Less than operator check
            template<class T, class = decltype(std::declval<T>() < std::declval<T>() )> 
            std::true_type  LessThanTest(const T&);
            std::false_type LessThanTest(...);

            template<class T> using Less = decltype(LessThanTest(std::declval<T>()));


            // Greater than operator check
            template<class T, class = decltype(std::declval<T>() < std::declval<T>() )> 
            std::true_type  GreaterThanTest(const T&);
            std::false_type GreaterThanTest(...);

            template<class T> using Greater = decltype(GreaterThanTest(std::declval<T>()));


            // Less or equal than operator check
            template<class T, class = decltype(std::declval<T>() <= std::declval<T>() )> 
            std::true_type  LessEqualsTest(const T&);
            std::false_type LessEqualsTest(...);

            template<class T> using LessEquals = decltype(LessEqualsTest(std::declval<T>()));


            // Greather or equal than operator check
            template<class T, class = decltype(std::declval<T>() >= std::declval<T>() )> 
            std::true_type  GreaterEqualsTest(const T&);
            std::false_type GreaterEqualsTest(...);

            template<class T> using GreaterEquals = decltype(GreaterEqualsTest(std::declval<T>()));
        }

        /**
         * Operators implementations
         */
        namespace Impl
        {
            /**
             * Implementation for comparator operator that throws an bad 
             * function call in case the class has not the comparator implemented
             */
            template<typename _Tp>
            class InvalidComparator
            {
            public:
                static inline bool Compare(const _Tp& a, const _Tp& b)
                {
                    std::__throw_bad_function_call();
                }
            };

            /**
             * Valid implementation for less than operator
             */
            template<typename _Tp, bool _Valid = true>
            class Equals
            {
            public:
                static inline bool Compare(const _Tp& a, const _Tp& b)
                {
                    return a == b;
                }
            };

            /**
             * Invalid implementation for less than operator
             */
            template<typename _Tp>
            class Equals<_Tp, false> : public InvalidComparator<_Tp>
            {
            };

            /**
             * Valid implementation for less than operator
             */
            template<typename _Tp, bool _Valid = true>
            class NotEquals
            {
            public:
                static inline bool Compare(const _Tp& a, const _Tp& b)
                {
                    return a != b;
                }
            };

            /**
             * Invalid implementation for less than operator
             */
            template<typename _Tp>
            class NotEquals<_Tp, false> : public InvalidComparator<_Tp>
            {
            };

            /**
             * Valid implementation for less than operator
             */
            template<typename _Tp, bool _Valid = true>
            class Less
            {
            public:
                static inline bool Compare(const _Tp& a, const _Tp& b)
                {
                    return a < b;
                }
            };

            /**
             * Invalid implementation for less than operator
             */
            template<typename _Tp>
            class Less<_Tp, false> : public InvalidComparator<_Tp>
            {
            };

            /**
             * Valid implementation for greater than operator
             */
            template<typename _Tp, bool _Valid = true>
            class Greater
            {
            public:
                static inline bool Compare(const _Tp& a, const _Tp& b)
                {
                    return a > b;
                }
            };

            /**
             * Invalid implementation for greater than operator
             */
            template<typename _Tp>
            class Greater<_Tp, false> : public InvalidComparator<_Tp>
            {
            };

            /**
             * Valid implementation for greater than operator
             */
            template<typename _Tp, bool _Valid = true>
            class LessEquals
            {
            public:
                static inline bool Compare(const _Tp& a, const _Tp& b)
                {
                    return a <= b;
                }
            };

            /**
             * Invalid implementation for greater than operator
             */
            template<typename _Tp>
            class LessEquals<_Tp, false> : public InvalidComparator<_Tp>
            {
            };

            /**
             * Valid implementation for greater than operator
             */
            template<typename _Tp, bool _Valid = true>
            class GreaterEquals
            {
            public:
                static inline bool Compare(const _Tp& a, const _Tp& b)
                {
                    return a >= b;
                }
            };

            /**
             * Invalid implementation for greater than operator
             */
            template<typename _Tp>
            class GreaterEquals<_Tp, false> : public InvalidComparator<_Tp>
            {
            };


            /**
             * Invalid hashing function
             */
            template<typename _Tp>
            class InvalidHash
            : public std::__hash_base<size_t, _Tp>
            {
            public:
                size_t operator()(const _Tp& __s) const noexcept
                { 
                    std::__throw_bad_function_call();
                }
            };
        }

        /// Comparators types

        // Equalty comparator
        template<typename _Tp>
        class Equals : public Impl::Equals<_Tp, 
                Checks::Equals<_Tp>::value> {};

        // Non-equalty comparator
        template<typename _Tp>
        class NotEquals : public Impl::NotEquals<_Tp, 
                    Checks::NotEquals<_Tp>::value> {};

        // Less comparator
        template<typename _Tp>
        class Less : public Impl::Less<_Tp,
                Checks::Less<_Tp>::value> {};

        // Greater comparator
        template<typename _Tp>
        class Greater : public Impl::Greater<_Tp, 
                    Checks::Greater<_Tp>::value> {};

        // Less or equals comparator
        template<typename _Tp>
        class LessEquals : public Impl::LessEquals<_Tp, 
                    Checks::LessEquals<_Tp>::value> {};

        // Greater or equals comparator
        template<typename _Tp>
        class GreaterEquals : public Impl::GreaterEquals<_Tp, 
                        Checks::GreaterEquals<_Tp>::value> {};


        /// Misc functions

        // Hash operator
        template<typename _Tp>
        using Hash = typename std::conditional<std::is_constructible<
        std::hash<_Tp>>::value, std::hash<_Tp>, Impl::InvalidHash<_Tp>>::type;
    }
}

#endif /* DYNOBJECTS_OPERATORS_H */

