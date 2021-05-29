//
// Created by zhangbaqing on 2021/4/24.
//
// 剑指offer21. 调整数组顺序使奇数位于偶数前面
// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
// 难度: easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        // 前后指针
        if (nums.empty()) {
            return nums;
        }
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            // 从前往后找第一个偶数
            while ((start < end) && (nums[start] % 2 == 1)) ++start;
            while ((start < end) && (nums[end] % 2 == 0)) --end;
            if (start < end) {
                int tmp = nums[start];
                nums[start] = nums[end];
                nums[end] = tmp;
            }
        }
        return nums;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
