#pragma once

namespace PhysicalNumbers
{
    class Quantity
    {

    public:

        explicit Quantity(double init_val = 0.);
        Quantity(Quantity const& num);
        Quantity& operator=(Quantity const& num);

        Quantity& operator=(Quantity&&) = default;
        Quantity(Quantity&&) = default;

        ~Quantity() = default;

        double const& get_value() const;
        double      & get_value();

        Quantity& operator-=(Quantity const& rhs);
        Quantity& operator+=(Quantity const& rhs);
        Quantity& operator*=(Quantity const& rhs);
        Quantity& operator/=(Quantity const& rhs);

    private:

        double val{ };
    };

    bool operator<(Quantity const& lhs, Quantity const& rhs);
    bool operator>(Quantity const& lhs, Quantity const& rhs);
    bool operator==(Quantity const& lhs, Quantity const& rhs);
    bool operator!=(Quantity const& lhs, Quantity const& rhs);
    bool operator<=(Quantity const& lhs, Quantity const& rhs);
    bool operator>=(Quantity const& lhs, Quantity const& rhs);

    Quantity operator-(Quantity const& lhs, Quantity const& rhs);
    Quantity operator+(Quantity const& lhs, Quantity const& rhs);
    Quantity operator*(Quantity const& lhs, Quantity const& rhs);
    Quantity operator/(Quantity const& lhs, Quantity const& rhs);
}