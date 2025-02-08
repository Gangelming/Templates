#pragma once
#include <cstddef>

template<typename T>
class IntrusiveList {
private:
    struct Node {
        T data;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    size_t m_size = 0;

public:
    void push_back(const T& value);
    size_t size() const;
};