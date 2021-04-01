//
// Created by zhangbaqing on 2021/4/1.
//
// https://leetcode-cn.com/problems/clumsy-factorial/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <stack>

#if false

/**
 * 解法一：
 * 分析： 我想，这题既然让求笨阶乘，应该需要遵守四则运算的规则，即先乘除后加减
 *         10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
 *       = (10 * 9 / 8) + 7 - (6 * 5 / 4) + 3 - (2 * 1)
 *       = 18 - 7 + 3 - 2
 *       = 12
 *       这与参考答案吻合，我们来实现一把
 * 思路： 每四位一处理呗
 *       除了第一次计算，用加法，其他都是减法
 *       如果 N % 4 > 0，特殊处理一下
 * */
class Solution {
public:
    int clumsy(int N) {
        if (N <= 0) {
            return 0;
        }
        int result = 0, n = N / 4, tmp = 0;
        bool first = true;
        for (int i = 0; i < n; ++i) {
            if (first) {
                first = false;
                tmp = N * (N - 1) / (N - 2) + (N - 3);
            } else {
                tmp = (-1) * N * (N - 1) / (N - 2) + (N - 3);
            }
            N -= 4;
            result += tmp;
        }
        tmp = 0;
        if (N == 3) {
            if (first) {
                first = false;
                tmp = 3 * 2;
            } else {
                tmp = (-1) * 3 * 2;
            }
        } else if (N == 2) {
            if (first) {
                first = false;
                tmp = 2;
            } else {
                tmp = -2;
            }
        } else if (N == 1) {
            if (first) {
                first = false;
                tmp = 1;
            } else {
                tmp = -1;
            }
        }
        result += tmp;
        return result;
    }
};

#endif

#if false

/**
 * 解法二：
 * 思路：枚举n, n-1, n-2, ..., 2, 1，依次进行乘除加减
 *      用一个栈保存计算过程
 *      1. 如果是乘除，让栈顶元素与当前n进行乘除；
 *      2. 对于加减，可以把减法看为加上一个数的相反数，然后压入栈，等待以后遇见乘除的时候取出
 *      最后将栈中所有元素累加，即可得到想要的答案
 * */
class Solution {
public:
    int clumsy(int n) {
        if (n <= 0) {
            return 0;
        }
        auto s = std::stack<int>();
        s.emplace(n--);
        int index = 0;
        while (n > 0) {
            if (index % 4 == 0) {
                s.top() *= n;
            } else if (index % 4 == 1) {
                s.top() /= n;
            } else if (index % 4 == 2) {
                s.emplace(n);
            } else {
                s.emplace(-n);
            }
            ++index;
            --n;
        }
        int result = 0;
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }
        return result;
    }
};

#endif

#if true

/**
 * 解法二：
 * 思路： 通过观察，我们发现
 *       clumsy(n) = 0      n <= 0
 *       clumsy(n) = 1      n == 1  1
 *       clumsy(n) = 2      n == 2  2*1
 *       clumsy(n) = 6      n == 3  3*2/1
 *       clumsy(n) = 7      n == 4  4*3/2+1
 *       clumsy(n) = n+1    n > 4 && n%4 == 0
 *       clumsy(n) = n+2    n > 4 && n%4 == 1
 *       clumsy(n) = n+2    n > 4 && n%4 == 2
 *       clumsy(n) = n+3    n > 4 && n%4 == 3
 * */
class Solution {
public:
    int clumsy(int n) {
        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else if (n == 3) {
            return 6;
        } else if (n == 4) {
            return 7;
        }
        if (n % 4 == 0) {
            return n + 1;
        } else if (n % 4 == 1) {
            return n + 2;
        } else if (n % 4 == 2) {
            return n + 2;
        } else {
            return n - 1;
        }
    }
}

#endif

#if false
class Solution {
public:
    int clumsy(int N) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
