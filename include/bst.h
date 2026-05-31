// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>

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

    BST() : root(nullptr) {}

    // Вставка или увеличение счётчика
    void insert(const T& key) {
        Node** cur = &root;
        while (*cur) {
            if (key < (*cur)->key) {
                cur = &((*cur)->left);
            } else if (key > (*cur)->key) {
                cur = &((*cur)->right);
            } else {
                (*cur)->count++;
                return;
            }
        }
        *cur = new Node(key);
    }

    // Поиск ключа и возврат Node (нужен для тестов)
    Node* search(const T& key) const {
        Node* cur = root;
        while (cur) {
            if (key < cur->key) {
                cur = cur->left;
            } else if (key > cur->key) {
                cur = cur->right;
            } else {
                return cur;
            }
        }
        return nullptr;
    }

    // Высота дерева
    int depth() const {
        return depth(root);
    }

    // Сбор узлов в порядке возрастания ключей
    void inorder(std::vector<Node*>& nodes) const {
        inorder(root, nodes);
    }

    ~BST() {
        clear(root);
    }

 private:
    Node* root;

    int depth(Node* node) const {
        if (!node) return 0;
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }

    void inorder(Node* node, std::vector<Node*>& nodes) const {
        if (!node) return;
        inorder(node->left, nodes);
        nodes.push_back(node);
        inorder(node->right, nodes);
    }

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
};
#endif  // INCLUDE_BST_H_
