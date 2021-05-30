//
// Created by zhangbaqing on 2021/4/13.
//
// 剑指offer05 替换空格
// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <sstream>

using std::string;

#if false

// 第一次统计所有空格
// 从后往前搬移元素，并将空格替换为20%
class Solution {
public:
    string replaceSpace(string s) {
        if (s.empty()) {
            return s;
        }
        int spaceCount = 0;
        for (const auto &item : s) {
            if (item == ' ') ++spaceCount;
        }
        int size = s.size();
        int newSize = size + 2 * spaceCount;
        s.resize(newSize);
        --newSize, --size;
        while (newSize >= 0) {
            if (s[size] == ' ') {
                s[newSize--] = '0';
                s[newSize--] = '2';
                s[newSize--] = '%';
                --size;
            } else {
                s[newSize--] = s[size--];
            }
        }
        return s;
    }
};

#endif

#if true

// 创建一个新的对象
class Solution {
public:
    string replaceSpace(string s) {
        std::stringstream ss;
        for (const auto &item : s) {
            if (' ' == item) {
                ss << "%20";
            } else {
                ss << item;
            }
        }
        return ss.str();
    }
};

#endif

#if false
class Solution {
public:
    string replaceSpace(string s) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
