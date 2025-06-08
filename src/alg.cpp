// Copyright 2022 NNTU-CS
#include "tree.h"

#include <cstdint>
#include <vector>
#include <algorithm>

static void buildAll(const std::vector<char>& available,
    std::vector<char>& path,
    std::vector<std::vector<char>>& out) {
    if (available.empty()) {
        out.push_back(path);
        return;
    }
    for (size_t i = 0; i < available.size(); ++i) {
        auto next = available;
        char c = next[i];
        next.erase(next.begin() + i);
        path.push_back(c);
        buildAll(next, path, out);
        path.pop_back();
    }
}

std::vector<std::vector<PMTree::Elem>> getAllPerms(const PMTree& tree) {
    std::vector<std::vector<char>> result;
    std::vector<char> path;
    buildAll(tree.getAlphabet(), path, result);
    return result;
}

std::vector<PMTree::Elem> getPerm1(const PMTree& tree, int num) {
    auto all = getAllPerms(tree);
    if (num < 1 || num > static_cast<int>(all.size())) {
        return {};
    }
    return all[num - 1];
}

std::vector<PMTree::Elem> getPerm2(const PMTree& tree, int num) {
    const auto& A = tree.getAlphabet();
    int n = static_cast<int>(A.size());
    int64_t fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    if (num < 1 || num > fact) {
        return {};
    }
    --num;

    std::vector<char> available = A;
    std::vector<char> result;
    result.reserve(n);

    for (int k = n; k >= 1; --k) {
        fact /= k;
        int idx = num / fact;
        result.push_back(available[idx]);
        available.erase(available.begin() + idx);
        num %= fact;
    }
    return result;
}
