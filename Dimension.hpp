#pragma once

#include "MetaProgramming.hpp"

namespace PhysicalNumbers
{
    using MetaProgramming::Zip;
    using MetaProgramming::Plus;
    using MetaProgramming::Minus;

    template<int m = 0, int kg = 0, int s = 0, int A = 0, int K = 0, int mol = 0, int cd = 0>
    using Dimension = MetaProgramming::IntList<m, kg, s, A, K, mol, cd>;

    using Number     = Dimension<>;                     // ����� ��� �����������
    using Distance   = Dimension<1>;                    // ����������, �
    using Square     = Dimension<2>;                    // �������, �2
    using Mass       = Dimension<0, 1>;                 // �����, ��
    using Time       = Dimension<0, 0, 1>;              // �����, �
    using MechForce  = Dimension<1, 1, -2>;             // ������������ ����, �
    using ElForce    = Dimension<0, 0, 0, 1>;           // ���� ����, �
    using Frequency  = Dimension<0, 0, -1>;             // �������, ��

    using Velocity = Zip<Distance, Time, Minus>;        // ��������, � * �
    using Accel    = Zip<Velocity, Time, Minus>;        // ���������, � * �2
    using Energy   = Zip<MechForce, Distance, Plus>;    // �������, ��
    using Power    = Zip<Energy, Time, Plus>;           // ��������,  ��
    using Pressure = Zip<MechForce, Square, Minus>;     // ��������, ��
    using ElCharge = Zip<ElForce, Time, Plus>;          // ������������� �����, ��
    
    using PotentialDiff     = Zip<Energy, ElCharge, Minus>;                   // �������� �����������, �
    using ElResistance      = Zip<PotentialDiff, ElForce, Minus>;             // ������������� �������������, ��
    using ElCapacity        = Zip<ElCharge, PotentialDiff, Minus>;            // ��������������, �
    using MagneticFlux      = Zip<Zip<Zip<Mass, Square, Plus>, Dimension<0, 0, -2>, Plus>,
                              Zip<Dimension<>, ElForce, Minus>, Plus>;        // ��������� �����, ��
    using MagneticInduction = Zip<MagneticFlux, Square, Minus>;               // ��������� ��������, ��
    using Inductance        = Zip<Zip<Zip<Mass, Square, Plus>, Dimension<0, 0, -2>, Plus>,
                              Dimension<0, 0, 0, -2>, Plus>;                  // �������������, ��
    using ElConductivity    = Zip<Dimension<>, ElResistance, Minus>;          // ������������� ������������, ��
}