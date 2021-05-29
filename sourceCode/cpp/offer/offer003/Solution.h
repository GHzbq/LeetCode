//
// Created by zhangbaqing on 2021/4/13.
//
// 剑指offer 03 数组中重复的数字
// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iterator>

using std::vector;

#if false

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        std::unordered_map<int, int> m;
        for (const auto &item : nums) {
            ++m[item];
            if (m[item] > 1) {
                return item;
            }
        }
        return -1;
    }
};

#endif

#if true

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        std::unordered_set<int> s;
        for (const auto &item : nums) {
            auto res = s.insert(item);
            if (!res.second) {
                return item;
            }
        }
        return -1;
    }
};

#endif

#if false
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {

    }
};
#endif


#endif //LEETCODE_SOLUTION_H
