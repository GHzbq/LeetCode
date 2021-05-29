//
// Created by zhangbaqing on 2021/4/15.
//
// 198 打家劫舍
// https://leetcode-cn.com/problems/house-robber/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>

using std::vector;

#if true

class Solution {
public:
    int rob(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        } else if (size == 2) {
            return std::max(nums[0], nums[1]);
        }
        int first = nums[0], second = std::max(first, nums[1]), tmp = 0;
        for (int i = 2; i < size; ++i) {
            tmp = second;
            second = std::max(second, first + nums[i]);
            first = tmp;
        }
        return second;
    }
};

#endif

#if false
class Solution {
public:
    int rob(vector<int>& nums) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
