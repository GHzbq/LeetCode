//
// Created by zhangbaqing on 2021/4/21.
//
// 191. 位1的个数
// https://leetcode-cn.com/problems/number-of-1-bits/
// 难度：easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <cstdint>

#if true

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // 3: 00000011
        // 2: 00000010 &
        //    00000010
        // 1: 00000001 &
        //    00000000
        int count = 0;
        while (0 != n) {
            n &= n - 1;
            ++count;
        }
        return count;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
