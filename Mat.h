#pragma once

#include "Vec.h"

template<std::size_t L, std::size_t C, class Scalar>
struct Mat
{
    using Line = Vec<C, Scalar>;
private:
    std::array<Line, L> m_elements {};
public:
    Line& operator[](std::size_t i) { return m_elements[i];}
    Line operator[](std::size_t i) const { return m_elements[i];}

    Mat operator+(const Mat& other) const
    {
        Mat result;
        std::transform(m_elements.begin(), m_elements.end(),
            other.m_elements.begin(), result.m_elements.begin(), std::plus<>{});
        return result;
    }

    Mat operator-(const Mat& other) const
    {
        Mat result;
        std::transform(m_elements.begin(), m_elements.end(),
            other.m_elements.begin(), result.m_elements.begin(), std::minus<>{});
        return result;
    }

    Mat operator*(const Scalar& s) const
    {
        Mat result;
        std::transform(m_elements.begin(), m_elements.end(), result.m_elements.begin(), [s](const Line e) { return e * s;});
        return result;
    }
};

template<std::size_t L, std::size_t C, class Scalar>
Mat<L, C, Scalar> operator*(Scalar s, const Mat<L, C, Scalar>& v)
{
    return v * s;
}

template<std::size_t N, class Scalar>
Mat<N, N, Scalar> identity()
{
    Mat<N, N, Scalar> id;
    for (std::size_t i = 0 ; i < N; ++i)
    {
        id[i][i] = 1;
    }
    return id;
}

template<std::size_t L, std::size_t C, class Scalar>
std::ostream& operator << ( std::ostream& out, const Mat<L, C, Scalar>& v )
{
    for (std::size_t i = 0; i < L - 1; ++i)
    {
        out << v[i] << " ";
    }
    out<< v[L-1];
    return out;
}

template<std::size_t N, class Scalar>
Mat<N, N, Scalar> outerProduct(const Vec<N, Scalar>& u, const Vec<N, Scalar>& v)
{
    Mat<N, N, Scalar> r;
    for (std::size_t i = 0 ; i < N; ++i)
    {
        for (std::size_t j = 0 ; j < N; ++j)
        {
            r[i][j] = u[i] * v[j];
        }
    }
    return r;
}
