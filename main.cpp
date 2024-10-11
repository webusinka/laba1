#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <sys/wait.h>

#include "Array.hpp"
#include "List.hpp"
#include "Node.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "HashTable.hpp"
#include "AVL_tree.hpp"

using namespace std;

Array<string> arrays;
map<string, LinkedList<string>> linked_lists;
map<string, DoublyList<string>> doubly_lists;
map<string, Stack<string>> stacks;
map<string, Queue<string>> queues;
map<string, Hash_map<string, string, 1000>> hash_tables;
map<string, AVLTree<int>> trees;

// Обработка команды
void processQuery(const string& query) {
    stringstream ss(query);
    string command;
    ss >> command;
    // ----------ARRAY------

    // push_back(string value)
    // push_front(string value)
    // push_in(int index, string value)
    // pop_front()
    // pop_back()
    // pop_in(int index)
    // search(string value)
    // search_index(int index)
    // void display();
    if (command == "APUSH"){ // добавление элемента в конец
        arrays.load_from_file("array.txt");
        string name, value;
        ss >> name >> value;
        arrays.push_back(value);
        arrays.save_to_file("array.txt");
    }
    else if (command == "APUSH_FRONT"){ // добавление элемента в начало
        arrays.load_from_file("array.txt");
        string name, value;
        ss >> name >> value;
        arrays.push_front(value);
        arrays.save_to_file("array.txt");
    }
    else if (command == "AINSERT"){ // добавление элемента по индексу
        arrays.load_from_file("array.txt");
        string name, value;
        int index;
        ss >> name >> index >> value;
        arrays.push_in(index, value);
        arrays.save_to_file("array.txt");
    }
    else if (command == "APOP"){ // удаление элемента по индексу
        arrays.load_from_file("array.txt");
        string name;
        int index;
        ss >> name >> index;
        arrays.pop_in(index);
        arrays.save_to_file("array.txt");
    }
    else if (command == "APOP_FRONT"){ // удаление элемента из начала
        arrays.load_from_file("array.txt");
        string name;
        ss >> name;
        arrays.pop_front();
        arrays.save_to_file("array.txt");
    }
    else if (command == "APOP_BACK"){ // удаление по индексу
        arrays.load_from_file("array.txt");
        string name;
        ss >> name;
        arrays.pop_back();
        arrays.save_to_file("array.txt");
    }
    else if (command == "AGET"){ // получение элемента по индексу - search_index
        arrays.load_from_file("array.txt");
        string name;
        int index;
        ss >> name >> index;
        arrays.search_index(index);
        arrays.save_to_file("array.txt");
    }
    else if (command == "ASEARCH"){ // есть ли элемент по индексу 
        arrays.load_from_file("array.txt");
        string name, value;
        ss >> name  >> value;
        arrays.search(value);
        arrays.save_to_file("array.txt");
    }
    else if (command == "APRINT"){ // вывод на экран
        arrays.load_from_file("array.txt");
        arrays.display();
    }

    // ----------LINKEDLIST-------

    // push_front(string value) // добавление элемента в голову
    // push_back(string value) // добавление элемента в хвост
    // insert(int index, string value) // добавление элемента по индексу
    // pop_head() // удаление элемента с головы
    // pop_tail() // удаление элемента с хвоста
    // pop(int index) // удаление элемента по индексу
    // pop_value(Data value) // удаление элемента по значению
    // search(Data value) // поиск элемента по значению
    // void display();
    else if (command == "LPUSH_HEAD"){ // добавление элемента в голову
        string name, value;
        ss >> name >> value;
        linked_lists[name].push_front(value);
    }
    else if (command == "LPUSH_TAIL"){ // добавление элемента в хвост
        string name, value;
        ss >> name >> value;
        linked_lists[name].push_back(value);
    }
    else if (command == "LINSERT"){ // добавление элемента по индексу
        string name, value;
        int index;
        ss >> name >> index >> value;
        linked_lists[name].insert(index, value);
    }
    else if (command == "LPOP_HEAD"){ // удаление элемента с головы
        string name;
        ss >> name;
        linked_lists[name].pop_head();
    }
    else if (command == "LPOP_TAIL"){ // удаление элемента с хвоста
        string name;
        ss >> name;
        linked_lists[name].pop_tail();
    }
    else if (command == "LPOP"){ // удаление элемента с хвоста
        string name;
        int index;
        ss >> name >> index;
        linked_lists[name].pop(index);
    }
    else if (command == "LPOP_VALUE"){ // удаление элемента по значению
        string name, value;
        ss >> name >> value;
        linked_lists[name].pop_value(value);
    }
    else if (command == "LSEARCH"){ // поиск элемента по значению
        string name, value;
        ss >> name >> value;
        linked_lists[name].search(value);
    }
    else if (command == "LPRINT"){ // вывод на экран
        string name;
        ss >> name;
        linked_lists[name].display();
    }

        // ----------DOUBLYLIST-------

    // push_front(string value) // добавление элемента в голову
    // push_back(string value) // добавление элемента в хвост
    // push_in(int index, string value) // добавление элемента по индексу
    // search(Data value) // поиск элемента по значению
    // pop_forward() // удаление элемента с головы
    // pop_backward() // удаление элемента с хвоста
    // pop(int index) // удаление элемента по индексу
    // pop_value(Data value) // удаление элемента по значению
    // void display();
    else if (command == "2LPUSH_HEAD"){ // добавление элемента в голову
        string name, value;
        ss >> name >> value;
        doubly_lists[name].push_front(value);
    }
    else if (command == "2LPUSH_TAIL"){ // добавление элемента в хвост
        string name, value;
        ss >> name >> value;
        doubly_lists[name].push_back(value);
    }
    else if (command == "2LINSERT"){ // добавление элемента в хвост
        string name, value;
        int index;
        ss >> name >> index >> value;
        doubly_lists[name].push_in(index, value);
    }
    else if (command == "2LPOP_HEAD"){ // удаление элемента с головы
        string name;
        ss >> name;
        doubly_lists[name].pop_forward();
    }
    else if (command == "2LPOP_TAIL"){ // удаление элемента с хвоста
        string name;
        ss >> name;
        doubly_lists[name].pop_backward();
    }
    else if (command == "2LPOP"){ // удаление элемента по индексу
        string name;
        int index;
        ss >> name >> index;
        doubly_lists[name].pop(index);
    }
    else if (command == "2LPOP_VALUE"){ // удаление элемента по значению
        string name, value;
        ss >> name >> value;
        doubly_lists[name].pop_value(value);
    }
    else if (command == "2LSEARCH"){ // поиск элемента по значению
        string name, value;
        ss >> name >> value;
        doubly_lists[name].search(value);
    }
    else if (command == "2LPRINT"){ // вывод на экран
        string name;
        ss >> name;
        doubly_lists[name].display();
    }

    // ----------QUEUE-------


    else if (command == "QPUSH"){ // Добавление элемента
        string name, value;
        ss >> name >> value;
        queues[name].push(value);
    }
    else if (command == "QPOP"){ // удаление элемента
        string name;
        ss >> name;
        queues[name].pop();
    }
    else if (command == "QSEARCH"){ // поиск элемента
        string name, value;
        ss >> name >> value;
        queues[name].search(value);
    }
    else if (command == "QPRINT"){ //вывод на экран
        string name;
        ss >> name;
        queues[name].display();
    }
    
    // ----------STACK-------

    else if (command == "SPUSH"){ // Добавление элемента
        string name, value;
        ss >> name >> value;
        stacks[name].push(value);
    }
    else if (command == "SPOP"){ // удаление элемента
        string name;
        ss >> name;
        stacks[name].pop();
    }
    else if (command == "SSEARCH"){ // поиск элемента
        string name, value;
        ss >> name >> value;
        stacks[name].search(value);
    }
    else if (command == "SPRINT"){ //вывод на экран
        string name;
        ss >> name;
        stacks[name].display();
    }

    // ----------HASH-TABLE-------
    // get_value(string key, string value)
    // insert(string key, string value)
    // remove(string key)

    else if (command == "HPUSH"){ // Добавление элемента
        string name, key, value;
        ss >> name >> key >> value;
        hash_tables[name].insert(key, value);
    }
    else if (command == "HPOP"){ // Удаление элемента
        string name, key;
        ss >> name >> key;
        hash_tables[name].remove(key);
    }
    else if (command == "HGET"){ // Получение значения по ключу
        string name, key, value;
        ss >> name >> key >> value;
        hash_tables[name].get_value(key, value);
    }

    // ----------TREE-------
    // create_root(int data) // создание корня
    // insert(tree_node<Data>* _node, int data) // вставка ключа data в дерево
    // find(tree_node<Data>* _node, int data) // поиск узла с нужным значением
    // remove(tree_node<Data>* _node, int data) // удаление узла с нужным значением
    // printTree(tree_node<Data>* node) // вывод дерева на экран

    else if (command == "TROOT"){
        string name;
        int root;
        ss >> name >> root;
        trees[name].create_root(root);
    }
    else if (command == "TINSERT"){
        string name;
        int data;
        ss >> name >> data;
        trees[name].insert(trees[name].root, data);
    }
    else if (command == "TSEARCH"){
        string name;
        int data;
        ss >> name >> data;
        trees[name].find(trees[name].root, data);
    }
    else if (command == "TPOP"){
        string name;
        int data;
        ss >> name >> data;
        trees[name].root = trees[name].remove(trees[name].root, data);
    }
    else if (command == "TPRINT"){
        string name;
        ss >> name;
        trees[name].printTree(trees[name].root);
    }
    else {
        cout << "Неизвестная команда: " << command << endl;
    }
}

// Загрузка данных из файла
void loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        processQuery(line);
    }
    file.close();
}

// Сохранение данных в файл
template <typename T>
void saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    // Сохранение массивов
    for (const auto& [name, array] : arrays) {
        for (int i = 0; i < array.size; ++i) {
            file << name << " " << array.array[i] << endl;
        }
    }

    // Сохранение связных списков
    for (const auto& [name, linked_list] : linked_lists) {
        Node<string>* current = linked_list.head;
        while (current != nullptr) {
            file << name << " " << current->data << endl;
            current = current->next;
        }
    }

        // Сохранение двусвязных списков
    for (const auto& [name, doubly_list] : doubly_lists) {
        Node<string>* currentDoubly = doubly_list.head;
        while (currentDoubly != nullptr) {
            file << name << " " << currentDoubly->data << endl;
            currentDoubly = currentDoubly->next;
        }
    }

    // Сохранение очередей
    for (const auto& [name, queue] : queues) {
        Node<string>* currentQueue = queue.head;
        while (currentQueue != nullptr) {
            file << name << endl; // Просто указываем имя очереди, так как QPOP удаляет элемент
            currentQueue = currentQueue->next;
        }
    }

    // Сохранение стеков
    for (const auto& [name, stack] : stacks) {
        Node<string>* currentStack = stack.head;
        while (currentStack != nullptr) {
            file << name << " " << currentStack->data << endl;
            currentStack = currentStack->next;
        }
    }

    // Сохранение хэш-таблиц
    /*for (const auto& [name, hash_table] : hash_tables) {
        for (int i = 0; i < 1000; ++i) {
            Hash_node<string, string>* item = hash_table.table[i];
            while (item != nullptr) {
                file << name << " " << item->key << " " << item->value << endl;
                item = item->next;
            }
        }
    }*/

        // Сохранение деревьев
    for (const auto& [name, tree] : trees) {
        // TODO: реализовать сохранение дерева
    }

    file.close();
}

int main(int argc, char* argv[]) {
    system("chcp 65001");
    string filename;

    // Обработка аргументов командной строки
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--file") {
            if (i + 1 < argc) {
                filename = argv[++i];
            }
        }
    }

    // Загружаем данные из файла
    if (!filename.empty()) {
        loadFromFile(filename);
    }

    // Интерактивный ввод команд
    string query;
    cout << "Введите команды (или 'exit' для выхода):" << endl;
    while (true) {
        cout << "> ";
        getline(cin, query);
        if (query == "exit") {
            break; // Выход из цикла
        }
        processQuery(query);
    }

    // Сохраняем данные обратно в файл
    if (!filename.empty()) {
        saveToFile<string>(filename);
    }

    return 0;
}