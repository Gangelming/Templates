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

template<typename T>
class List : public Container<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;


    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}
        T& operator*() { return current->data; }
        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }
        bool operator!=(const Iterator& other) { return current != other.current; }
    };

public:
    List() = default;

    ~List() {
        clear();
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        this->m_size++;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = head;
        this->m_size++;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
        this->m_size--;
    }

    void resize(size_t new_size) override {
        while (this->m_size < new_size) {
            push_back(T());
        }
        while (this->m_size > new_size) {
            pop_front();
        }
    }

    void clear() override {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        this->m_size = 0;
    }

    T& front() { return head->data; }
    const T& front() const { return head->data; }

    T& back() { return tail->data; }
    const T& back() const { return tail->data; }

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};