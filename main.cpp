#include <iostream>
#include <string>
#include <sstream>

#include "Node.hpp"
#include "Array.hpp"
#include "List.hpp"
//#include "Queue.hpp"
//#include "Stack.hpp"
//#include "HashTable.hpp"
//#include "AVL_tree.hpp"

using namespace std;

Array<string> arrays;
LinkedList<string> linked_lists;
DoublyList<string> doubly_lists;
//Queue<string> queues;
//Stack<string> stacks;
//Hash_map<string, string, 1000> hash_tables;
//AVLTree<int> trees;

void process_query(const string& query) {
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
        string value;
        ss >> value;
        arrays.push_back(value);
        arrays.save_to_file("array.txt");
    }
    else if (command == "APUSH_FRONT"){ // добавление элемента в начало
        arrays.load_from_file("array.txt");
        string value;
        ss >> value;
        arrays.push_front(value);
        arrays.save_to_file("array.txt");
    }
    else if (command == "AINSERT"){ // добавление элемента по индексу
        arrays.load_from_file("array.txt");
        string value;
        int index;
        ss >> index >> value;
        arrays.push_in(index, value);
        arrays.save_to_file("array.txt");
    }
    else if (command == "APOP"){ // удаление элемента по индексу
        arrays.load_from_file("array.txt");
        int index;
        ss >> index;
        arrays.pop_in(index);
        arrays.save_to_file("array.txt");
    }
    else if (command == "APOP_FRONT"){ // удаление элемента из начала
        arrays.load_from_file("array.txt");
        arrays.pop_front();
        arrays.save_to_file("array.txt");
    }
    else if (command == "APOP_BACK"){ // удаление по индексу
        arrays.load_from_file("array.txt");
        arrays.pop_back();
        arrays.save_to_file("array.txt");
    }
    else if (command == "AGET"){ // получение элемента по индексу - search_index
        int index;
        ss >> index;
        arrays.search_index(index);
    }
    else if (command == "ASEARCH"){ // есть ли элемент по индексу 
        string value;
        ss >> value;
        arrays.search(value);
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
        linked_lists.load_from_file("linked_list.txt");
        string value;
        ss >> value;
        linked_lists.push_front(value);
        linked_lists.save_to_file("linked_list.txt");
    }
    else if (command == "LPUSH_TAIL"){ // добавление элемента в хвост
        linked_lists.load_from_file("linked_list.txt");
        string value;
        ss >> value;
        linked_lists.push_back(value);
        linked_lists.save_to_file("linked_list.txt");
    }
    else if (command == "LINSERT"){ // добавление элемента по индексу
        linked_lists.load_from_file("linked_list.txt");
        string value;
        int index;
        ss >> index >> value;
        linked_lists.insert(index, value);
        linked_lists.save_to_file("linked_list.txt");
    }
    else if (command == "LPOP_HEAD"){ // удаление элемента с головы
        linked_lists.load_from_file("linked_list.txt");
        linked_lists.pop_head();
        linked_lists.save_to_file("linked_list.txt");
    }
    else if (command == "LPOP_TAIL"){ // удаление элемента с хвоста
        linked_lists.load_from_file("linked_list.txt");
        linked_lists.pop_tail();
        linked_lists.save_to_file("linked_list.txt");
    }
    else if (command == "LPOP"){ // удаление элемента с хвоста
        linked_lists.load_from_file("linked_list.txt");
        int index;
        ss >>  index;
        linked_lists.pop(index);
        linked_lists.save_to_file("linked_list.txt");
    }
    else if (command == "LPOP_VALUE"){ // удаление элемента по значению
        linked_lists.load_from_file("linked_list.txt");
        string value;
        ss >> value;
        linked_lists.pop_value(value);
        linked_lists.save_to_file("linked_list.txt");
    }
    else if (command == "LSEARCH"){ // поиск элемента по значению
        string value;
        ss >> value;
        linked_lists.search(value);
    }
    else if (command == "LPRINT"){ // вывод на экран
        linked_lists.load_from_file("linked_list.txt");
        linked_lists.display();
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
        doubly_lists.load_from_file("doubly_list.txt");
        string value;
        ss >> value;
        doubly_lists.push_front(value);
        doubly_lists.save_to_file("doubly_list.txt");
    }
    else if (command == "2LPUSH_TAIL"){ // добавление элемента в хвост
        doubly_lists.load_from_file("doubly_list.txt");
        string value;
        ss >> value;
        doubly_lists.push_back(value);
        doubly_lists.save_to_file("doubly_list.txt");
    }
    else if (command == "2LINSERT"){ // добавление элемента в хвост
        doubly_lists.load_from_file("doubly_list.txt");
        string value;
        int index;
        ss >> index >> value;
        doubly_lists.push_in(index, value);
        doubly_lists.save_to_file("doubly_list.txt");
    }
    else if (command == "2LPOP_HEAD"){ // удаление элемента с головы
        doubly_lists.load_from_file("doubly_list.txt");
        doubly_lists.pop_forward();
        doubly_lists.save_to_file("doubly_list.txt");
    }
    else if (command == "2LPOP_TAIL"){ // удаление элемента с хвоста
        doubly_lists.load_from_file("doubly_list.txt");
        doubly_lists.pop_backward();
        doubly_lists.save_to_file("doubly_list.txt");
    }
    else if (command == "2LPOP"){ // удаление элемента по индексу
        doubly_lists.load_from_file("doubly_list.txt");
        int index;
        ss >>index;
        doubly_lists.pop(index);
        doubly_lists.save_to_file("doubly_list.txt");
    }
    else if (command == "2LPOP_VALUE"){ // удаление элемента по значению
        doubly_lists.load_from_file("doubly_list.txt");
        string value;
        ss >> value;
        doubly_lists.pop_value(value);
        doubly_lists.save_to_file("doubly_list.txt");
    }
    else if (command == "2LSEARCH"){ // поиск элемента по значению
        string value;
        ss >> value;
        doubly_lists.search(value);
    }
    else if (command == "2LPRINT"){ // вывод на экран
        doubly_lists.load_from_file("doubly_list.txt");
        doubly_lists.display();
    }

    // ----------QUEUE-------
    // push(value) // добавление элемента
    // pop() // удаление с головы
    // search(value) // поиск элемента по значению
    /*else if (command == "QPUSH"){ // Добавление элемента
        queues.load_from_file("queue.txt");
        string value;
        ss >> value;
        queues.push(value);
        queues.save_to_file("queue.txt");
    }
    else if (command == "QPOP"){ // удаление элемента
        queues.load_from_file("queue.txt");
        queues.pop();
        queues.save_to_file("queue.txt");
    }
    else if (command == "QSEARCH"){ // поиск элемента
        string value;
        ss >> value;
        queues.search(value);
    }
    else if (command == "QPRINT"){ //вывод на экран
        queues.load_from_file("queue.txt");
        queues.display();
    }
    
    // ----------STACK-------
    // push(value) // добавление элемента
    // pop() // удаление с хвоста
    // search(value) // поиск элемента по значению
    else if (command == "SPUSH"){ // Добавление элемента
        stacks.load_from_file("stack.txt");
        string value;
        ss >> value;
        stacks.push(value);
        stacks.save_to_file("stack.txt");
    }
    else if (command == "SPOP"){ // удаление элемента
        stacks.load_from_file("stack.txt");
        stacks.pop();
        stacks.save_to_file("stack.txt");
    }
    else if (command == "SSEARCH"){ // поиск элемента
        string value;
        ss >> value;
        stacks.search(value);
    }
    else if (command == "SPRINT"){ //вывод на экран
        stacks.load_from_file("stack.txt");
        stacks.display();
    }

    // ----------HASH-TABLE-------
    // get_value(string key, string value)
    // insert(string key, string value)
    // remove(string key)
    else if (command == "HPUSH"){ // Добавление элемента
        hash_tables.load_from_file("hash_table.txt");
        string key, value;
        ss >> key >> value;
        hash_tables.insert(key, value);
        hash_tables.save_to_file("hash_table.txt");
    }
    else if (command == "HPOP"){ // Удаление элемента
        hash_tables.load_from_file("hash_table.txt");
        string key;
        ss >> key;
        hash_tables.remove(key);
        hash_tables.save_to_file("hash_table.txt");
    }
    else if (command == "HGET"){ // Получение значения по ключу
        string key, value;
        ss >> key >> value;
        hash_tables.get_value(key, value);
    }
    else if (command == "HPRINT"){ //Вывод на экран
        hash_tables.load_from_file("hash_table.txt");
        hash_tables.display();
    }

    // ----------TREE-------
    // create_root(int data) // создание корня
    // insert(tree_node<Data>* _node, int data) // вставка ключа data в дерево
    // find(tree_node<Data>* _node, int data) // поиск узла с нужным значением
    // remove(tree_node<Data>* _node, int data) // удаление узла с нужным значением
    // printTree(tree_node<Data>* node) // вывод дерева на экран
    else if (command == "TROOT"){
        int root;
        ss >> root;
        trees.create_root(root);
        trees.save_from_file("tree.txt");
    }
    else if (command == "TINSERT"){
        trees.load_from_file("tree.txt");
        int data;
        ss >> data;
        trees.insert(trees.root, data);
        trees.save_from_file("tree.txt");
    }
    else if (command == "TSEARCH"){
        int data;
        ss >> data;
        trees.find(trees.root, data);
    }
    else if (command == "TPOP"){
        trees.load_from_file("tree.txt");
        int data;
        ss >> data;
        trees.root = trees.remove(trees.root, data);
        trees.save_from_file("tree.txt");
    }
    else if (command == "TPRINT"){
        trees.load_from_file("tree.txt");
        trees.display(trees.root);
    }
    */
    else {
        cout << "Неизвестная команда " << endl;
    }
}

int main() {
    // Интерактивный ввод команд
    string query;
    cout << "Input the command ('EXIT'):" << endl;
    while (true) {
        cout << ">>> ";
        getline(cin, query);
        if (query == "EXIT") {
            break; // Выход из цикла
        }
        process_query(query);
    }
    return 0;
}