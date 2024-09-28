#pragma once

#include <string>

template <typename Data>
class Node {
    public:
        Data data;
        Node* next;
        Node* prev;

        Node(const Data& value, Node* nextNode = nullptr, Node* prevNode = nullptr) 
            : data(value), next(nextNode), prev(prevNode) {
        }
};