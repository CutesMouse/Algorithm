//
// Created by user on 2023/6/24.
//

#ifndef THESNAKE_LINKEDLIST_H
#define THESNAKE_LINKEDLIST_H
#include "Node.h"

template<typename T>
class LinkedList {
private:
    Node<T>* last = nullptr;
    int size = 0;
public:
    void add(T entry);
    void insert_front(T entry);
    T& getLast();
    int getSize();
    Node<T>* getLastNode();
    void remove(int n);
    void remove_last();
    T &at(int n);
};


#endif //THESNAKE_LINKEDLIST_H
