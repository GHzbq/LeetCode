//
// Created by zhangbaqing on 2021/4/2.
//
// https://leetcode-cn.com/problems/volume-of-histogram-lcci/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>

#if true

class Solution {
public:
    int trap(std::vector<int> &height) {
        if (height.empty() || height.size() <= 1) {
            return 0;
        }
        int size = height.size();
        auto leftMax = std::vector<int>(size, 0);
        auto rightMax = std::vector<int>(size, 0);
        leftMax[0] = height[0];
        for (int i = 1; i < size; ++i) {
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }
        rightMax[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            rightMax[i] = std::max(height[i], rightMax[i + 1]);
        }
        int result = 0;
        for (int i = 0; i < size; ++i) {
            result += std::min(leftMax[i], rightMax[i]) - height[i];
        }
        return result;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
