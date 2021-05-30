//
// Created by zhangbaqing on 2021/5/21.
//
// 118.杨辉三角
// https://leetcode-cn.com/problems/pascals-triangle/
// easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

// 5
// [
// [1],
// [1,1],
// [1,2,1],
// [1,3,3,1],
// [1,4,6,4,1]
//]
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result(numRows, std::vector<int>());
        if (numRows <= 0) {
            return result;
        }
        for (int i = 0; i < numRows; ++i) {
            result[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
        return result;
    }
};

#endif

#if false
class Solution {
public:
    vector<vector<int>> generate(int numRows) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
