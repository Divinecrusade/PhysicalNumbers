#include "Quantity.hpp"

template<typename IntList>
PhysicalNumbers::Quantity<IntList>::Quantity(double init_val) : val(init_val) { }

template<typename IntList>
PhysicalNumbers::Quantity<IntList>::Quantity(Quantity const& num) : val(num.val) { }

template<typename IntList>
PhysicalNumbers::Quantity<IntList>& PhysicalNumbers::Quantity<IntList>::operator=(Quantity<IntList> const& num)
{
    val = num.val;

    return *this;
}

template<typename IntList>
double const& PhysicalNumbers::Quantity<IntList>::get_value() const
{
    return val;
}

template<typename IntList>
double& PhysicalNumbers::Quantity<IntList>::get_value()
{
    return const_cast<double&>(const_cast<Quantity const*>(this)->get_value());
}

template<typename IntList>
PhysicalNumbers::Quantity<IntList>& PhysicalNumbers::Quantity<IntList>::operator-=(Quantity const& rhs)
{
    return *this = *this - rhs;
}

template<typename IntList>
PhysicalNumbers::Quantity<IntList>& PhysicalNumbers::Quantity<IntList>::operator+=(Quantity const& rhs)
{
    return *this = *this + rhs;
}

template<typename IntList>
PhysicalNumbers::Quantity<IntList>& PhysicalNumbers::Quantity<IntList>::operator*=(Quantity const& rhs)
{
    return *this = *this * rhs;
}

template<typename IntList>
PhysicalNumbers::Quantity<IntList>& PhysicalNumbers::Quantity<IntList>::operator/=(Quantity const& rhs)
{
    return *this = *this / rhs;
}

template<typename IntList>
bool PhysicalNumbers::operator<(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
{
    return lhs.get_value() < rhs.get_value();
}

template<typename IntList>
bool PhysicalNumbers::operator>(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
{
    return lhs.get_value() > rhs.get_value();
}

template<typename IntList>
bool PhysicalNumbers::operator==(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
{
    return lhs.get_value() == rhs.get_value();
}

template<typename IntList>
bool PhysicalNumbers::operator!=(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
{
    return lhs.get_value() != rhs.get_value();
}

template<typename IntList>
bool PhysicalNumbers::operator<=(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
{
    return lhs.get_value() <= rhs.get_value();
}

template<typename IntList>
bool PhysicalNumbers::operator>=(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
{
    return lhs.get_value() >= rhs.get_value();
}

template<typename IntList>
PhysicalNumbers::Quantity<IntList> PhysicalNumbers::operator-(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
{
    return Quantity<IntList>(lhs.get_value() - rhs.get_value());
}

template<typename IntList>
PhysicalNumbers::Quantity<IntList> PhysicalNumbers::operator+(Quantity<IntList> const& lhs, Quantity<IntList> const& rhs)
{
    return Quantity<IntList>(lhs.get_value() + rhs.get_value());
}

template<typename IntList1, typename IntList2>
PhysicalNumbers::Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Plus>> PhysicalNumbers::operator*(Quantity<IntList1> const& lhs, Quantity<IntList2> const& rhs)
{
    return Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Plus>>(lhs.get_value() * rhs.get_value());
}

template<typename IntList1, typename IntList2>
PhysicalNumbers::Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Minus>> PhysicalNumbers::operator/(Quantity<IntList1> const& lhs, Quantity<IntList2> const& rhs)
{
    return Quantity<MetaProgramming::Zip<IntList1, IntList2, MetaProgramming::Minus>>(lhs.get_value() / rhs.get_value());
}