//
// Created by zhangbaqing on 2020/11/10.
//
// https://leetcode-cn.com/problems/next-permutation/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int> &nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};

#endif //LEETCODE_SOLUTION_H
