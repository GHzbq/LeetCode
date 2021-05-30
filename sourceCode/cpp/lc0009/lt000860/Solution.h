//
// Created by zhangbaqing on 2020/12/10.
//
// https://leetcode-cn.com/problems/lemonade-change/
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

#if 1

class Solution {
public:
    bool lemonadeChange(std::vector<int> &bills) {
        int five = 0, ten = 0;
        for (auto bill : bills) {
            if (bill == 5) {
                ++five;
            } else if (bill == 10) {
                ++ten;
                if (five < 0) {
                    return false;
                } else {
                    --five;
                }
            } else {
                if (ten > 0 && five > 0) {
                    --ten;
                    --five;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif

#if 0
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
