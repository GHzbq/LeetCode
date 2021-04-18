//
// Created by zhangbaqing on 2021/4/17.
//
// 5717.最少操作使数组递增
// https://leetcode-cn.com/problems/minimum-operations-to-make-the-array-increasing/
// 难度：easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int count = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] >= nums[i]) {
                count += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return count;
    }
};

#endif

#if false
class Solution {
public:
    int minOperations(vector<int>& nums) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
