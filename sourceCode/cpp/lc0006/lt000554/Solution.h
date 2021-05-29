//
// Created by zhangbaqing on 2021/5/2.
//
// 554.砖墙
// https://leetcode-cn.com/problems/brick-wall/
// 难度：中等

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <unordered_map>

using std::vector;

#if true

class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        // 想画穿过最少砖块的垂线
        // 通过间隙越多，穿过的砖块越少呗
        // 那怎么表示间隙呢，举个例子
        // 1 2 2 1     // 1 3 5
        // 3 1 2       // 3 4
        // 1 3 2       // 1 4
        // 2 4         // 2
        // 3 1 2       // 3 4
        // 1 3 1 1     // 1 4 5
        // 使用前缀和的方式表示，统计所有缝隙的总数
        // 缝隙越多，穿过的墙越少
        // 对于一行砖块，缝隙的表示是唯一的
        std::unordered_map<int, int> m;
        int sum = 0;
        for (const auto &bricks : wall) {
            sum = 0;
            for (auto brick : bricks) {
                sum += brick;
                ++m[sum];
            }
            m.erase(sum); // 移除最后一个缝隙--边界
        }
        int size = wall.size();
        int minBrick = size; // 最多穿过所有墙
        for (auto &p : m) {
            minBrick = std::min(minBrick, size - p.second);
        }
        return minBrick;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
