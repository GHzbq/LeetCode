//
// Created by zhangbaqing on 2020/11/23.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>

#if 1

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>> &points) {
        if (points.empty()) {
            return 0;
        }
        std::sort(points.begin(), points.end(), [](const std::vector<int> &left, const std::vector<int> &right) {
            return left[1] < right[1];
        });
        int pos = points[0][1];
        int arrowCounts = 1;
        for (const auto &balloon: points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++arrowCounts;
            }
        }
        return arrowCounts;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
