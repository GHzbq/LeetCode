//
// Created by zhangbaqing on 2021/4/7.
//
// https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;
#if true

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return false;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0] == target ? true : false;
        }
        int left = 0, right = size - 1, mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return true;
            }
            if ((nums[left] == nums[mid]) && (nums[mid] == nums[right])) {
                ++left;
                --right;
            } else if (nums[left] <= nums[mid]) {
                // 左子序列是有序的
                if ((nums[left] <= target) && (target < nums[mid])) {
                    // target 可能在左子序列中
                    right = mid - 1;
                } else {
                    // 在右子序列中查找
                    left = mid + 1;
                }
            } else {
                // 右子序列是有序的
                if ((nums[mid] < target) && (target <= nums[right])) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

#endif

#if false
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (auto& item : nums) {
            if (item == target) {
                return true;
            }
        }
        return false;
    }
};
#endif
#endif //LEETCODE_SOLUTION_H
