#pragma once

namespace PhysicalNumbers
{
    template<class T>
    __interface ILogicalOperations
    {
        static bool operator<(T const& lhs, T const& rhs) = 0;

        static bool operator>(T const& lhs, T const& rhs) { return !(lhs < rhs); }

        static bool operator!=(T const& lhs, T const& rhs) { return lhs < rhs || rhs < lhs; }
        static bool operator==(T const& lhs, T const& rhs) { return !(lhs < rhs || rhs < lhs); }

        static bool operator<=(T const& lhs, T const& rhs) { return lhs < rhs || lhs == rhs; }
        static bool operator>=(T const& lhs, T const& rhs) { return lhs > rhs || lhs == rhs; }

        static bool operator bool(T const& rhs) = 0;
    };
}