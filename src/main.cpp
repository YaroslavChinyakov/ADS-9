// Copyright 2022 NNTU-CS
#include "tree.h"
#include <string>
#include <iostream>
#include <chrono>
#include <random>


int main() {
    std::vector<char> in = { '1','2','3' };
    PMTree tree(in);

    auto all = getAllPerms(tree);
    std::cout << "All perms (" << all.size() << "):\n";
    for (auto& p : all) {
        for (char c : p) std::cout << c;
        std::cout << "\n";
    }

    std::cout << "getPerm1 #2: ";
    for (char c : getPerm1(tree, 2)) std::cout << c;
    std::cout << "\n";
    std::cout << "getPerm2 #2: ";
    for (char c : getPerm2(tree, 2)) std::cout << c;
    std::cout << "\n";

    std::mt19937_64 rng(12345);
    for (int n = 5; n <= 10; ++n) {
        std::vector<char> v(n);
        for (int i = 0; i < n; ++i) v[i] = 'A' + i;
        PMTree t(v);
        int num = std::uniform_int_distribution<int>(1, 1'000'000)(rng);

        auto start = std::chrono::high_resolution_clock::now();
        (void)getAllPerms(t);
        auto mid = std::chrono::high_resolution_clock::now();
        (void)getPerm1(t, num);
        auto mid2 = std::chrono::high_resolution_clock::now();
        (void)getPerm2(t, num);
        auto end = std::chrono::high_resolution_clock::now();

        auto dtAll = std::chrono::duration<double>(mid - start).count();
        auto dt1 = std::chrono::duration<double>(mid2 - mid).count();
        auto dt2 = std::chrono::duration<double>(end - mid2).count();

        std::cout << "n=" << n
            << " AllPerms=" << dtAll
            << " Perm1=" << dt1
            << " Perm2=" << dt2 << "\n";
    }
    return 0;
}

