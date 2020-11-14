//
// Created by zhangbaqing on 2020/11/14.
//
// https://leetcode-cn.com/problems/relative-sort-array/
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int> &arr1, std::vector<int> &arr2) {
        auto numSet = std::unordered_set<int>();
        for (auto num : arr2) {
            numSet.insert(num);
        }
        auto numMap = std::map<int, int>();
        for (auto num : arr1) {
            ++numMap[num];
        }
        arr1.clear();
        int size = 0;
        for (auto num : arr2) {
            size = numMap[num];
            numMap.erase(num);
            while (size--) {
                arr1.push_back(num);
            }
        }
        for (auto &numPair : numMap) {
            size = numPair.second;
            while (size--) {
                arr1.push_back(numPair.first);
            }
        }
        return arr1;
    }
};

#endif //LEETCODE_SOLUTION_H
