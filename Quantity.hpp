#pragma once

#include "MetaProgramming.hpp"

namespace PhysicalNumbers
{
    // Declaration

    template<typename IntList>
    class Quantity
    {

    public:

        using type = typename IntList;

        explicit Quantity(double init_val = 0.);
        Quantity(Quantity const& num);
        Quantity<IntList>& operator=(Quantity<IntList> const& num);

        Quantity<IntList>& operator=(Quantity<IntList>&&) = default;
        Quantity(Quantity&&) = default;

        ~Quantity() = default;

        double const& get_value() const;
        double      & get_value();

        Quantity<IntList>& operator-=(Quantity<IntList> const& rhs);
        Quantity<IntList>& operator+=(Quantity<IntList> const& rhs);
        Quantity<IntList>& operator*=(Quantity<IntList> const& rhs);
        Quantity<IntList>& operator/=(Quantity<IntList> const& rhs);

    private:

        double val{ };
    };

    template<typename IntList>
    bool operator<(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs);

    template<typename IntList>
    bool operator>(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs);

    template<typename IntList>
    bool operator==(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs);

    template<typename IntList>
    bool operator!=(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs);

    template<typename IntList>
    bool operator<=(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs);

    template<typename IntList>
    bool operator>=(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs);


    template<typename IntList>
    Quantity<IntList> operator-(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs);

    template<typename IntList>
    Quantity<IntList> operator+(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs);

    template<typename IntList1, typename IntList2>
    Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Plus>> operator*(Quantity<IntList1> const& lhs, Quantity<IntList2> const& rhs);

    template<typename IntList1, typename IntList2>
    Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Minus>> operator/(Quantity<IntList1> const& lhs, Quantity<IntList2> const& rhs);

    template<typename IntList>
    Quantity<IntList> operator*(double lhs, Quantity<IntList> const& rhs);

    template<typename IntList>
    Quantity<MetaProgramming::Zip<MetaProgramming::Generate<MetaProgramming::Length<IntList>::value>, IntList, MetaProgramming::Minus>>
    operator/(double lhs, Quantity<IntList> const& rhs);


    // Implementation

    template<typename IntList>
    Quantity<IntList>::Quantity(double init_val) : val(init_val) { }

    template<typename IntList>
    Quantity<IntList>::Quantity(Quantity const& num) : val(num.val) { }

    template<typename IntList>
    Quantity<IntList>& Quantity<IntList>::operator=(Quantity<IntList> const& num)
    {
        val = num.val;

        return *this;
    }

    template<typename IntList>
    double const& Quantity<IntList>::get_value() const
    {
        return val;
    }

    template<typename IntList>
    double& Quantity<IntList>::get_value()
    {
        return const_cast<double&>(const_cast<Quantity const*>(this)->get_value());
    }

    template<typename IntList>
    Quantity<IntList>& Quantity<IntList>::operator-=(Quantity const& rhs)
    {
        val -= rhs.val;

        return *this;
    }

    template<typename IntList>
    Quantity<IntList>& Quantity<IntList>::operator+=(Quantity const& rhs)
    {
        val += rhs.val;

        return *this;
    }

    template<typename IntList>
    Quantity<IntList>& Quantity<IntList>::operator*=(Quantity const& rhs)
    {
        val *= rhs.val;

        return *this;
    }

    template<typename IntList>
    Quantity<IntList>& Quantity<IntList>::operator/=(Quantity const& rhs)
    {
        val /= rhs.val;

        return *this;
    }

    template<typename IntList>
    bool operator<(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
    {
        return lhs.get_value() < rhs.get_value();
    }

    template<typename IntList>
    bool operator>(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
    {
        return lhs.get_value() > rhs.get_value();
    }

    template<typename IntList>
    bool operator==(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
    {
        return lhs.get_value() == rhs.get_value();
    }

    template<typename IntList>
    bool operator!=(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
    {
        return lhs.get_value() != rhs.get_value();
    }

    template<typename IntList>
    bool operator<=(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
    {
        return lhs.get_value() <= rhs.get_value();
    }

    template<typename IntList>
    bool operator>=(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
    {
        return lhs.get_value() >= rhs.get_value();
    }

    template<typename IntList>
    Quantity<IntList> operator-(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
    {
        return Quantity<IntList>(lhs) -= rhs;
    }

    template<typename IntList>
    Quantity<IntList> operator+(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
    {
        return Quantity<IntList>(lhs) += rhs;
    }

    template<typename IntList1, typename IntList2>
    Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Plus>> operator*(Quantity<IntList1> const& lhs, Quantity<IntList2> const& rhs)
    {
        return Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Plus>>(lhs.get_value() * rhs.get_value());
    }

    template<typename IntList1, typename IntList2>
    Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Minus>> operator/(Quantity<IntList1> const& lhs, Quantity<IntList2> const& rhs)
    {
        return Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Minus>>(lhs.get_value() / rhs.get_value());
    }

    template<typename IntList>
    Quantity<IntList> operator*(double lhs, Quantity<IntList> const& rhs)
    {
        return Quantity<IntList>(lhs * rhs.get_value());
    }

    template<typename IntList>
    Quantity<MetaProgramming::Zip<MetaProgramming::Generate<MetaProgramming::Length<IntList>::value>, IntList, MetaProgramming::Minus>> operator/(double lhs, Quantity<IntList> const& rhs)
    {
        return Quantity<MetaProgramming::Zip<MetaProgramming::Generate<MetaProgramming::Length<IntList>::value>, IntList, MetaProgramming::Minus>>(lhs / rhs.get_value());
    }
}