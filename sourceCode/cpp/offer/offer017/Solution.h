//
// Created by zhangbaqing on 2021/4/23.
//
// 剑指offer17. 打印从1到最大的n位数
// https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
// 难度：easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <numeric>
#include <vector>

using std::vector;

#if true

class Solution {
public:
    vector<int> printNumbers(int n) {
        int size = 1;
        for (int i = 0; i < n; ++i) {
            size *= 10;
        }
        std::vector<int> result(size - 1, 0);
        std::iota(result.begin(), result.end(), 1);
        return result;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
