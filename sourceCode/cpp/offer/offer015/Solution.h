//
// Created by zhangbaqing on 2021/4/21.
//
// 剑指offer15. 二进制中1的个数
// https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
// 难度：easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <cstdint>

#if true

// 按位与一把呗
// 5: 0101
//    0100
//--------
//    0100
//    0011
//--------
//    0000
// &了两次，刚好与5的二进制中1的个数相同
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            n &= n - 1;
            ++count;
        }
        return count;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
