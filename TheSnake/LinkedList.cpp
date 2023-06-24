//
// Created by user on 2023/6/24.
//

#include "LinkedList.h"
#include <iostream>

using namespace std;

template<typename T>
void LinkedList<T>::add(T entry) {
    auto node = new Node<T>(entry);
    node->last = last;
    last = node;
    size++;
}

template<typename T>
void LinkedList<T>::insert_front(T entry) {
    auto node = new Node<T>(entry);
    auto ptr = last;
    while (ptr->last != nullptr) ptr = ptr->last;
    ptr->last = node;
    node->last = nullptr;
    size++;
}

template<typename T>
T &LinkedList<T>::getLast() {
    return last->value;
}

template<typename T>
int LinkedList<T>::getSize() {
    return size;
}

template<typename T>
Node<T> *LinkedList<T>::getLastNode() {
    return last;
}

template<typename T>
void LinkedList<T>::remove(int n) {
    if (n == size - 1) {
        remove_last();
        return;
    }
    auto ptr = last;
    for (int i = 0; i < (size - n - 2); i++) {
        ptr = ptr->last;
    }
    auto tmp = ptr->last;
    ptr->last = ptr->last->last;
    delete tmp;
    size--;
}

template<typename T>
void LinkedList<T>::remove_last() {
    auto tmp = last;
    last = last->last;
    size--;
    delete tmp;
    return;
}

template<typename T>
T &LinkedList<T>::at(int n) {
    auto ptr = last;
    for (int i = 0; i < (size - n - 1); i++) {
        ptr = ptr->last;
    }
    return ptr->value;
}