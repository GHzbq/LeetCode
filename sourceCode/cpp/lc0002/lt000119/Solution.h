//
// Created by zhangbaqing on 2021/5/21.
//
// 119.杨辉三角II
// https://leetcode-cn.com/problems/pascals-triangle-ii/
// easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

// 3
// [1],
// [1,1],
// [1,2,1],
// [1,3,3,1],  => 返回该行
// [1,4,6,4,1]
// 题目要求在O(k)空间复杂度解决，那么就得考虑滚动数组了
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> result(rowIndex + 1, 1);
        if (rowIndex < 2) {
            return result;
        }

        int pre = 0, sum = 0;
        for (int i = 2; i <= rowIndex; ++i) {
            pre = 1;
            for (int j = 1; j < i; ++j) {
                sum = pre;
                pre = result[j];
                result[j] += sum;
            }
        }

        return result;
    }
};

#endif

#if false
class Solution {
public:
    vector<int> getRow(int rowIndex) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
