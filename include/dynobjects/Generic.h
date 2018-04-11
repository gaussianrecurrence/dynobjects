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
 * File:   Generic.h
 * Author: Mario Salazar de Torres
 *
 * Created on 06/19/2017, 10:48
 */

#ifndef SHARED_OBJECTS_GENERIC_H
#define SHARED_OBJECTS_GENERIC_H

/// Internal libs includes
#include "Utils.h"
#include "Object.h"
#include "Instance.h"
#include "Operators.h"

/// External libs includes

// C++11 standard
#include <ostream>

/**
 * DynObjects library namespace
 */
namespace DynObjects
{
    /**
     * Generic object class
     */
    template<typename T>
    class Generic : public T, public virtual Object
    {       
    public:
        /// Class constructors

        /**
         * Class constructor
         * @param args Variable arguments for encapsulated object
         */
        template<typename... Args>
        inline Generic(Args... args) : T(args...)
        {
        }

        /**
         * Class destructor
         */
        virtual ~Generic()
        {
        }


        /// Class operators

        /**
         * De-reference operator
         * @return A reference to the encapsulated object
         */
        inline T &operator*()
        {
          return dynamic_cast<T&>(*this);
        }

        /**
         * De-reference operator
         * @return A reference to the encapsulated object
         */
        inline const T &operator*() const
        {
          return dynamic_cast<const T&>(*this);
        }

        /**
         * Non equalty comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator!=(const Object &o) const
        {
            try
            {
                return Operators::NotEquals<T>::Compare(
                dynamic_cast<const T&>(*this), dynamic_cast<const T&>(o));
            }
            catch(std::bad_cast &)
            {
                return true;
            }
        }

        /**
         * Equalty comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator==(const Object &o) const
        {
            try
            {
                return Operators::Equals<T>::Compare(
                dynamic_cast<const T&>(*this), dynamic_cast<const T&>(o));
            }
            catch(std::bad_cast &)
            {
                return false;
            }
        }

        /**
         * Less than comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator<(const Object &o) const
        {
            return Operators::Less<T>::Compare(
            dynamic_cast<const T&>(*this), dynamic_cast<const T&>(o));
        }

        /**
         * Greater than comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator>(const Object &o) const
        {
            return Operators::Greater<T>::Compare(
            dynamic_cast<const T&>(*this), dynamic_cast<const T&>(o));
        }

        /**
         * Less or equal than comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator<=(const Object &o) const
        {
            return Operators::LessEquals<T>::Compare(
            dynamic_cast<const T&>(*this), dynamic_cast<const T&>(o));
        }

        /**
         * Greater or equal than comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator>=(const Object &o) const
        {
            return Operators::GreaterEquals<T>::Compare(
            dynamic_cast<const T&>(*this), dynamic_cast<const T&>(o));
        }


        /// Class implementation

        /**
         * Returns object type
         * @return Object type
         */
        virtual std::string GetObjectType() const
        {
          return DemangleObjectName(typeid(T).name());
        }

        /**
         * Hashing method
         * @return Hash of the object
         */
        virtual size_t hash() const
        {
            return Operators::Hash<T>()(this->operator*());
        }
    };

    template<typename T>
    using GenericInstance = Instance<T, Generic<T>>;
}
#endif /* DYNOBJECTS_GENERIC_H */

