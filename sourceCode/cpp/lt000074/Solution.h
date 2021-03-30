//
// Created by zhangbaqing on 2021/3/30.
//
// https://leetcode-cn.com/problems/search-a-2d-matrix/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>

using std::vector;

#if false

/**
 * 解法一：
 * 思路：二分查找走起来
 * */
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for (auto &vec : matrix) {
            if (std::binary_search(vec.begin(), vec.end(), target)) {
                return true;
            }
        }
        return false;
    }
};

#endif

#if true

/**
 * 解法二：
 * 思路：二分查找的优化
 *      观察数据的特性，每一行最右边数据是这一列最大的，我们不妨从左上角开始，
 *      如果这一行最右边元素比目标值大，那目标值极有可能出现在这一行，二分查找之
 *      否则循环处理下一行
 * */
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        for (auto &vec : matrix) {
            // 如果这一行的最大值比目标值小，直接进入下一次循环
            if (vec.back() < target) {
                continue;
            }
            // 如果这一行的最小值比目标值大，直接返回false
            if (vec.front() > target) {
                return false;
            }
//            return std::binary_search(vec.begin(), vec.end(), target) ? true : false;
            return binarySearch(vec, target) ? true : false;
        }
        return false;
    }

private:
    bool binarySearch(const std::vector<int> &data, int target);
};

bool Solution::binarySearch(const std::vector<int> &data, int target) {
    int start = 0, end = data.size();
    int middle = 0;
    while (start < end) {
        middle = start + (end - start) / 2;
        if (data[middle] == target) {
            return true;
        } else if (data[middle] < target) {
            start = middle + 1;
        } else {
            end = middle;
        }
    }
    return false;
}

#endif

#if false
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
