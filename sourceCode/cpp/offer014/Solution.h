//
// Created by zhangbaqing on 2021/4/21.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <cmath>

#if false

// 剑指offer 14-I. 剪绳子-I
// https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
class Solution {
public:
    int cuttingRope(int n) {
        // 长度等于1,剪不成
        if (n < 2) {
            return 0;
        }
        // 长度为2时，只能剪一刀，一刀两段，刚好满足m > 1的条件
        if (n == 2) {
            return 1;
        }
        // 长度为3时，有两种剪法，第一种，剪一刀，得2
        // 第二种，剪2刀，得1，取最大值，2返回
        if (n == 3) {
            return 2;
        }
        // 尽可能多的剪出长度为3的段
        int timeOf3 = n / 3;
        // 当绳子最后剩下的长度为4的时候，不能再剪长度为3的段，剪2个长度为2的段，能取得更大值
        if (n - timeOf3 * 3 == 1) {
            timeOf3 -= 1;
        }
        int timesOf2 = (n - timeOf3 * 3) / 2;
        return (int) (pow(3, timeOf3)) * (int) (pow(2, timesOf2));
    }
};

#endif

#if false

// 剑指offer 14-II. 剪绳子-II
// https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/
// 需要考虑int溢出的问题
const int MOD = 1e9+7;
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4) {
            return n-1;
        }
        int timesOf3 = n / 3;
        if (n - timesOf3*3 == 1) {
            timesOf3 -= 1;
        }
        int timesOf2 = (n - timesOf3 * 3) / 2;
        return func(3, timesOf3) * func(2, timesOf2) % MOD;
    }
private:
    long func(int base, int exp) {
        if (base == 0) {
            return 0;
        }

        long result = 1;
        for (int i = 0; i < exp; ++i) {
            result = result * base % MOD;
        }
        return result;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
