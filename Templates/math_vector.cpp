#include "math_vector.h"

template<typename T, size_t N>
T MathVector<T, N>::dot_product(const MathVector& other) const {
    T result = 0;
    for (size_t i = 0; i < N; ++i)
        result += m_data[i] * other.m_data[i];
    return result;
}

template<typename T, size_t N>
MathVector<T, N> MathVector<T, N>::normalized() const {
    T magnitude = 0;
    for (size_t i = 0; i < N; ++i)
        magnitude += m_data[i] * m_data[i];
    magnitude = std::sqrt(magnitude);

    MathVector result;
    for (size_t i = 0; i < N; ++i)
        result.m_data[i] = m_data[i] / magnitude;
    return result;
}

template<typename T, size_t N>
MathVector<T, N> MathVector<T, N>::operator+(const MathVector& other) const {
    MathVector result;
    for (size_t i = 0; i < N; ++i)
        result.m_data[i] = m_data[i] + other.m_data[i];
    return result;
}

template class MathVector<float, 3>;