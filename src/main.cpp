// Copyright 2022 NNTU-CS
#include "tree.h"
#include <chrono>
#include <random>
#include <iostream>
#include <vector>

int main() {
  std::vector<char> in = {'1', '2', '3'};
  PMTree tree(in);

  auto all = getAllPerms(tree);
  std::cout << "All perms (" << all.size() << "):\n";
  for (const auto& p : all) {
    for (char c : p) std::cout << c;
    std::cout << '\n';
  }

  std::cout << "getPerm1 #2: ";
  for (char c : getPerm1(tree, 2)) std::cout << c;
  std::cout << '\n';

  std::cout << "getPerm2 #2: ";
  for (char c : getPerm2(tree, 2)) std::cout << c;
  std::cout << '\n';

  std::mt19937_64 rng(12345);
  std::uniform_int_distribution<int64_t> dist(1, 1'000'000);

  for (int n = 5; n <= 10; ++n) {
    std::vector<char> v(n);
    for (int i = 0; i < n; ++i) {
      v[i] = static_cast<char>('A' + i);
    }
    PMTree t(v);
    int num = static_cast<int>(dist(rng));

    auto start = std::chrono::high_resolution_clock::now();
    (void)getAllPerms(t);
    auto mid1  = std::chrono::high_resolution_clock::now();
    (void)getPerm1(t, num);
    auto mid2  = std::chrono::high_resolution_clock::now();
    (void)getPerm2(t, num);
    auto end   = std::chrono::high_resolution_clock::now();

    double dtAll  = std::chrono::duration<double>(mid1 - start).count();
    double dt1    = std::chrono::duration<double>(mid2 - mid1 ).count();
    double dt2    = std::chrono::duration<double>(end  - mid2 ).count();

    std::cout << "n=" << n
              << ", AllPerms=" << dtAll
              << ", Perm1="    << dt1
              << ", Perm2="    << dt2
              << '\n';
  }

  return 0;
}
