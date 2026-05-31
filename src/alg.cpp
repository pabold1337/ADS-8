// Copyright 2021 NNTU-CS
#include "bst.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include <vector>

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string word;
    char ch;
    while (file.get(ch)) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            word += std::tolower(static_cast<unsigned char>(ch));
        } else {
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        tree.insert(word);
    }
    file.close();
}

void printFreq(BST<std::string>& tree) {
    std::vector<BST<std::string>::Node*> nodes;
    tree.inorder(nodes);

    std::sort(nodes.begin(), nodes.end(),
        [](const BST<std::string>::Node* a, const BST<std::string>::Node* b) {
            return a->count > b->count;
        });

    std::ofstream outFile("result/freq.txt");
    if (!outFile.is_open()) return;

    for (const auto& node : nodes) {
        std::cout << node->key << ": " << node->count << std::endl;
        outFile << node->key << ": " << node->count << std::endl;
    }
    outFile.close();
}
