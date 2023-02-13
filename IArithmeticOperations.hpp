#pragma once

namespace PhysicalNumbers
{
    template<class T>
    __interface IArithmeticOperations
    {
        static T operator-(T const& lhs, T const& rhs) = 0;
        static T operator+(T const& lhs, T const& rhs) = 0;
        
        static T operator*(T const& lhs, T const& rhs) = 0;
        static T operator/(T const& lhs, T const& rhs) = 0;

        T& operator -=(T const& rhs) = 0;
        T& operator +=(T const& rhs) = 0;

        T& operator *=(T const& rhs) = 0;
        T& operator /=(T const& rhs) = 0;
    };
}