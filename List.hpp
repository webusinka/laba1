#pragma once

#include "Node.hpp"

template <typename Data>
class List{
    public:
        virtual void push_front(const Data& value) = 0;
        virtual void push_back(const Data& value) = 0;
        virtual void insert_after(Node<Data>* node, const Data& value) = 0;
        virtual void insert_before(Node<Data>* node, const Data& value) = 0;

        Node<Data>* head;
        Node<Data>* tail;
};

template <typename Data>
class List2 : public List<Data>{
    public:
        List2(): List<Data>() {};
        ~List2() {
            while (this->head != nullptr) {           //переписать
                Node<Data>* next = this->head->next;
                delete this->head;
                this->head = next;
            }
        }
        void push_front(const Data& value) {
            Node<Data>* newNode = new Node<Data>(value, nullptr,this->head);
            if (this->head != nullptr) {
                this->head->prev = newNode;
            }
            this->head = newNode;
            if (this->tail == nullptr) {
                this->tail = newNode;
            }
        }
        void push_back(const Data& value) {
            Node<Data>* newNode = new Node<Data>(value, nullptr, this->tail);
            if (this->tail != nullptr) {
                this->tail->next = newNode;
            }
            this->tail = newNode;
            if (this->head == nullptr) {
                this->head = newNode;
            }
        }
        void insert_after(Node<Data>* node, const Data& value) {
            Node<Data>* newNode = new Node<Data>(value, node->next, node);
            if (node->next != nullptr) {
                node->next->prev = newNode;
            }
            node->next = newNode;
        }
        void insert_before(Node<Data>* node, const Data& value) {
            Node<Data>* newNode = new Node<Data>(value, node, node->prev);
            if (node->prev != nullptr) {
                node->prev->next = newNode;
            }
            node->prev = newNode;
        }
        Data& operator[] (int index) {
            Node<Data>* node = this->head;
            for (int i = 0; i < index; i++) {
                node = node->next;
            }
            return node->data;
        }
};
