//
// Created by zhangbaqing on 2021/3/21.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <queue>

using std::vector;


#if 0

/**
 * 解法一：
 * 思路： 1. 遍历二维数组，用一个队列保存每个0出现的位置
 *       2. 遍历队列，将一行一列变为0；
 * 提交报错：AddressSanitizer: heap-use-after-free on address 0x61500004b778 at pc 0x00000034c3c3 bp 0x7ffee0dc3d50 sp 0x7ffee0dc3d48
 * */
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        auto zeroQueue = std::queue<std::pair<int, int>>();
        auto row = matrix.size();
        auto col = matrix[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (0 == matrix[i][j]) {
                    zeroQueue.push(std::pair<int, int>(i, j));
                }
            }
        }
        while (!zeroQueue.empty()) {
            auto &p = zeroQueue.front();
            zeroQueue.pop();
            std::fill(matrix[p.first].begin(), matrix[p.first].end(), 0);
            for (int i = 0; i < row; ++i) {
                matrix[i][p.second] = 0;
            }
        }
    }
};

#endif

#if false

/**
 * 解法二：
 * 思路： 用一行，一列两个数组，来保存0出现的位置
 *       如果某个位置出现0，那么这一行，一列都应该变成0
 *       统计结束之后，再将他们变成0，避免对同一位置，重复置0
 * */
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        auto m = matrix.size(), n = matrix[0].size();
        auto row = std::vector<int>(m),
                col = std::vector<int>(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == matrix[i][j]) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((1 == row[i]) || (1 == col[j])) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

#endif

#if true

/**
 * 解法3：
 * 思路：通过解法2，我们发现，其实使用第一行和第一列来标记这一行或这一列是否应该被置0
 *      ，这样做，可以省掉O(m+n)的空间；
 *      需要考虑第一行和第一列是否应该全置0，并且应该考虑置0的时机
 *      我们应该首先遍历第一行和第一列，并用变量标记出来
 *      第二步，用第一行和第一列去标记那些行那些列应该被置0
 *      第三步，通过第一行和第一列的标记，处理其他行和列
 *      第四步，通过标记，判断第一行和第一列是否应该全置0
 *      且3，4步不可以互换位置！！！
 * */
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        auto m = matrix.size(), n = matrix[0].size();
        auto firstRow = false, firstCol = false;
        // 1.
        for (int i = 0; i < m; ++i) {
            if (0 == matrix[i][0]) {
                firstCol = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (0 == matrix[0][j]) {
                firstRow = true;
            }
        }
        // 2.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (0 == matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 3.
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if ((0 == matrix[i][0]) || (0 == matrix[0][j])) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 4.
        if (firstRow) {
            std::fill(matrix[0].begin(), matrix[0].end(), 0);
        }
        if (firstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }

    }
};

#endif

#if 0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
