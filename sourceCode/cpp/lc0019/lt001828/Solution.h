//
// Created by zhangbaqing on 2021/4/17.
//
// 1828.统计一个圆中点的数目
// https://leetcode-cn.com/problems/minimum-operations-to-make-the-array-increasing/
// 难度：中等

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

class Solution {
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries) {
        // 两点间距离公式
        int n = queries.size();
        std::vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            for (const auto &point : points) {
                // 这不是半径的平方 点到圆心距离的平方吗
                if (powll(queries[i][2]) >= (powll(point[0] - queries[i][0]) + powll(point[1] - queries[i][1]))) {
                    ++res[i];
                }
            }
        }
        return res;
    }

    long long powll(int i) {
        return i * i;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
