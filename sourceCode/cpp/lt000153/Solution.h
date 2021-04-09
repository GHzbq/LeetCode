//
// Created by zhangbaqing on 2021/4/8.
//
// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>
#include <climits>

using std::vector;

#if true

class Solution {
public:
    int findMin(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int left = 0, right = size - 1, mid = 0, minNumber = INT_MAX;
        while (left <= right) {
            mid = left + (right - left) / 2;
            minNumber = std::min(minNumber, nums[mid]);
            // 注意判断条件的等号！！！
            if (nums[left] <= nums[mid]) {
                minNumber = std::min(minNumber, nums[left]);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return minNumber;
    }
};

#endif

#if false

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                // 这种情况，说明nums[mid]是最小值右侧元素，应当舍弃右子序列
                right = mid;
            } else {
                // 这种情况，说明nums[mid]是最小值左侧元素，应当舍弃左子序列
                left = mid + 1;
            }
        }
        // 此时left标记的就是最小元素位置的元素
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
