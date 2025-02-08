#include "intrusive_list.h"

template<typename T>
void IntrusiveList<T>::push_back(const T& value) {
    Node* newNode = new Node{ value, nullptr, tail };
    if (!head) head = newNode;
    if (tail) tail->next = newNode;
    tail = newNode;
    ++m_size;
}

template<typename T>
size_t IntrusiveList<T>::size() const {
    return m_size;
}


template class IntrusiveList<int>;