//
// Created by zhangbaqing on 2021/4/6.
//
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

// 注意审题!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 看清楚返回值是什么！！！
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        int s = 1, f = 1, pre = nums[0], count = 1;
        for (; f < size; ++f) {
            if (pre == nums[f]) {
                ++count;
                if (count > 2) {
                    continue;
                }
            } else {
                pre = nums[f];
                count = 1;
            }
            nums[s++] = nums[f];
        }
        nums.resize(s);
        return nums.size();
    }
};

#endif

#if false
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
