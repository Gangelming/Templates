#pragma once
#include <cmath>
#include <algorithm>
#include <stdexcept>

template<typename T, size_t N>
class MathVector {
private:
    T m_data[N];

public:

    MathVector() {
        std::fill(m_data, m_data + N, T());
    }

    explicit MathVector(const T& val) {
        std::fill(m_data, m_data + N, val);
    }

    MathVector(std::initializer_list<T> list) {
        size_t count = std::min(list.size(), N);
        std::copy_n(list.begin(), count, m_data);
        std::fill(m_data + count, m_data + N, T());
    }


    T& operator[](size_t index) {
        if (index >= N) throw std::out_of_range("Index hors limites");
        return m_data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= N) throw std::out_of_range("Index hors limites");
        return m_data[index];
    }

 
    T dot_product(const MathVector& other) const;
    MathVector normalized() const;
    MathVector operator+(const MathVector& other) const;

    template<size_t M = N>
    MathVector<T, 3> cross_product(const MathVector<T, 3>& other) const {
        static_assert(M == 3, "Cross product is only defined for 3D vectors");
        return MathVector<T, 3>{
            m_data[1] * other[2] - m_data[2] * other[1],
                m_data[2] * other[0] - m_data[0] * other[2],
                m_data[0] * other[1] - m_data[1] * other[0]
        };
    }
};