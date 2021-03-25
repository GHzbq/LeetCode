//
// Created by zhangbaqing on 2021/3/25.
//
// https://leetcode-cn.com/problems/unique-paths-ii/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if false

/**
 * 解法一：
 * 思路：通过分析题意，我们发现，这个笨蛋每次只能往右或者往下走一步，换个角度，
 *      这个笨蛋到这一步的方式只会有两种，要么从上面，要么从左边
 *      用f[i][j]表示从(0, 0)走到(i, j)，可以有f[i][j]种方式
 *      那么f[i][j] = f[i-1][j] + f[i][j-1]
 *      考虑一种特殊情况，(i, j)的位置是个障碍物
 *      此时无论从上边，还是左边，都走不到当前位置，f[i][j]的位置应该置0
 * */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        const int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        auto f = std::vector<std::vector<int>>(row, std::vector<int>(col, 0));
        f[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 1; i < row; ++i) {
            f[i][0] = obstacleGrid[i][0] == 1 ? 0 : f[i - 1][0];
        }
        for (int j = 1; j < col; ++j) {
            f[0][j] = obstacleGrid[0][j] == 1 ? 0 : f[0][j - 1];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                f[i][j] = obstacleGrid[i][j] == 1 ? 0 : f[i - 1][j] + f[i][j - 1];
            }
        }
        return f.back().back();
    }
};

#endif

#if true

/**
 * 解法一优化：
 * 思路：使用滚动数组，我们发现，经过一次遍历，一行的数据就已经处理完了，处理本行的数据，完全可以使用上一行的数据
 *      而左边来的，是一路叠加来的
 * */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        auto f = std::vector<int>(col, 0);
        f[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    // 如果这是个障碍物，应该跳过循环；
                    continue;
                }
                if (j != 0 && obstacleGrid[i][j] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }
        return f.back();
    }
};

#endif

#if false
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
