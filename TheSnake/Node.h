//
// Created by user on 2023/6/24.
//

#ifndef THESNAKE_NODE_H
#define THESNAKE_NODE_H

template <class T>
class Node {
public:
    T value;
    Node<T>* last = 0;
    Node(T value);
};


#endif //THESNAKE_NODE_H
