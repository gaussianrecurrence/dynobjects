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
 * File:   Object.h
 * Author: Mario Salazar de Torres
 *
 * Created on 06/08/2017, 12:05
 */

#ifndef DYNOBJECTS_OBJECT_H
#define DYNOBJECTS_OBJECT_H

/// External libs includes

// C++11 standard
#include <memory>
#include <sstream>


/**
 * DynObjects library namespace
 */
namespace DynObjects
{

    /**
     * Object interface
     */
    class Object : public std::enable_shared_from_this<Object>
    {
    public:
        /**
         * Interface destructor
         */
        virtual ~Object() = default;


        /// Interface operators

        /**
         * Non equalty comparison operator
         * @param o Object to compare with
         * @return Result of the comparison
         */
        virtual bool operator!=(const Object &o) const = 0;

        /**
         * Equalty comparison operator
         * @param o Object to compare with
         * @return Result of the comparison
         */
        virtual bool operator==(const Object &o) const = 0;

        /**
         * Less than comparison operator
         * @param o Object to compare with
         * @return Result of the comparison
         */
        virtual bool operator<(const Object &o) const = 0;

        /**
         * Greater than comparison operator
         * @param o Object to compare with
         * @return Result of the comparison
         */
        virtual bool operator>(const Object &o) const = 0;

        /**
         * Less or equal than comparison operator
         * @param o Object to compare with
         * @return Result of the comparison
         */
        virtual bool operator<=(const Object &o) const = 0;

        /**
         * Greater or equal than comparison operator
         * @param o Object to compare with
         * @return Result of the comparison
         */
        virtual bool operator>=(const Object &o) const = 0;


        /// Interface methods

        /**
         * Returns object type
         * @return Object type
         */
        virtual std::string GetObjectType() const = 0;

        /**
         * Returns an string representation of the object
         * @return 
         */
        virtual std::string str() const
        {
            std::stringstream ss;
            ss << "[" << this->GetObjectType() << "]" << "(" << this << ")";

            return ss.str();
        }

        /**
         * Object hashing method
         * @return Hash of the object
         */
        virtual size_t hash() const = 0;
    };

    /**
     * Object pointer
     */
    class ObjectPtr
    {
    public:
        /// Class constructors

        /**
         * Default class constructor
         */
        ObjectPtr() = default;

        /**
         * Copy class constructor
         * @param ptr Shared pointer
         */
        template<typename T>
        inline ObjectPtr(const std::shared_ptr<T> &ptr) : m_Pointer(ptr)
        {
        }

        /**
         * Class destructor
         */
        virtual ~ObjectPtr() = default;

        /**
         * Casting operator to shared pointer
         * @return Shared pointer
         */
        inline operator std::shared_ptr<Object>() const
        {
            return this->m_Pointer;
        }

        /**
         * De-reference operator
         * @return Reference to the object
         */
        inline Object &operator*()
        {
            return *this->m_Pointer.get();
        }

        /**
         * De-reference operator
         * @return A const reference to the object
         */
        inline const Object &operator*() const
        {
            return *this->m_Pointer.get();
        }

        /**
         * Non equalty comparison operator
         * @param o Object pointer to compare with
         * @return Result of the comparison
         */
        inline bool operator!=(const ObjectPtr &o) const
        {
            return this->operator*() != o.operator*();
        }

        /**
         * Equalty comparison operator
         * @param o Object pointer to compare with
         * @return Result of the comparison
         */
        inline bool operator==(const ObjectPtr &o) const
        {
            return this->operator*() == o.operator*();
        }

        /**
         * Less than comparison operator
         * @param o Object pointer to compare with
         * @return Result of the comparison
         */
        inline bool operator<(const ObjectPtr &o) const
        {
            return this->operator*() < o.operator*();
        }

        /**
         * Greater than comparison operator
         * @param o Object pointer to compare with
         * @return Result of the comparison
         */
        inline bool operator>(const ObjectPtr &o) const
        {
            return this->operator*() > o.operator*();
        }

        /**
         * Less or equal than comparison operator
         * @param o Object pointer to compare with
         * @return Result of the comparison
         */
        inline bool operator<=(const ObjectPtr &o) const
        {
            return this->operator*() <= o.operator*();
        }

        /**
         * Greater or equal than comparison operator
         * @param o Object pointer to compare with
         * @return Result of the comparison
         */
        inline bool operator>=(const ObjectPtr &o) const
        {
            this->operator*() >= o.operator*();
        }

        /**
         * Bool operator
         * @return Whether or not pointer is initialized
         */
        inline operator bool() const
        {
            return this->m_Pointer.operator bool();
        }

        /**
         * 
         * @return 
         */
        std::string GetObjectType() const
        {
            return "Ptr<" + this->operator*().GetObjectType() + ">";
        }

    protected:
        /// Class attributes

        /**
         * Shared pointer
         */
        std::shared_ptr<Object> m_Pointer;
    };
};


/**
 * Stream operator for instances
 * @param os Output stream
 * @param item Item to write to the stream
 * @return Modified stream
 */
std::ostream & operator<<(std::ostream &os,
        const DynObjects::ObjectPtr &item);


// Hash implementation
namespace std
{

    template<>
    struct hash<DynObjects::ObjectPtr>
    : public __hash_base<size_t, DynObjects::ObjectPtr>
    {

        size_t operator()(const DynObjects::ObjectPtr& __s) const noexcept
        {
            return (*__s).hash();
        }
    };
}

#endif /* DYNOBJECTS_OBJECT_H */

