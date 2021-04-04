//
// Created by zhangbaqing on 2021/4/4.
//
// https://leetcode-cn.com/problems/rabbits-in-forest/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <unordered_map>

using std::vector;

#if true

/**
 * 思路：两只相同颜色的兔子，看到其他跟自己相同颜色兔子的数量，应该相同（一定相同）
 *      若两只兔子，看到其他跟自己相同颜色兔子的数量不同，那么这两只兔子的颜色，应该也不相同（一定不相同）
 *
 */
class Solution {
public:
    int numRabbits(vector<int> &answers) {
        auto count = std::unordered_map<int, int>();
        for (auto item : answers) {
            ++count[item];
        }
        int result = 0;
        int x = 0, y = 0;
        for (auto &p : count) {
            y = p.first, x = p.second;
            result += (x + y) / (y + 1) * (y + 1);
        }
        return result;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
