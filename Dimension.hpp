#pragma once

#include "MetaProgramming.hpp"

namespace PhysicalNumbers
{
    using MetaProgramming::Zip;
    using MetaProgramming::Plus;
    using MetaProgramming::Minus;

    template<int m = 0, int kg = 0, int s = 0, int A = 0, int K = 0, int mol = 0, int cd = 0>
    using Dimension = MetaProgramming::IntList<m, kg, s, A, K, mol, cd>;

    using Number     = Dimension<>;                     // число без размерности
    using Distance   = Dimension<1>;                    // расстояние, м
    using Square     = Dimension<2>;                    // площадь, м2
    using Mass       = Dimension<0, 1>;                 // масса, кг
    using Time       = Dimension<0, 0, 1>;              // время, с
    using MechForce  = Dimension<1, 1, -2>;             // механическая сила, Н
    using ElForce    = Dimension<0, 0, 0, 1>;           // сила тока, А
    using Frequency  = Dimension<0, 0, -1>;             // частота, Гц

    using Velocity = Zip<Distance, Time, Minus>;        // скорость, м * с
    using Accel    = Zip<Velocity, Time, Minus>;        // ускорение, м * с2
    using Energy   = Zip<MechForce, Distance, Plus>;    // энергия, Дж
    using Power    = Zip<Energy, Time, Plus>;           // мощность,  Вт
    using Pressure = Zip<MechForce, Square, Minus>;     // давление, Па
    using ElCharge = Zip<ElForce, Time, Plus>;          // электрический заряд, Кл
    
    using PotentialDiff     = Zip<Energy, ElCharge, Minus>;                   // разность потенциалов, В
    using ElResistance      = Zip<PotentialDiff, ElForce, Minus>;             // электрическое сопротивление, Ом
    using ElCapacity        = Zip<ElCharge, PotentialDiff, Minus>;            // электроемкость, Ф
    using MagneticFlux      = Zip<Zip<Zip<Mass, Square, Plus>, Dimension<0, 0, -2>, Plus>,
                              Zip<Dimension<>, ElForce, Minus>, Plus>;        // магнтиный поток, Вб
    using MagneticInduction = Zip<MagneticFlux, Square, Minus>;               // магнитная индукция, Тл
    using Inductance        = Zip<Zip<Zip<Mass, Square, Plus>, Dimension<0, 0, -2>, Plus>,
                              Dimension<0, 0, 0, -2>, Plus>;                  // индуктивность, Гн
    using ElConductivity    = Zip<Dimension<>, ElResistance, Minus>;          // электрическая проводимость, См
}