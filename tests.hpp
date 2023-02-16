#pragma once

#include <iostream>
#include <string>

#include "Quantity.hpp"

namespace PhysicalNumbers
{
    namespace tests
    {
        using std::cout;
        using std::clog;
        using std::cerr;
        using namespace MetaProgramming;

        static constexpr double init_val0{0.};
        static constexpr double init_val1{1.4};
        static constexpr double init_val2{-2.3};

        template<typename T1, typename T2>
        inline void send_log(std::string const& msg, T1 const& expected, T2 const& got)
        {
            clog << msg << " | Expected: " << expected << " | Got: " << got << "\n";
        }

        void creation()
        {
            static constexpr char const* msg{"Creation"};

            Quantity<IntList<0, 1, 0>> a1(init_val0);
            Quantity<IntList<0, 1, 0>> a2(init_val1);
            Quantity<IntList<0, 1, 0>> a3(init_val2);

            send_log(msg, init_val0, a1.get_value());
            send_log(msg, init_val1, a2.get_value());
            send_log(msg, init_val2, a3.get_value());
        }

        void assignment()
        {
            static constexpr char const* msg{"Assignment"};

            Quantity<IntList<1, 0>> a1(init_val0);
            Quantity<IntList<1, 0>> a2(init_val1);
            Quantity<IntList<1, 0>> a3 = a1;
            Quantity<IntList<1, 0>> a4 = a2;

            send_log(msg, a1.get_value(), a3.get_value());
            send_log(msg, a2.get_value(), a4.get_value());
        }

        void logical()
        {
            static constexpr char const* msg{"Logical"};

            Quantity<IntList<0>> a1(init_val0);
            Quantity<IntList<0>> a2(init_val1);
            Quantity<IntList<0>> a3(init_val2);

            send_log(msg, true, a1 != a2);
            send_log(msg, true, a1 == a1);
            send_log(msg, true, a1 == Quantity<IntList<0>>(a1));
            send_log(msg, false, a1 > a2);
            send_log(msg, true, a1 >= Quantity<IntList<0>>(a1));
            send_log(msg, false, a2 < a3);
            send_log(msg, false, a2 <= a3);
        }

        void arithmetic()
        {
            static constexpr char const* msg{"Arithmetic"};

            Quantity<IntList<1>> a1(init_val0);
            Quantity<IntList<1>> a2(init_val1);
            Quantity<IntList<1>> a3(init_val2);

            send_log(msg, init_val0 + init_val0, (a1 + a1).get_value());
            send_log(msg, init_val2 - init_val1, (a3 - a2).get_value());
            send_log(msg, init_val0 * init_val1, (a1 * a2).get_value());
            send_log(msg, init_val2 / init_val1, (a3 / a2).get_value());
            send_log(msg, init_val1 * init_val2, (a2 * a3).get_value());

            send_log(msg, init_val1 / init_val2, (init_val1 / Quantity<IntList<0, 1, 0>>(init_val2)).get_value());
            send_log(msg, init_val1 * init_val2, (init_val1 * Quantity<IntList<0, 1, 0>>(init_val2)).get_value());
        }

        void combined()
        {
            static constexpr char const* msg{"Combined"};

            Quantity<IntList<1, 0, 0>> a1(init_val0);
            Quantity<IntList<1, 0, 0>> a2(init_val1);
            Quantity<IntList<1, 0, 0>> a3(init_val2);
            Quantity<IntList<1, 0, 0>> a4(init_val2);

            a1 += a2;
            send_log(msg, init_val0 + init_val1, a1.get_value());

            a3 -= a2;
            send_log(msg, init_val2 - init_val1, a3.get_value());

            a2 *= a2;
            send_log(msg, init_val1 * init_val1, a2.get_value());

            a2 /= a1;
            send_log(msg, init_val1 * init_val1 / (init_val0 + init_val1), a2.get_value());
        }
    }
}