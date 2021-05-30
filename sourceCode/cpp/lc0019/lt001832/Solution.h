//
// Created by zhangbaqing on 2021/4/18.
//
// 1832. 判断句子是否为全字母句
// 5734.判断句子是否为全字母句
// https://leetcode-cn.com/problems/check-if-the-sentence-is-pangram/
// 难度：easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>

using std::string;

#if true

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int bit = 0;
        for (char ch : sentence) {
            bit |= (1 << (ch - 'a'));
        }
        return bit == 0x3ffffff;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
