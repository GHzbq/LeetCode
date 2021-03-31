//
// Created by zhangbaqing on 2021/3/31.
//
// https://leetcode-cn.com/problems/subsets-ii/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;

#if true

/**
 * 解法一：
 * 思路：排列组合试试
 *      不考虑相同集合的情况，应该有2^n种排列组合方式(每个元素都有可能出现，或者不出现的机会)
 *      但是考虑到会有相同元素！！！
 *      我们对nums排个序，如果上一个元素没被选择，且当前元素等于上一个元素，跳过本轮；
 *
 * 诶呀，飘了飘了，耗时0ms，打败100%
 * */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        if (nums.empty()) {
            return {{}};
        }
        std::sort(nums.begin(), nums.end());
        auto result = std::vector<std::vector<int>>();
        auto vec = std::vector<int>();
        int size = nums.size();
        bool flag = true;
        for (int mask = 0; mask < (1 << size); ++mask) {
            vec.clear();
            flag = true;
            for (int i = 0; i < size; ++i) {
                if (mask & (1 << i)) {
                    // 上一个元素没有被选中，并且当前元素与上一个元素相等
                    if (i > 0 && (((mask >> (i - 1)) & 1) == 0) && (nums[i] == nums[i - 1])) {
                        flag = false;
                        break;
                    }
                    vec.emplace_back(nums[i]);
                }
            }
            if (flag) {
                result.emplace_back(vec.begin(), vec.end());
            }
        }
        return result;
    }
};

#endif

#if false
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
