// Copyright 2022 NNTU-CS
#include "tree.h"
#include <iostream>
#include <string>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
	BST<std::string> tree;
	const char* filename = "src/war_peace.txt";
	makeTree(tree, filename);

	printFreq(tree);
	return 0;
}


int main() {
  return 0;
}
