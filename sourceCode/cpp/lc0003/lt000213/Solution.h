//
// Created by zhangbaqing on 2021/4/15.
//
// 213.打家劫舍II
// https://leetcode-cn.com/problems/house-robber-ii/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>

using std::vector;

#if true

class Solution {
private:
    int robRange(const vector<int> &nums, int start, int end) {
        int first = nums[start], second = std::max(first, nums[start + 1]), tmp = 0;
        for (int i = start + 2; i <= end; ++i) {
            tmp = second;
            second = std::max(second, first + nums[i]);
            first = tmp;
        }
        return second;
    }

public:
    int rob(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        } else if (size == 2) {
            return std::max(nums[0], nums[1]);
        }
        return std::max(robRange(nums, 0, size - 2), robRange(nums, 1, size - 1));
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
