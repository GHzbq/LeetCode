//
// Created by zhangbaqing on 2021/3/29.
//
// https://leetcode-cn.com/problems/reverse-bits/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <cstdint>

#if false

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32 && n > 0; ++i) {
            result |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return result;
    }
};

#endif

#if true

class Solution {
private:
    const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

public:
    uint32_t reverseBits(uint32_t n) {
        // 5 0000 0000 0000 0000 0000 0000 0000 0101   // n
        //   0000 0000 0000 0000 0000 0000 0000 0010   // n >> 1
        //   0101 0101 0101 0101 0101 0101 0101 0101 & // M1
        //   0000 0000 0000 0000 0000 0000 0000 0010   // tmp_result
        //   ----
        //   0000 0000 0000 0000 0000 0000 0000 0101   // n
        //   0101 0101 0101 0101 0101 0101 0101 0101 & // M1
        //   0000 0000 0000 0000 0000 0000 0000 0101 << 1 // tmp_result2 << 1
        //   0000 0000 0000 0000 0000 0000 0000 1010   // tmp_result3
        //   0000 0000 0000 0000 0000 0000 0000 0010 | // tmp_result
        //   0000 0000 0000 0000 0000 0000 0000 1010 n现在的值
        n = n >> 1 & M1 | (n & M1) << 1;
        // n 0000 0000 0000 0000 0000 0000 0000 1010   // n
        //   0000 0000 0000 0000 0000 0000 0000 0010   // n >> 2
        //   0011 0011 0011 0011 0011 0011 0011 0011 & // M2
        //   0000 0000 0000 0000 0000 0000 0000 0010   // tmp_result
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M4 | (n & M4) << 4;
        n = n >> 8 & M8 | (n & M8) << 8;
        return n >> 16 | n << 16;
    }
};

#endif

#if false
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
