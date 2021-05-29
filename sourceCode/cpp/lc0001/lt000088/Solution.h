//
// Created by zhangbaqing on 2021/4/5.
//
// https://leetcode-cn.com/problems/merge-sorted-array/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        // 从后往前放数据！！
        int posM = m - 1, posN = n - 1, first = 0, second = 0;
        for (int i = m + n - 1; i >= 0; --i) {
            first = posM < 0 ? INT_MIN : nums1[posM];
            second = posN < 0 ? INT_MIN : nums2[posN];
            if (first < second) {
                --posN;
                nums1[i] = second;
            } else {
                --posM;
                nums1[i] = first;
            }
        }
    }
};

#endif //LEETCODE_SOLUTION_H
