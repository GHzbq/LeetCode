//
// Created by zhangbaqing on 2021/3/28.
//
// https://leetcode-cn.com/problems/unique-binary-search-trees/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

/**
 * 解法一：
 * 思路：
 * */
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};

#endif

#if false
class Solution {
public:
    int numTrees(int n) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
