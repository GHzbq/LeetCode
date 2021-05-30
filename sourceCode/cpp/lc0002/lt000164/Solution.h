//
// Created by zhangbaqing on 2020/11/26.
//
// https://leetcode-cn.com/problems/maximum-gap/


#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>

#if 1

class Solution {
public:
    int maximumGap(std::vector<int> &nums) {
        if (nums.empty() || nums.size() < 2) {
            return 0;
        }
        std::sort(nums.begin(), nums.end(), std::less<int>());


        int maxGap = nums[1] - nums[0];
        int gap = maxGap;
        for (int i = 2; i < nums.size(); ++i) {
            gap = nums[i] - nums[i - 1];
            maxGap = std::max(gap, maxGap);
        }
        return maxGap;
    }
};

#endif

#if 0
// 默认代码模板
class Solution {
public:
    int maximumGap(vector<int>& nums) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
