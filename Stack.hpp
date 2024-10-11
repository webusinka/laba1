#include <iostream>

#include "Node.hpp"
#include "List.hpp"

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
    void display() {
        Node<Data>* current = this->head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void load_from_file(std::string filename) {
        List<Data> list;
        list.load_from_file(filename);
        this->head = list.head;
    }

    void save_to_file(std::string filename) {
        List<Data> list;
        list.head = this->head;
        list.save_to_file(filename);
    }
};