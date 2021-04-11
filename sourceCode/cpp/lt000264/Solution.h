//
// Created by zhangbaqing on 2021/4/11.
//
// https://leetcode-cn.com/problems/ugly-number-ii/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>
#include <iostream>

#if true

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 1) {
            return n;
        }
        auto result = std::vector<int>(n);
        int c2 = 0, c3 = 0, c5 = 0;
        int r2 = 0, r3 = 0, r5 = 0;
        result[0] = 1;
        for (int i = 1; i < n; ++i) {
            r2 = result[c2] * 2;
            r3 = result[c3] * 3;
            r5 = result[c5] * 5;
            result[i] = std::min(r2, std::min(r3, r5));
            if (result[i] == r2) ++c2;
            if (result[i] == r3) ++c3;
            if (result[i] == r5) ++c5;
        }
        std::cout << std::endl;
        return result[n - 1];
    }
};

#endif

#if false
class Solution {
public:
    int nthUglyNumber(int n) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
