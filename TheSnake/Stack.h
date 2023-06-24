//
// Created by user on 2023/6/24.
//

#ifndef THESNAKE_STACK_H
#define THESNAKE_STACK_H

#include "Node.cpp"
#include <iostream>

template<typename T>
class Stack {
private:
    Node<T>* back = 0;
    int size = 0;
public:
    void push(T val);
    void pop();
    T top();
    bool empty();
    int getSize();
    std::string to_string();
};


#endif //THESNAKE_STACK_H
