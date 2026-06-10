// Copyright 2021 NNTU-CS
#ifndef BST_H_
#define BST_H_

#include <string>
#include <vector>

template<typename T>
class BST {
public:
    struct Node {
        T key;
        int count;
        Node* left;
        Node* right;
        Node(const T& k) : key(k), count(1), left(nullptr), right(nullptr) {}
    };

private:
    Node* root;

    void insert(Node*& node, const T& key) {
        if (node == nullptr) {
            node = new Node(key);
        } else if (key < node->key) {
            insert(node->left, key);
        } else if (key > node->key) {
            insert(node->right, key);
        } else {
            node->count++;
        }
    }

    void inorder(Node* node, std::vector<Node*>& nodes) const {
        if (node != nullptr) {
            inorder(node->left, nodes);
            nodes.push_back(node);
            inorder(node->right, nodes);
        }
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }

    void insert(const T& key) {
        insert(root, key);
    }

    void inorder(std::vector<Node*>& nodes) const {
        inorder(root, nodes);
    }
};

#endif  // BST_H_
