#pragma once
#include <cstddef>

template<typename T>
class Container {
protected:
    size_t m_size = 0;
    size_t m_capacity = 0;

public:
    virtual void resize(size_t new_size) = 0;
    virtual void clear() = 0;
    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
};
