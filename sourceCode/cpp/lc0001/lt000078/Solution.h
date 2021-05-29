//
// Created by zhangbaqing on 2021/3/31.
//
// https://leetcode-cn.com/problems/subsets/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

/**
 * 解法一：
 * 思路： 已知nums是个集合，不会存在重复的元素，那么只需要排列组合即可
 *       对每个元素，都可以选择出现，或者不出现，所以将会有2^n种排列组合方式(其中，n为nums中元素个数)
 *       用程序来说，其实就是从0~2^n-1种
 *       用二进制表示 0000 ~ 1111 (假设n=4)
 * */
class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        if (nums.empty()) {
            return {{}};
        }
        auto result = std::vector<std::vector<int>>();
        auto tmp = std::vector<int>();
        int size = nums.size();
        for (int mask = 0; mask < (1 << size); ++mask) {
            tmp.clear();
            for (int i = 0; i < size; ++i) {
                if (mask & (1 << i)) {
                    tmp.emplace_back(nums[i]);
                }
            }
            result.emplace_back(tmp.begin(), tmp.end());
        }
        return result;
    }
};

#endif

#if false
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
