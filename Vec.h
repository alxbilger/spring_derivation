#pragma once
#include <array>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cmath>

template<std::size_t N, class Scalar>
struct Vec
{
private:
    std::array<Scalar, N> m_elements {};

public:
    Vec() = default;

    template<typename ...E>
    Vec(E&&...e) : m_elements({std::forward<E>(e)...})
    {}

    Scalar& operator[](std::size_t i) { return m_elements[i];}
    Scalar operator[](std::size_t i) const { return m_elements[i];}

    Vec operator+(const Vec& other) const
    {
        Vec result;
        std::transform(m_elements.begin(), m_elements.end(),
            other.m_elements.begin(), result.m_elements.begin(), std::plus<>{});
        return result;
    }

    Vec operator-(const Vec& other) const
    {
        Vec result;
        std::transform(m_elements.begin(), m_elements.end(),
            other.m_elements.begin(), result.m_elements.begin(), std::minus<>{});
        return result;
    }

    Vec operator-() const
    {
        Vec result;
        std::transform(m_elements.begin(), m_elements.end(), result.m_elements.begin(), [](const Scalar e){ return -e;});
        return result;
    }

    Vec operator*(const Scalar& s) const
    {
        Vec result;
        std::transform(m_elements.begin(), m_elements.end(), result.m_elements.begin(), [s](const Scalar e) { return e * s;});
        return result;
    }

    Vec operator/(const Scalar& s) const
    {
        Vec result;
        std::transform(m_elements.begin(), m_elements.end(), result.m_elements.begin(), [s](const Scalar e) { return e / s;});
        return result;
    }

    [[nodiscard]] Scalar norm2() const
    {
        return std::sqrt(
            std::accumulate(m_elements.begin(), m_elements.end(), static_cast<Scalar>(0), [](const Scalar sum, const Scalar e){ return sum + e * e;})
        );
    }
};

template<std::size_t N, class Scalar>
Vec<N, Scalar> operator*(Scalar s, const Vec<N, Scalar>& v)
{
    return v * s;
}

template<std::size_t N, class Scalar>
std::ostream& operator << ( std::ostream& out, const Vec<N, Scalar>& v )
{
    out << "[";
    for (std::size_t i = 0; i < N - 1; ++i)
    {
        out << v[i] << " ";
    }
    out << v[N - 1] << "]";
    return out;
}
