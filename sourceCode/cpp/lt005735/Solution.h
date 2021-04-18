//
// Created by zhangbaqing on 2021/4/18.
//
// 5735.雪糕的最大数量
// https://leetcode-cn.com/problems/maximum-ice-cream-bars/
// 难度：中等

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>

using std::vector;

#if true

class Solution {
public:
    int maxIceCream(vector<int> &costs, int coins) {
        std::sort(costs.begin(), costs.end());
        int sum = 0, count = 0;
        for (int cost : costs) {
            sum += cost;
            if (sum > coins) {
                break;
            }
            ++count;
        }
        return count;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
