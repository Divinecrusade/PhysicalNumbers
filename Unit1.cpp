#include <iostream>

#include "tests.hpp"

#define CRT
#define ASS
#define LOG
#define ARM
#define CMB

using namespace PhysicalNumbers::tests;

int main()
{
#ifdef CRT

    creation();

#endif // CRT

#ifdef ASS

    assignment();

#endif // ASS

#ifdef LOG

    logical();

#endif // LOG

#ifdef ARM

    arithmetic();

#endif // ARM

#ifdef CMB
    
    combined();
    
#endif // CMB

    return 0;
}