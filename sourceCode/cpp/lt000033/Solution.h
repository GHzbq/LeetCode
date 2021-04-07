//
// Created by zhangbaqing on 2021/4/7.
//
// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
            s
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int left = 0, right = size - 1, mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 这里的等号非常关键，mid极有可能与left相等
            // 考虑nums = [3, 1]的情况
            // 第一次二分, left = 0, mid = 0, right = 1
            if (nums[left] <= nums[mid]) {
                // 左子序列有序
                if ((nums[left] <= target) && (target < nums[mid])) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if ((nums[mid] < target) && (target <= nums[right])) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

#endif

#if false
class Solution {
public:
    int search(vector<int>& nums, int target) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
