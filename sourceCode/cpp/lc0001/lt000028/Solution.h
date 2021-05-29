//
// Created by zhangbaqing on 2021/4/20.
//
// 28. 实现strStr()
// https://leetcode-cn.com/problems/implement-strstr/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>

using std::string;

#if true

class Solution {
public:
    int strStr(const string &haystack, const string &needle) {
        return haystack.find(needle);
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
