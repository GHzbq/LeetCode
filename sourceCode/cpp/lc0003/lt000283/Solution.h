//
// Created by zhangbaqing on 2020/11/19.
//
// https://leetcode-cn.com/problems/move-zeroes/
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

#if 0

// 解法一：先放置非0，末尾补0
class Solution {
public:
    void moveZeroes(std::vector<int> &nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        for (int i = index; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

#endif

#if 1

// 解法二：双指针交换
//       left指针指向已处理数字序列末尾，
//       right指针指向未处理数字序列开头
class Solution {
public:
    void moveZeroes(std::vector<int> &nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right] != 0) {
                std::swap(nums[left++], nums[right]);
            }
            ++right;
        }
    }
};

#endif

#if 0
// 默认代码模板
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
