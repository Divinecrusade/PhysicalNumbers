#pragma once

namespace MetaProgramming
{
    template <int ... I>
    struct IntList;

    template <int n, int ... I>
    struct IntList<n, I...>
    {
        static constexpr int Head = n;
        using Tail = IntList<I...>;
    };

    template <>
    struct IntList<> { };

    template<typename IL>
    struct Length
    {
        static int const value = 1 +
            Length<typename IL::Tail>::value;
    };

    template<>
    struct Length<IntList<>>
    {
        static int const value = 0;
    };

    template<int N, typename IT>
    struct IntCons;

    template<int N, int... Ints>
    struct IntCons<N, IntList<Ints...>>
    {
        using type = IntList<N, Ints...>;
    };

    template<int N, int M = 0>
    struct Generate
    {
        using type = typename IntCons<0, typename Generate<N - 1, M + 1>::type>::type;
    };

    template<int M>
    struct Generate<0, M>
    {
        using type = IntList<>;
    };

    template<int a, int b>
    struct Plus
    {
        static int const value = a + b;
    };

    template<int a, int b>
    struct Minus
    {
        static int const value = a - b;
    };

    template<int a, int b>
    struct Neg
    {
        static int const value = a - 2 * b;
    };

    template<typename IL1, typename IL2, template <int, int> class Func>
    struct Zip
    {
        using type = typename IntCons<Func<IL1::Head, IL2::Head>::value,
            typename Zip<typename IL1::Tail, typename IL2::Tail, Func>::type>::type;
    };

    template<template <int, int> class Func>
    struct Zip<IntList<>, IntList<>, Func>
    {
        using type = IntList<>;
    };
}