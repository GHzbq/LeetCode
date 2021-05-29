//
// Created by zhangbaqing on 2020/11/27.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <unordered_set>

#if 1

// 解法一：暴力枚举
//   虽然我知道会时间超限，但是我还是想试试
class Solution {
public:
    int fourSumCount(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C, std::vector<int> &D) {
        auto dSet = std::unordered_multiset<int>();
        for (auto num : D) {
            dSet.insert(num);
        }
        int pairCount = 0;
        int num = 0;
        for (auto a : A) {
            for (auto b : B) {
                for (auto c : C) {
                    num = 0 - a + b + c;
                    if (dSet.find(num) != dSet.end()) {
                        ++pairCount;
                    }
                }
            }
        }
        return pairCount;
    }
};

#endif

#if 0
// 默认代码模板
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
