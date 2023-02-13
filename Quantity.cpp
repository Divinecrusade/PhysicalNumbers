#include "Quantity.hpp"

PhysicalNumbers::Quantity::Quantity(double init_val) : val(init_val) { }

PhysicalNumbers::Quantity::Quantity(Quantity const& num) : val(num.val) { }

PhysicalNumbers::Quantity& PhysicalNumbers::Quantity::operator=(Quantity const& num)
{
    val = num.val;

    return *this;
}

double const& PhysicalNumbers::Quantity::get_value() const
{
    return val;
}

double& PhysicalNumbers::Quantity::get_value()
{
    return const_cast<double&>(const_cast<Quantity const*>(this)->get_value());
}

PhysicalNumbers::Quantity& PhysicalNumbers::Quantity::operator-=(Quantity const& rhs)
{
    return *this = *this - rhs;
}

PhysicalNumbers::Quantity& PhysicalNumbers::Quantity::operator+=(Quantity const& rhs)
{
    return *this = *this + rhs;
}

PhysicalNumbers::Quantity& PhysicalNumbers::Quantity::operator*=(Quantity const& rhs)
{
    return *this = *this * rhs;
}

PhysicalNumbers::Quantity& PhysicalNumbers::Quantity::operator/=(Quantity const& rhs)
{
    return *this = *this / rhs;
}

bool PhysicalNumbers::operator<(Quantity const& lhs, Quantity const& rhs)
{
    return lhs.get_value() < rhs.get_value();
}

bool PhysicalNumbers::operator>(Quantity const& lhs, Quantity const& rhs)
{
    return lhs.get_value() > rhs.get_value();
}

bool PhysicalNumbers::operator==(Quantity const& lhs, Quantity const& rhs)
{
    return lhs.get_value() == rhs.get_value();
}

bool PhysicalNumbers::operator!=(Quantity const& lhs, Quantity const& rhs)
{
    return lhs.get_value() != rhs.get_value();
}

bool PhysicalNumbers::operator<=(Quantity const& lhs, Quantity const& rhs)
{
    return lhs.get_value() <= rhs.get_value();
}

bool PhysicalNumbers::operator>=(Quantity const& lhs, Quantity const& rhs)
{
    return lhs.get_value() >= rhs.get_value();
}

PhysicalNumbers::Quantity PhysicalNumbers::operator-(Quantity const& lhs, Quantity const& rhs)
{
    return Quantity(lhs.get_value() - rhs.get_value());
}

PhysicalNumbers::Quantity PhysicalNumbers::operator+(Quantity const& lhs, Quantity const& rhs)
{
    return Quantity(lhs.get_value() + rhs.get_value());
}

PhysicalNumbers::Quantity PhysicalNumbers::operator*(Quantity const& lhs, Quantity const& rhs)
{
    return Quantity(lhs.get_value() * rhs.get_value());
}

PhysicalNumbers::Quantity PhysicalNumbers::operator/(Quantity const& lhs, Quantity const& rhs)
{
    return Quantity(lhs.get_value() / rhs.get_value());
}
