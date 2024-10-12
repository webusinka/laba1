#include <iostream>
#include <fstream>

#include "tree_node.hpp"

template <typename Data>
class AVLTree { 
public: 
    tree_node<Data>* root; // корень дерева
    AVLTree(){ 
        root = nullptr;         
    } 
    ~AVLTree(){
        delete root;
    }
    void create_root(Data data) {
        root = new tree_node<Data>(data);
    }
    tree_node<Data>* insert(tree_node<Data>* _node, Data data){ // вставка ключа data в дерево с корнем _node
        if( _node == nullptr ) return new tree_node<Data>(data); //создание корня
        if( data < _node->data )
            _node->left = insert(_node->left, data);
        else
            _node->right = insert(_node->right, data);
        return root->balance(_node);
    }
    tree_node<Data>* find(tree_node<Data>* _node, Data data){
        if(_node == nullptr) return nullptr;
        if(data < _node->data)
            return find(_node->left, data);
        else if(data > _node->data)
            return find(_node->right, data);
        else
            return _node;
    }
    tree_node<Data>* find_min_data(tree_node<Data>* _node){ // поиск узла с минимальным значением в узле 
        return _node->left ? find_min_data( _node->left ) : _node;
    }
    tree_node<Data>* remove_min_data(tree_node<Data>* _node){ // удаление узла с минимальным значением из узла
        if( _node->left==0 )
            return _node->right;
        _node->left = remove_min_data(_node->left);
        return root->balance(_node);
    }
    tree_node<Data>* remove(tree_node<Data>* _node, Data data){ // удаление значения Data из узла _node
        if( _node == nullptr ) return 0;
        if( data < _node->data )
            _node->left = remove(_node->left, data);
        else if( data > _node->data )
            _node->right = remove(_node->right, data);	
        else{
            tree_node<Data>* node_left = _node->left;
            tree_node<Data>* node_right = _node->right;
            delete _node;
            if( node_right ==nullptr ) return node_left;
            tree_node<Data>* min = find_min_data(node_right);
            min->right = remove_min_data(node_right);
            min->left = node_left;
            if (_node == root) {
                root = min;
            }
            return min;
        }
        return _node;
    }
    void display(tree_node<Data>* node) {
        if (node == nullptr) return;
            std::cout << node->data << " ";
        printTree(node->left);
        printTree(node->right);
    }

    void load_from_file(std::string filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                insert(line);
            }
            file.close();
        }
    }

    void save_from_file(std::string filename) {
        std::ofstream fout(filename);
        if (fout.is_open()) {
            save_to_file(fout, root);
            fout.close();
        }
    }

    void save_to_file(std::ofstream& fout, tree_node<Data>* node) {
        if (node == nullptr) return;
        save_to_file(fout, node->left);
        fout << node->data << " ";
        save_to_file(fout, node->right);
    }
};