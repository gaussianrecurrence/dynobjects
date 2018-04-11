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

#ifndef DYNOBJECTS_BASIC_H
#define DYNOBJECTS_BASIC_H

/// Internal libs includes
#include "Utils.h"
#include "Generic.h"
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
     * Basic object class
     */
    template<typename T>
    class Basic : public virtual Object
    {
    public:
        /// Class constructors

        /**
         * Class default constructor
         */
        Basic()
        {
        }

        /**
         * Class constructor
         * @param o
         */
        Basic(const T &o) : m_Data(o)
        {
        }

        /**
         * Class destructor
         */
        virtual ~Basic()
        {
        }

        /// Class operators

        /**
         * De-reference operator
         * @return A reference to the contained item
         */
        T &operator*()
        {
            return this->m_Data;
        }

        /**
         * De-reference operator
         * @return A const reference to the contained item
         */
        const T &operator*() const
        {
            return this->m_Data;
        }

        /**
         * Assignation operator
         * @param o Item to be assigned
         * @return A reference to itself
         */
        Basic &operator=(const T &o)
        {
            this->m_Data = o;
            return *this;
        }

        /**
         * Non equalty comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator!=(const Object &o) const
        {
            return this->m_Data != dynamic_cast<const Basic &>(o).m_Data;
        }

        /**
         * Equalty comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator==(const Object &o) const
        {
            return this->m_Data == dynamic_cast<const Basic &>(o).m_Data;
        }

        /**
         * Less than comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator<(const Object &o) const
        {
            return this->m_Data < dynamic_cast<const Basic &>(o).m_Data;
        }

        /**
         * Greater than comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator>(const Object &o) const
        {
            return this->m_Data > dynamic_cast<const Basic &>(o).m_Data;
        }

        /**
         * Less or equal than comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator<=(const Object &o) const
        {
            return this->m_Data <= dynamic_cast<const Basic &>(o).m_Data;
        }

        /**
         * Greater or equal than comparison operator
         * @param o Object to compare
         * @return Result of the comparison
         */
        virtual bool operator>=(const Object &o) const
        {
            return this->m_Data >= dynamic_cast<const Basic &>(o).m_Data;
        }


        /// Class implementations

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
            return Operators::Hash<T>()(this->m_Data);
        }

    protected:

        /// Class attributes

        /**
         * Class encapsulated item
         */
        T m_Data;
    };

    /**
     * Basic instances alias
     */
    template<typename T>
    using BasicInstance = Instance<T, Basic<T>>;
}

#endif /* DYNOBJECTS_BASIC_H */

