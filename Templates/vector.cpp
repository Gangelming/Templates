#include "vector.h"

template<typename T>
Vector<T>::Vector() = default;

template<typename T>
Vector<T>::Vector(size_t size) : m_data(new T[size]), m_size(size), m_capacity(size) {}

template<typename T>
Vector<T>::Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
    m_data = new T[m_capacity];
    std::copy(other.m_data, other.m_data + m_size, m_data);
}

template<typename T>
Vector<T>::~Vector() {
    delete[] m_data;
}

template<typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= m_size) throw std::out_of_range("Index hors limites");
    return m_data[index];
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (m_size == m_capacity) {
        size_t new_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
        T* new_data = new T[new_capacity];
        std::copy(m_data, m_data + m_size, new_data);
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
    m_data[m_size++] = value;
}

template<typename T>
void Vector<T>::resize(size_t new_size) {
    if (new_size > m_capacity) {
        T* new_data = new T[new_size];
        std::copy(m_data, m_data + m_size, new_data);
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_size;
    }
    m_size = new_size;
}

template<typename T>
void Vector<T>::clear() {
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template class Vector<int>;