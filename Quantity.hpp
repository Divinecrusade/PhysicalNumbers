#pragma once

#include "Dimension.hpp"

namespace PhysicalNumbers
{
    // Declaration

    template<typename IntList, class T = double>
    class Quantity
    {

    public:

        using type = typename IntList;

        explicit Quantity(T init_val);
        Quantity(Quantity<IntList, T> const& num);
        Quantity<IntList, T>& operator=(Quantity<IntList, T> const& num);

        Quantity<IntList, T>& operator=(Quantity<IntList, T>&&) = default;
        Quantity(Quantity<IntList, T>&&) = default;

        ~Quantity() = default;

        T const& get_value() const;
        T      & get_value();

        Quantity<IntList, T>& operator-=(Quantity<IntList, T> const& rhs);
        Quantity<IntList, T>& operator+=(Quantity<IntList, T> const& rhs);
        Quantity<IntList, T>& operator*=(Quantity<IntList, T> const& rhs);
        Quantity<IntList, T>& operator/=(Quantity<IntList, T> const& rhs);

    private:

        T val{ };
    };

    template<typename IntList, class T>
    bool operator<(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs);

    template<typename IntList, class T>
    bool operator>(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs);

    template<typename IntList, class T>
    bool operator==(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs);

    template<typename IntList, class T>
    bool operator!=(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs);

    template<typename IntList, class T>
    bool operator<=(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs);

    template<typename IntList, class T>
    bool operator>=(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs);


    template<typename IntList, class T>
    Quantity<IntList, T> operator-(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs);

    template<typename IntList, class T>
    Quantity<IntList, T> operator+(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs);

    template<typename IntList1, typename IntList2, class T>
    Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Plus>, T> operator*(Quantity<IntList1, T> const& lhs, Quantity<IntList2, T> const& rhs);

    template<typename IntList1, typename IntList2, class T>
    Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Minus>, T> operator/(Quantity<IntList1, T> const& lhs, Quantity<IntList2, T> const& rhs);

    template<typename IntList, class T>
    Quantity<IntList, T> operator*(double lhs, Quantity<IntList, T> const& rhs);

    template<typename IntList, class T>
    Quantity<MetaProgramming::Zip<MetaProgramming::Generate<MetaProgramming::Length<IntList>::value>, IntList, MetaProgramming::Minus>, T>
    operator/(double lhs, Quantity<IntList, T> const& rhs);


    // Implementation

    template<typename IntList, class T>
    Quantity<IntList, T>::Quantity(T init_val) : val(init_val) { }

    template<typename IntList, class T>
    Quantity<IntList, T>::Quantity(Quantity<IntList, T> const& num) : val(num.val) { }

    template<typename IntList, class T>
    Quantity<IntList, T>& Quantity<IntList, T>::operator=(Quantity<IntList, T> const& num)
    {
        val = num.val;

        return *this;
    }

    template<typename IntList, class T>
    T const& Quantity<IntList, T>::get_value() const
    {
        return val;
    }

    template<typename IntList, class T>
    T& Quantity<IntList, T>::get_value()
    {
        return const_cast<double&>(const_cast<Quantity const*>(this)->get_value());
    }

    template<typename IntList, class T>
    Quantity<IntList, T>& Quantity<IntList, T>::operator-=(Quantity<IntList, T> const& rhs)
    {
        val -= rhs.val;

        return *this;
    }

    template<typename IntList, class T>
    Quantity<IntList, T>& Quantity<IntList, T>::operator+=(Quantity<IntList, T> const& rhs)
    {
        val += rhs.val;

        return *this;
    }

    template<typename IntList, class T>
    Quantity<IntList, T>& Quantity<IntList, T>::operator*=(Quantity<IntList, T> const& rhs)
    {
        val *= rhs.val;

        return *this;
    }

    template<typename IntList, class T>
    Quantity<IntList, T>& Quantity<IntList, T>::operator/=(Quantity<IntList, T> const& rhs)
    {
        val /= rhs.val;

        return *this;
    }

    template<typename IntList, class T>
    bool operator<(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs)
    {
        return lhs.get_value() < rhs.get_value();
    }

    template<typename IntList, class T>
    bool operator>(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs)
    {
        return lhs.get_value() > rhs.get_value();
    }

    template<typename IntList, class T>
    bool operator==(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs)
    {
        return lhs.get_value() == rhs.get_value();
    }

    template<typename IntList, class T>
    bool operator!=(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs)
    {
        return lhs.get_value() != rhs.get_value();
    }

    template<typename IntList>
    bool operator<=(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
    {
        return lhs.get_value() <= rhs.get_value();
    }

    template<typename IntList, class T>
    bool operator>=(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs)
    {
        return lhs.get_value() >= rhs.get_value();
    }

    template<typename IntList, class T>
    Quantity<IntList, T> operator-(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs)
    {
        return Quantity<IntList, T>(lhs) -= rhs;
    }

    template<typename IntList, class T>
    Quantity<IntList, T> operator+(Quantity<IntList, T> const& lhs, Quantity<IntList, T> const& rhs)
    {
        return Quantity<IntList, T>(lhs) += rhs;
    }

    template<typename IntList1, typename IntList2, class T>
    Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Plus>, T> operator*(Quantity<IntList1, T> const& lhs, Quantity<IntList2, T> const& rhs)
    {
        return Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Plus>, T>(lhs.get_value() * rhs.get_value());
    }

    template<typename IntList1, typename IntList2, class T>
    Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Minus>, T> operator/(Quantity<IntList1, T> const& lhs, Quantity<IntList2, T> const& rhs)
    {
        return Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Minus>>(lhs.get_value() / rhs.get_value());
    }

    template<typename IntList, class T>
    Quantity<IntList, T> operator*(double lhs, Quantity<IntList, T> const& rhs)
    {
        return Quantity<IntList, T>(lhs * rhs.get_value());
    }

    template<typename IntList, class T>
    Quantity<MetaProgramming::Zip<MetaProgramming::Generate<MetaProgramming::Length<IntList>::value>, IntList, MetaProgramming::Minus>, T> operator/(double lhs, Quantity<IntList, T> const& rhs)
    {
        return Quantity<MetaProgramming::Zip<MetaProgramming::Generate<MetaProgramming::Length<IntList>::value>, IntList, MetaProgramming::Minus>, T>(lhs / rhs.get_value());
    }
}