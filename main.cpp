#include "Spring.h"

// for finite difference
constexpr double smallNumber = 1e-9;

int main()
{
    using Scalar = double;

    const Vec<3, Scalar > a{};
    const Vec<3, Scalar > b{1.,3.,-9.};

    constexpr Scalar k = 100;
    constexpr Scalar restLength = 3;

    //potential energy
    const auto U = potentialEnergySpring(a, b, k, restLength);
    std::cout << "U = " << U << '\n';

    //force
    const auto Fa = forceSpring(a, b, k, restLength);
    std::cout << "Fa = " << Fa << '\n';
    const auto Fb = -forceSpring(a, b, k, restLength);
    std::cout << "Fb = " << Fb << '\n';

    //finite difference Fa
    Vec<3, Scalar > finiteDiffFa;
    for (std::size_t i = 0; i < 3; ++i)
    {
        Vec<3, Scalar> h{0., 0., 0.};
        h[i] = smallNumber;
        const auto Uah = potentialEnergySpring(a + h, b, k, restLength);
        finiteDiffFa[i] = (Uah - U)/smallNumber;
    }
    std::cout << "Finite difference Fa = " << finiteDiffFa << '\n';

    //finite difference Fb
    Vec<3, Scalar > finiteDiffFb;
    for (std::size_t i = 0; i < 3; ++i)
    {
        Vec<3, Scalar> h{0., 0., 0.};
        h[i] = smallNumber;
        const auto Ubh = potentialEnergySpring(a, b + h, k, restLength);
        finiteDiffFb[i] = (Ubh - U)/smallNumber;
    }
    std::cout << "Finite difference Fb = " << finiteDiffFb << '\n';

    //stiffness matrix
    const auto K = stiffnessMatrix(a, b, k, restLength);
    std::cout << "Stiffness matrix K = " << K << '\n';

    //finite difference: stiffness matrix Kaa
    Mat<3, 3, Scalar> finiteDifferenceKaa;
    for (std::size_t i = 0; i < 3; ++i)
    {
        Vec<3, Scalar> h{0., 0., 0.};
        h[i] = smallNumber;
        const auto Fah = forceSpring(a + h, b, k, restLength);
        finiteDifferenceKaa[i] = (Fah - Fa) / smallNumber;
    }
    std::cout << "Finite difference Kaa = " << finiteDifferenceKaa << std::endl;

    return 0;
}
