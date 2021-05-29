//
// Created by zhangbaqing on 2021/4/16.
//
// offer 11 旋转数组的最小数字
// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

// 二分
class Solution {
public:
    int minArray(vector<int> &numbers) {
        int size = numbers.size();
        if (size == 1) {
            return numbers[0];
        }
        int left = 0, right = size - 1, mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (numbers[mid] < numbers[right]) {
                right = mid;
            } else if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else {
                --right;
            }
        }
        return numbers[left];
    }
};

#endif

#if false
class Solution {
public:
    int minArray(vector<int>& numbers) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
