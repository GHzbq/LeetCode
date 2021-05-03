//
// Created by zhangbaqing on 2021/5/3.
//
// 7.整数反转
// https://leetcode-cn.com/problems/reverse-integer/
// 难度：easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <climits>

#if true

class Solution {
public:
    int reverse(int x) {
        long ret = 0;
        while (x != 0) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        if (ret > INT_MAX || ret < INT_MIN) {
            return 0;
        }
        return ret;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
