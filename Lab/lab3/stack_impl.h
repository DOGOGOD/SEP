#ifndef STACK_IMPL_H
#define STACK_IMPL_H
#include <cassert>
#include <cstddef>

template <typename T>
Stack<T>::Stack() : sz(0), head(nullptr) { }

template <typename T>
Stack<T>::~Stack() {
    while (head) {
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
void Stack<T>::push(T t) {
    Node<T>* tmp = new Node<T>(t);
    tmp->next = head;
    head = tmp;
    sz++;
}

template <typename T>
void Stack<T>::pop() {
    assert(!empty());
    Node<T>* tmp = head;
    head = head->next;
    delete tmp;
    sz--;
}

template <typename T>
T& Stack<T>::top() {
    assert(!empty());
    return head->val;
}

template <typename T>
bool Stack<T>::empty() const {
    return sz == 0;
}

template <typename T>
size_t Stack<T>::size() const {
    return sz;
}

#endif
