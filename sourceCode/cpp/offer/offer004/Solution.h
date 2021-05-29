//
// Created by zhangbaqing on 2021/4/13.
//
// 剑指offer04 二维数组中的查找
// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>

using std::vector;

#if false
// 遍历
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for (const auto& vec : matrix) {
            for (const auto& item : vec) {
                if (item == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
#endif

#if false

// 二分
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        for (const auto &vec : matrix) {
            auto ret = std::binary_search(vec.begin(), vec.end(), target);
            if (ret) {
                return true;
            }
        }
        return false;
    }
};

#endif

#if true

// 从右上角开始，往左下角寻找
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};

#endif

#if false
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
