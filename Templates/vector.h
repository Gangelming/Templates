#pragma once
#include <stdexcept>
#include <algorithm>

template<typename T>
class Vector {
private:
    T* m_data = nullptr;
    size_t m_size = 0;
    size_t m_capacity = 0;

public:
    Vector();
    explicit Vector(size_t size);
    Vector(const Vector& other);
    ~Vector();

    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }

    T& operator[](size_t index);
    void push_back(const T& value);
    void resize(size_t new_size);
    void clear();
};