#pragma once

namespace LogicalOperations
{
    // Realize compile-time check for realized logical operation

    // Req: operator<
    template<class T>
    bool operator>(T const& lhs, T const& rhs)  { return !(lhs < rhs) && (lhs < rhs || rhs < lhs); }

    // Req: operator<
    template<class T>
    bool operator!=(T const& lhs, T const& rhs) { return lhs < rhs || rhs < lhs; }

    // Req: operator<
    template<class T>
    bool operator==(T const& lhs, T const& rhs) { return !(lhs < rhs || rhs < lhs); }

    // Req: operator<
    template<class T>
    bool operator<=(T const& lhs, T const& rhs) { return lhs < rhs || !(lhs < rhs || rhs < lhs); }

    // Req: operator<
    template<class T>
    bool operator>=(T const& lhs, T const& rhs) { return !(lhs < rhs) && (lhs < rhs || rhs < lhs) || !(lhs < rhs || rhs < lhs); }
}