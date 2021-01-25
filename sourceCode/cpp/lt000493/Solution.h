//
// Created by zhangbaqing on 2020/11/28.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

#if 1

class Solution {
public:
    int reversePairs(std::vector<int> &nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; i < j && j < nums.size(); ++j) {
                if (nums[i] > 2 * nums[j]) {
                    ++result;
                }
            }
        }
        return result;
    }
};

#endif

#if 0
// 默认代码模板
class Solution {
public:
    int reversePairs(vector<int>& nums) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
