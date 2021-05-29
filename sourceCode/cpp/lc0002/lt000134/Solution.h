//
// Created by zhangbaqing on 2020/11/18.
//
// https://leetcode-cn.com/problems/gas-station/
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

#if 1

// 解法一：暴力枚举
// 思路：尝试从每个加油站出发，看能不能跑回来
//      如果都不能跑回来，return -1
//      如果有一个能跑回来，直接返回i
/**
 * 输入:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

输出: 3
 */
/**
 * 解释:
从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。
 */
class Solution {
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
        int capacity = 0, index = 0;
        int gasSize = gas.size();
        for (int i = 0; i < gasSize; ++i) {
            index = i, capacity = 0;
            do {
                capacity += gas[index]; // 加油
                capacity -= cost[index]; // 开往下一站的消耗
                index = (index + 1) % gasSize;
            } while (capacity >= 0 && index != i);
            if (capacity >= 0) {
                return i;
            }
        }
        return -1;
    }
};

#endif

#if 0
// 默认的代码模板
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
