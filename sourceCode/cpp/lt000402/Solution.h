//
// Created by zhangbaqing on 2020/11/15.
//
// https://leetcode-cn.com/problems/remove-k-digits/
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <vector>

class Solution {
public:
    static std::string removeKdigits(const std::string &num, int k) {
        std::vector<char> numStack;
        for (auto digit : num) {
            while (!numStack.empty() && numStack.back() > digit && k) {
                numStack.pop_back();
                --k;
            }
            numStack.push_back(digit);
        }

        for (; k > 0; --k) {
            numStack.pop_back();
        }

        std::string result;
        bool isLeadingZero = true;
        for (auto &digit: numStack) {
            if (isLeadingZero && digit == '0') {
                continue;
            }
            isLeadingZero = false;
            result += digit;
        }
        return result.empty() ? "0" : result;
    }
};

#endif //LEETCODE_SOLUTION_H
