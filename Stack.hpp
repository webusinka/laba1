#pragma once
#include <iostream>

#include "Node.hpp"

template <typename Data>
class Stack {
public:
    Node<Data>* head;

    Stack() : head(nullptr) {}
    void push(const Data& value) {
        Node<Data>* newNode = new Node<Data>(value, this->head);
        this->head = newNode;
    }
    void pop() {
        if (this->head == nullptr) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        Node<Data>* next = this->head->next;
        delete this->head;
        this->head = next;
    }
    void search(const Data& value) {
        Node<Data>* current = this->head;
        while (current != nullptr) {
            if (current->data == value) {
                std::cout << "Found!" << std::endl;
                return;
            }
            current = current->next;
        }
        std::cout << "Not found!" << std::endl;
    }

};
