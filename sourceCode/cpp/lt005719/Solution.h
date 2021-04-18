//
// Created by zhangbaqing on 2021/4/17.
//
// 5719.每个查询的最大异或值
// https://leetcode-cn.com/problems/maximum-xor-for-each-query/
// 难度：中等

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

// 最大化的结果就是 k xor num = 2^maximumBit -1
// 求出k，即可
//
class Solution {
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        int n = nums.size();
        if (n <= 0) {
            return nums;
        }
        std::vector<int> tmp(n);
        int num = nums[0];
        int index = n - 1;
        tmp[index] = num;
        for (int i = 1; i < n; ++i) {
            num ^= nums[i];
            tmp[--index] = num;
        }
        int maximumNum = (1 << maximumBit) - 1;
        for (int i = 0; i < n; ++i) {
            tmp[i] ^= maximumNum;
        }
        return tmp;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
