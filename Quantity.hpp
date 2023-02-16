#pragma once

#include "MetaProgramming.hpp"

namespace PhysicalNumbers
{
    using namespace MetaProgramming;

    template<typename IntList>
    class Quantity
    {

    public:

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
}