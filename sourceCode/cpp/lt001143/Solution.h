//
// Created by zhangbaqing on 2021/4/3.
//
// https://leetcode-cn.com/problems/longest-common-subsequence/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <string>

using std::string;

#if true

/**
 * 分析，最长公共子序列，我可不可以先找到两个字符串中都出现的字符呢？
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) {
            return 0;
        }
        int m = text1.size(), n = text2.size();
        // dp[i][j]表示 text1[0...i] 与 text2[0...j]最长公共子序列
        auto dp = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));
        // dp[0][0] = 0;
        // dp[0][1] = 0;
        // dp[1][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
