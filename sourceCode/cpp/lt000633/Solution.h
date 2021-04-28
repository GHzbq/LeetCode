//
// Created by zhangbaqing on 2021/4/28.
//
// 633. 平方数之和
// https://leetcode-cn.com/problems/sum-of-square-numbers/
// 难度: easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <cmath>

#if false
class Solution {
public:
    bool judgeSquareSum(int c) {
        // 一道被标记为“中等”的问题，暴力枚举，通常会时间超限 所以我们得考虑其他方法
        // 也许我们可以忽略一些枚举，来减少枚举的次数
        // 例如，我们只枚举a，如果a*a已经大于c了，就退出循环
        // 当我们确定a之后，b可以在O(1)的时间内，被计算出来，
        // 如果计算出来的b恰好是个整数，那我们就可以返回true了
        // 这样就把时间复杂度由O(c*c),降到了O(sqrt(c))
        for (long a = 0; a*a <= (long)c; ++a) {
            double b = std::sqrt(c - a*a);
            if (b == (int)b) {
                return true;
            }
        }
        return false;
    }
};

#endif

#if true

class Solution {
public:
    bool judgeSquareSum(int c) {
        // 可以考虑使用一下双指针
        // left为0
        // right为sqrt(c)
        // 考虑到可能会有int溢出的情况
        long left = 0;
        long right = sqrt(c);
        while (left <= right) {
            long sum = left * left + right * right;
            if (sum == c) {
                return true;
            } else if (sum > c) {
                --right;
            } else {
                ++left;
            }
        }
        return false;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
