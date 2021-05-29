//
// Created by zhangbaqing on 2020/11/17.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <map>
#include <algorithm>

#if 0
// 解法1：枚举所有的可能，排序
// 采用std::multimap存储结果
class Solution {
public:
    std::vector<std::vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        center.push_back(r0);
        center.push_back(c0);
        auto distMap = std::multimap<int, std::vector<int>, std::less<int>>();
        auto getDist = [&](const std::vector<int> &point) {
            return abs(point[0] - center[0]) + abs(point[1] - center[1]);
        };
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                auto point = std::vector<int>({i, j});
                distMap.insert(std::pair<int, std::vector<int>>(getDist(point), point));
            }
        }
        auto result = std::vector<std::vector<int>>();
        for (auto &pair: distMap) {
            result.push_back(pair.second);
        }
        center.clear();
        return result;
    }

public:
    static std::vector<int> center;
};

std::vector<int> Solution::center = {};
#endif

#if 0
// 解法二：枚举所有可能结果
// 存储在vector里，直接排序
class Solution {
public:
    std::vector<std::vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        auto result = std::vector<std::vector<int>>();
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                result.push_back(std::vector<int>({i, j}));
            }
        }
        auto cmp = [=](const std::vector<int> &left, const std::vector<int> &right) {
            int liftDist = abs(left[0] - r0) + abs(left[1] - c0);
            int rightDist = abs(right[0] - r0) + abs(right[1] - c0);
            return liftDist < rightDist;
        };
        std::sort(result.begin(), result.end(), cmp);
        return result;
    }
};
#endif

#if 0

// 解法三：桶排序
class Solution {
public:
    std::vector<std::vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        auto buckets = std::vector<std::vector<std::vector<int>>>(R * C);
        auto getDist = [&](const std::vector<int> &point) {
            return abs(point[0] - r0) + abs(point[1] - c0);
        };
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                auto point = std::vector<int>({i, j});
                buckets[getDist(point)].push_back(point);
            }
        }
        auto result = std::vector<std::vector<int>>();
        for (auto &bucket : buckets) {
            for (auto &point : bucket) {
                result.push_back(point);
            }
        }
        return result;
    }
};

#endif

#if 1
using namespace std;

// 解法四：几何解法
class Solution {
public:
    const int dr[4] = {1, 1, -1, -1};
    const int dc[4] = {1, -1, -1, 1};

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        vector<vector<int>> ret;
        int row = r0, col = c0;
        ret.push_back({row, col});
        for (int dist = 1; dist <= maxDist; dist++) {
            row--;
            for (int i = 0; i < 4; i++) {
                while ((i % 2 == 0 && row != r0) || (i % 2 != 0 && col != c0)) {
                    if (row >= 0 && row < R && col >= 0 && col < C) {
                        ret.push_back({row, col});
                    }
                    row += dr[i];
                    col += dc[i];
                }
            }
        }
        return ret;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
