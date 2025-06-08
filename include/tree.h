// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#pragma once
#include <vector>
#include <algorithm>

class PMTree {
public:
    using Elem = char;

    explicit PMTree(const std::vector<Elem>& in)
        : alphabet(in) {
        std::sort(alphabet.begin(), alphabet.end());
    }

    const std::vector<Elem>& getAlphabet() const {
        return alphabet;
    }

private:
    std::vector<Elem> alphabet;
};

std::vector<std::vector<PMTree::Elem>> getAllPerms(const PMTree& tree);

std::vector<PMTree::Elem> getPerm1(const PMTree& tree, int num);

std::vector<PMTree::Elem> getPerm2(const PMTree& tree, int num);

#endif  // INCLUDE_TREE_H_
