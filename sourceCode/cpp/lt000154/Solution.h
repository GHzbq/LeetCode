//
// Created by zhangbaqing on 2021/4/9.
//
// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

class Solution {
public:
    int findMin(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int left = 0, right = size - 1, mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                --right;
            }
        }
        return nums[left];
    }
};

#endif

#if false
class Solution {
public:
    int findMin(vector<int>& nums) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
