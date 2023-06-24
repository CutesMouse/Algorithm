//
// Created by user on 2023/6/24.
//

#include "Stack.h"
#include "Node.h"
#include <vector>

using namespace std;

template<typename T>
void Stack<T>::push(T val) {
    auto *node = new Node<T>(val);
    node->last = back;
    back = node;
    size++;
}

template<typename T>
void Stack<T>::pop() {
    Node<T> *temp = back->last;
    delete back;
    back = temp;
    size--;
}

template<typename T>
T Stack<T>::top() {
    return back->value;
}

template<typename T>
int Stack<T>::getSize() {
    return size;
}

template<typename T>
bool Stack<T>::empty() {
    return back == nullptr;
}

template <typename T>
string Stack<T>::to_string() {
    if (empty()) return "";
    vector<T> inv;
    Node<T> *ptr = back;
    while (ptr != nullptr) {
        inv.push_back(ptr->value);
        ptr = ptr->last;
    }
    inv = vector<T>(inv.rbegin(), inv.rend());
    string builder;
    for (T k : inv) {
        builder += (string(1, k) + " ");
    }
    return builder;
}