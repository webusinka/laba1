#pragma once

template <typename Data>
class tree_node {
public: 
    Data data; 
    tree_node* left; //далее p - правый узел, q - левый
    tree_node* right;
    unsigned char height;

    tree_node(Data _data) { data = _data; left = right = 0; height = 1; }

    ~tree_node() { delete left; delete right; }
    unsigned char height(tree_node* _node) {
        return (_node == nullptr) ? 0 : _node->height;
    }

    int balance_factor(tree_node* _node) {
        return height(_node->right) - height(_node->left);
    }

    void fix_height(node* _node) {
        unsigned char height_left = height(_node->left);
        unsigned char height_right = height(_node->right);
        _node->height = (height_left > height_right ? height_left : height_right) + 1;
    }
    tree_node* rotate_right(tree_node* _node){ // правый поворот вокруг p
        tree_node* node_left = _node->left;
        _node->left = node_left->right;
        node_left->right = _node;
        fix_height(_node);
        fix_height(node_left);
        return node_left;
    }
    tree_node* rotate_left(tree_node* _node){ // левый поворот вокруг q
        tree_node* node_right = _node->right;
        _node->right = node_right->left;
        node_right->left = _node;
        fix_height(_node);
        fix_height(node_right);
        return node_right;
    }
    node* balance(node* _node){ // балансировка узла p
        fix_height(_node);
        if( balance_factor(_node) == 2 ) {      //правый больше левого
            if( balance_factor( _node->right ) < 0 )
                _node->right = rotate_right( _node->right );
            return rotate_left(_node);
        }
        if( balance_factor(_node) == -2 ) {
            if( balance_factor(_node->left) > 0 )
                _node->left = rotate_left(_node->left);
            return rotate_right(_node);
        }
        return _node; // балансировка не нужна
    }
};