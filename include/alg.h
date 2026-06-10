#ifndef ALG_H_
#define ALG_H_

#include "bst.h"
#include <string>

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

#endif  // ALG_H_
