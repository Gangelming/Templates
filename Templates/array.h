#pragma once
#include <stdexcept>
#include <algorithm>

template<typename T, size_t N>
class Array {
private:
    T m_data[N];

public:
   
    Array() = default;

    explicit Array(const T& val) {
        std::fill(m_data, m_data + N, val);
    }


    Array(std::initializer_list<T> list) {
        size_t count = std::min(list.size(), N);
        std::copy_n(list.begin(), count, m_data);
        std::fill(m_data + count, m_data + N, T());
    }

    // Accès aux éléments
    T& operator[](size_t index) {
        if (index >= N) throw std::out_of_range("Index hors limites");
        return m_data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= N) throw std::out_of_range("Index hors limites");
        return m_data[index];
    }

    // Taille
    constexpr size_t size() const { return N; }
    constexpr bool empty() const { return N == 0; }

    // Itérateurs
    T* begin() { return m_data; }
    const T* begin() const { return m_data; }
    T* end() { return m_data + N; }
    const T* end() const { return m_data + N; }

    // Opérations
    void fill(const T& val) {
        std::fill(m_data, m_data + N, val);
    }

    void swap(Array& other) noexcept {
        std::swap_ranges(m_data, m_data + N, other.m_data);
    }

    // Accès aux premiers et derniers éléments
    T& front() {
        if (N == 0) throw std::out_of_range("Tableau vide");
        return m_data[0];
    }

    const T& front() const {
        if (N == 0) throw std::out_of_range("Tableau vide");
        return m_data[0];
    }

    T& back() {
        if (N == 0) throw std::out_of_range("Tableau vide");
        return m_data[N - 1];
    }

    const T& back() const {
        if (N == 0) throw std::out_of_range("Tableau vide");
        return m_data[N - 1];
    }
};