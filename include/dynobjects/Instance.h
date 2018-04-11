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
 * File:   Instance.h
 * Author: Mario Salazar de Torres
 *
 * Created on 06/20/2017, 12:59
 */

#ifndef DYNOBJECTS_INSTANCE_H
#define DYNOBJECTS_INSTANCE_H

/// Internal libs includes
#include "Object.h"


/**
 * DynObjects library namespace
 */
namespace DynObjects
{
    /**
     * Object instance class
     */
    template<typename _Tp, typename _Type>
    class Instance : public ObjectPtr
    {
    public:
        ///Class constructors

        /**
         * Class constructor with shared pointer
         * @param ptr Shared pointer
         * @note Used both as casting operator and also as copy-constructor
         */
        inline Instance(const ObjectPtr &ptr) : ObjectPtr(ptr)
        {
        }

        /**
         * Generic class constructor
         * @param args List of encapsulated object constructor arguments
         */
        template<typename... Args>
        inline Instance(Args... args) :
        ObjectPtr(std::make_shared<_Type>(args...))
        {
        }

        /**
         * Class destructor
         */
        virtual ~Instance()
        {
        }

        /// Class operators
        /**
         * Comparison operator with another generic instance
         * @param o Another generic instance
         * @return Result of the comparison
         */
        inline bool operator==(const Instance &o) const
        {
            return this->operator *() == o.operator*();
        }

        /**
         * Comparison operator with the raw object
         * @param o Raw object
         * @return Result of the comparison
         */
        inline bool operator==(const _Tp &o) const
        {
            return this->operator *() == o;
        }


        /// Class implementations

        /**
         * De-reference operator
         * @return A reference to the encapsulated object
         */
        inline _Tp &operator*()
        {
            return static_cast<_Tp &>(
            **std::dynamic_pointer_cast<_Type>(
            static_cast<std::shared_ptr<Object>>(*this)).get());
        }

        /**
         * De-reference operator
         * @return A const reference to the encapsulated object
         */
        inline  const _Tp &operator*() const
        {
            return const_cast<_Tp &>(
            **std::dynamic_pointer_cast<_Type>(
            static_cast<std::shared_ptr<Object>>(*this)).get());
        }
    };
}

/**
 * Compares two instances of the same type
 * @param a Instance A
 * @param b Instance B
 * @return Result of the comparison
 */
template<typename _Tp, typename _Type>
inline bool
operator==(const DynObjects::Instance<_Tp, _Type>& a,
           const DynObjects::Instance<_Tp, _Type>& b) noexcept
{
    return a.operator==(b);
}

/**
 * Stream operator for instances
 * @param os Output stream
 * @param item Item to write to the stream
 * @return Modified stream
 */
template<typename _Tp, typename _Type>
std::ostream & operator <<( std::ostream &os, 
const DynObjects::Instance<_Tp, _Type> &item)
{
   return os << *item;
}

#endif /* DYNOBJECTS_INSTANCE_H */

