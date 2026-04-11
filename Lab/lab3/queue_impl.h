#ifndef QUEUE_IMPL_H
#define QUEUE_IMPL_H
#include <cassert>
#include <cstddef>

template <typename T>
Queue<T>::Queue() : sz(0), head(nullptr), tail(nullptr) { }

template <typename T>
Queue<T>::~Queue() {
    while (head) {
        Node<T> *tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
void Queue<T>::push(T t) {
    Node<T>* tmp = new Node<T>(t);
    if (tail) { 
        tail->next = tmp;
    } else {
        head = tmp;
    }
    tail = tmp;
    sz++;
}

template <typename T>
void Queue<T>::pop() {
    assert(!empty());
    Node<T>* tmp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete tmp;
    sz--;
}

template <typename T>
T &Queue<T>::front() {
    assert(!empty());
    return head->val;
}

template <typename T>
bool Queue<T>::empty() const {
    return sz == 0;
}

template <typename T>
size_t Queue<T>::size() const {
    return sz;
}
#endif
