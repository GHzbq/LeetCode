//
// Created by zhangbaqing on 2021/4/18.
//
// 剑指offer 12.矩阵中的路径
// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
// 难度：中等

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <string>

using std::vector;
using std::string;

#if true

// 我们尝试以每个位置为单词的起始位置
// 然后进行深度优先遍历（向上、下、左和右依次进行）
// 如果可以将所有单词字母都找到，返回true
// 对于已经访问过的，用' '标记出来
// 在递归回溯的时候，将访问过的元素依次恢复
// 递归的边界条件
// 1) 走到边界之外
// 2) 当前元素和单词中的字母不匹配（访问过的，肯定也不匹配）
class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int rows;
    int cols;

    bool dfs(std::vector<std::vector<char>> &board,
             const std::string &word,
             int i, int j, int k);
};

bool Solution::dfs(std::vector<std::vector<char>> &board,
                   const std::string &word,
                   int i, int j, int k) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[k]) {
        return false;
    }
    if (k == word.size() - 1) {
        return true;
    }
    board[i][j] = ' ';
    bool ret = dfs(board, word, i - 1, j, k + 1) ||
               dfs(board, word, i + 1, j, k + 1) ||
               dfs(board, word, i, j - 1, k + 1) ||
               dfs(board, word, i, j + 1, k + 1);
    board[i][j] = word[k];
    return ret;
}

#endif

#endif //LEETCODE_SOLUTION_H
