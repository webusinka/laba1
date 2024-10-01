#pragma once
#include "tree_node.hpp"

template <typename Data>
class AVLTree { 
private: 
    tree_node* root; 
public: 
    AVLTree(){ 
        root = nullptr; 
    } 
    tree_node* insert(tree_node* _node, Data data){ // вставка ключа data в дерево с корнем _node
        if( _node == nullptr ) return new tree_node(data); //создание корня
        if( data < _node->key )
            _node->left = insert(_node->left, data);
        else
            _node->right = insert(_node->right, data);
        return balance(_node);
    }
    tree_node* find(tree_node* _node, Data data){
        if(_node == nullptr) return nullptr;
        if(data < _node->key)
            return find(_node->left, data);
        else if(data > _node->key)
            return find(_node->right, data);
        else
            return _node;
    }
    tree_node* find_min_data(tree_node* _node){ // поиск узла с минимальным значением в узле 
        return _node->left ? find_min_data( _node->left ) : _node;
    }
    tree_node* remove_min_data(tree_node* _node){ // удаление узла с минимальным значением из узла
        if( _node->left==0 )
            return _node->right;
        _node->left = remove_min_data(_node->left);
        return balance(_node);
    }
    tree_node* remove(tree_node* _node, Data data){ // удаление значения Data из узла _node
        if( _node == nullptr ) return 0;
        if( data < _node->key )
            _node->left = remove(_node->left, data);
        else if( data > _node->key )
            _node->right = remove(_node->right, data);	
        else{ //  data == _node->key 
            tree_node* node_left = _node->left;
            tree_node* node_right = _node->right;
            delete _node;
            if( node_right ==nullptr ) return node_left;
            tree_node* min = find_min_data(node_right);
            min->right = remove_min_data(node_right);
            min->left = node_left;
            return balance(min);
        }
        return balance(_node);
    }
};