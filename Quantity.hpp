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

    private:

        double val{ };
    };
}