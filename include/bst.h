// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H__
#define INCLUDE_BST_H__

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
    explicit Node(const T& k) : key(k), count(1), left(nullptr), right(nullptr) {}
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

  int depth(Node* node) const {
    if (node == nullptr) return 0;
    int leftDepth = depth(node->left);
    int rightDepth = depth(node->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
  }

  int search(Node* node, const T& key) const {
    if (node == nullptr) return 0;
    if (key == node->key) return node->count;
    if (key < node->key) return search(node->left, key);
    return search(node->right, key);
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

  int depth() const {
    return depth(root);
  }

  int search(const T& key) const {
    return search(root, key);
  }
};

#endif  // INCLUDE_BST_H__
