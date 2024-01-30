#pragma once

#include "Mat.h"

/**
 * Calculates the potential energy of a spring based on Hooke's Law.
 *
 * @param a The position vector of the first end of the spring.
 * @param b The position vector of the second end of the spring.
 * @param springStiffness The stiffness constant of the spring.
 * @param springRestLength The rest length of the spring (undeformed length).
 * @return The potential energy of the spring.
 *
 * The potential energy (U) of a spring is given by the formula:
 * U = 0.5 * k * (||b - a|| - L0)^2
 * where:
 * - k is the spring stiffness constant,
 * - ||b - a|| is the distance between the two ends of the spring,
 * - L0 is the rest length of the spring.
 */
template<std::size_t N, class Scalar>
Scalar potentialEnergySpring(const Vec<N, Scalar>& a, const Vec<N, Scalar>& b, Scalar springStiffness, Scalar springRestLength)
{
    const auto elongation = (b-a).norm2() - springRestLength;
    return static_cast<Scalar>(0.5) * springStiffness * elongation * elongation;
}

/**
 * Calculates the force exerted by a spring based on Hooke's Law.
 *
 * @param a The position vector of the first end of the spring.
 * @param b The position vector of the second end of the spring.
 * @param springStiffness The stiffness constant of the spring.
 * @param springRestLength The rest length of the spring (undeformed length).
 * @return The force vector exerted by the spring.
 *
 * The force (F) exerted by a spring is given by the formula:
 * F = k * (||b - a|| - L0) * (b - a) / ||b - a||
 * where:
 * - k is the spring stiffness constant,
 * - ||b - a|| is the distance between the two ends of the spring,
 * - L0 is the rest length of the spring.
 */
template<std::size_t N, class Scalar>
Vec<N, Scalar> forceSpring(const Vec<N, Scalar>& a, const Vec<N, Scalar>& b, Scalar springStiffness, Scalar springRestLength)
{
    const auto difference = b-a;
    const auto length = difference.norm2();
    const auto direction = difference / length;
    return springStiffness * ( length - springRestLength) * direction;
}

/**
 * Calculates the stiffness matrix of a spring based on Hooke's Law.
 *
 * @param a The position vector of the first end of the spring.
 * @param b The position vector of the second end of the spring.
 * @param springStiffness The stiffness constant of the spring.
 * @param springRestLength The rest length of the spring (undeformed length).
 * @return The stiffness matrix of the spring
 */
template<std::size_t N, class Scalar>
Mat<N, N, Scalar> stiffnessMatrix(const Vec<N, Scalar>& a, const Vec<N, Scalar>& b, Scalar springStiffness, Scalar springRestLength)
{
    Mat<N, N, Scalar> r;

    const auto difference = b-a;
    const auto length = difference.norm2();
    const auto direction = difference / length;
    const auto elongation = length - springRestLength;

    const auto d2 = outerProduct(direction, direction);
    const auto ratio = elongation / length;
    return springStiffness * ( (ratio - 1) * d2 - ratio * identity<N, Scalar>());
}

