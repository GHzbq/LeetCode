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

    // 剑指offer 10-II 青蛙跳台接问题
    // https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
    // -----
    // 超出时间限制
//    int numWays(int n) {
//        // 0级台阶也要跳一步
//        if (n == 0) {
//            return 1;
//        }
//        if (n <= 2) {
//            return n;
//        }
//        const int MOD = 1e9 + 7;
//        return (numWays(n - 1) + numWays(n - 2)) % MOD;
//    }
    int numWays(int n) {
        int first = 1, second = 1, sum = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            sum = (first + second) % MOD;
            first = second;
            second = sum;
        }
        return first;
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
