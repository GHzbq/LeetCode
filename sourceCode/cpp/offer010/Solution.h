//
// Created by zhangbaqing on 2021/4/15.
//
// 剑指offer10-I.斐波那契数列
// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#if true

class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        const int MOD = 1e9 + 7;
        long first = 0, second = 1, tmp = 0;
        for (int i = 2; i <= n; ++i) {
            tmp = second;
            second = (first + second) % MOD;
            first = tmp;
        }
        return second;
    }
};

#endif

#if false
class Solution {
public:
    int fib(int n) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
