//
// Created by zhangbaqing on 2021/4/12.
//
// https://leetcode-cn.com/problems/largest-number/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using std::vector;
using std::string;

#if true

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        long leftUnit = 10, rightUnit = 10;
        // [52, 2]
        std::sort(nums.begin(), nums.end(), [&](const int &left, const int &right) {
            leftUnit = 10, rightUnit = 10;
            while (leftUnit <= left) {
                leftUnit *= 10;
            }
            while (rightUnit <= right) {
                rightUnit *= 10;
            }
            // return 522 > 252;
            return left * rightUnit + right > right * leftUnit + left;
        });
        if (nums[0] == 0) {
            return "0";
        }
        std::stringstream result;
        for (const auto &num : nums) {
            result << std::to_string(num);
        }
        return result.str();
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
