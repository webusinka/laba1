#pragma once
#include <iostream>

template <typename Data>
class Array {
    public:

        Data* array;
        int size;       // размерность массива
        int capacity; // текущая ёмкость массива

        Array() : array(nullptr), size(0), capacity(0) {}

        ~Array() {
            delete[] array;
        }

        void initialize(Array& checklist, int initialCapacity){
            checklist.capacity = initialCapacity; 
            checklist.size = 0;
            checklist.array = new Data[checklist.capacity]; 
        }
        void push_front(Array& checklist, const Data& value){ //добавление в начало массива
                if (checklist.size == checklist.capacity) {
                    int newCapacity = checklist.capacity * 2;
                    Data* newArray = new Data[newCapacity];

                    for (int i = 0; i < checklist.size; i++) {
                        newArray[i] = checklist.array[i];
                    }

                    delete[] checklist.array; 
                    checklist.array = newArray;
                    checklist.capacity = newCapacity;
                }
                for (int i = checklist.size; i > 0; i--) { 
                    checklist.array[i] = checklist.array[i - 1];
                }

                checklist.array[0] = value;
                checklist.size++;
        }
        void push_back(Array& checklist, const Data& value){
                if (checklist.size == checklist.capacity) {
                    int newCapacity = checklist.capacity * 2;
                    Data* newArray = new Data[newCapacity];

                    for (int i = 0; i < checklist.size; i++) {
                        newArray[i] = checklist.array[i];
                    }

                    delete[] checklist.array;
                    checklist.array = newArray;
                    checklist.capacity = newCapacity;
                }

                checklist.array[checklist.size] = value;
                checklist.size++;
        }
        void push_in(Array& checklist, int index, const Data& value){
            if (index < 0 || index > checklist.size) {
                std::cout << "Invalid index" << std::endl;
                return;
            }

            if (checklist.size == checklist.capacity) {
                int newCapacity = checklist.capacity * 2;
                Data* newArray = new Data[newCapacity];

                for (int i = 0; i < checklist.size; i++) {
                    newArray[i] = checklist.array[i];
                }

                delete[] checklist.array;
                checklist.array = newArray;
                checklist.capacity = newCapacity;
            }

            for (int i = checklist.size; i > index; i--) {
                checklist.array[i] = checklist.array[i - 1];
            }

            checklist.array[index] = value;
            checklist.size++;
        }
        void pop_front(Array& checklist){
            if (checklist.size <= 0) {
                std::cout << "Array is empty, cannot pop front." << std::endl;
            } else {
                for (int i = 0; i < checklist.size - 1; i++) {
                    checklist.array[i] = checklist.array[i + 1];
                }
                checklist.size--;
            }
        }
        void pop_back(Array& checklist){
            if (checklist.size > 0) {
                checklist.size--;
            } else {
                std::cout << "Array is empty, cannot pop back." << std::endl;
            }
        }
        void pop_in(Array& checklist, int index){
            if (index < 0 || index >= checklist.size) {
                std::cout << "Invalid index" << std::endl;
                return;
            }
            for (int i = index; i < checklist.size - 1; i++) {
                checklist.array[i] = checklist.array[i + 1];
            }
            checklist.size--;
        }
        void search(const Array& checklist, const Data& value){
            for (int i = 0; i < checklist.size; i++) {
                if (checklist.array[i] == value) {
                    std::cout << "Found!" << std::endl;
                    return;
                }
            }
            std::cout << "Not found!" << std::endl;
        }
        void search_index(const Array& checklist, const int index){
            if (index >= 0 && index < checklist.size) {
                std::cout << checklist.array[index] << std::endl;
            } else {
                std::cout << "Invalid index" << std::endl;
            }
        }
        void display(const Array& checklist){
            for (int i = 0; i < checklist.size; i++) {
                std::cout << checklist.array[i] << " ";
            }
            std::cout << std::endl;

        }
        void set(const Array& checklist, const int index, Data value){
            if (index >= 0 && index <= size) {
                checklist.array[index] = value;
                std::cout << checklist.array[index] << std::endl;
            } else {
                std::cout << "Invalid index" << std::endl; 
            }
        }
};