//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>

template<typename T>
class DoublyLinkedNode {
private:
public:
    T value; //Value of node
    DoublyLinkedNode *prev = nullptr, *next = nullptr;
};

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
