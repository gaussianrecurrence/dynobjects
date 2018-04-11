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
 * File:   Standard.h
 * Author: Mario Salazar de Torres
 *
 * Created on 06/20/2017, 10:21
 */

#ifndef DYNOBJECTS_STANDARD_H
#define DYNOBJECTS_STANDARD_H

/// Internal libs includes
#include "Generic.h"

/// External libs 

// C++11 standard
#include <set>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <unordered_map>

/**
 * DynObjects library namespace
 */
namespace DynObjects
{
    // Helper class
    struct DictionaryComparator :
    public std::binary_function<ObjectPtr, ObjectPtr, bool>
    {
        bool operator()(const ObjectPtr& __x, const ObjectPtr& __y) const
        {
            try
            {
                return __x < __y;
            }
            catch(std::bad_cast &)
            {
                return false;
            } 
        }
    };

    // Set class
    template<typename _Key, typename _Compare = std::less<_Key>, 
             typename _Alloc = std::allocator<_Key>>
    using Set = GenericInstance<std::set<_Key, _Compare, _Alloc>>;

    // Map class
    template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>,
        typename _Alloc = std::allocator<std::pair<const _Key, _Tp>>>
    using Map = GenericInstance<std::map<_Key, _Tp, _Compare, _Alloc>>;

    // Unordered map class
    template<class _Key, class _Tp,
             class _Hash = std::hash<_Key>,
             class _Pred = std::equal_to<_Key>,
             class _Alloc = std::allocator<std::pair<const _Key, _Tp> > >
    using UnorderedMap = GenericInstance<std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>>;

    // Dictionary class
    typedef UnorderedMap<ObjectPtr, ObjectPtr> Dictionary;

    // List class
    template<typename _Tp, typename _Alloc = std::allocator<_Tp>>
    using List = GenericInstance<std::list<_Tp, _Alloc>>;

    // Vector class
    template<typename _Tp, typename _Alloc = std::allocator<_Tp>>
    using Vector = GenericInstance<std::vector<_Tp, _Alloc>>;

    // Basic string class
    template<typename _CharT, typename _Traits = std::char_traits<_CharT>,
             typename _Alloc = std::allocator<_CharT>>
    using BasicString = GenericInstance<std::basic_string<_CharT, _Traits, _Alloc>>;

    // ASCII stl string
    typedef BasicString<char> String;

    // Unicode stl string
    typedef BasicString<wchar_t> WString;
};

#endif /* DYNOBJECTS_STANDARD_H */

