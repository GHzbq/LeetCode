//
// Created by zhangbaqing on 2021/4/30.
//
// 137. 只出现一次的数字II
// https://leetcode-cn.com/problems/single-number-ii/
// 难度：中等

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <unordered_map>

using std::vector;

#if true

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        // 最暴力的做法，我可以统计每个数字出现的次数
        std::unordered_map<int, int> m;
        for (auto num : nums) {
            ++m[num];
        }
        for (auto item : m) {
            if (item.second == 1) {
                return item.first;
            }
        }
        return 0;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
