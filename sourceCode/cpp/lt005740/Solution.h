//
// Created by zhangbaqing on 2021/4/25.
//
// 5740.所有原因按顺序排布的最长子字符串
// https://leetcode-cn.com/problems/longest-substring-of-all-vowels-in-order/
// 难度：中等

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <set>

using std::string;

#if true

// 动态规划
// dp[i]表示前多少个字符可以组成美丽字符串，如果不能组成就是0
// 那么dp[i]可由dp[i-1]变化而来
// 如果dp[i-1]是美丽字符串，那么，
// 只需要word[i]和word[i-1]相同，或者word[i]为word[i-1]的下一个元音字母
// 此时可以更新dp[i] = dp[i-1]+1;
// 如果dp[i-1]不是美丽字符串，那么判断word[i]能否作为美丽字符串的start
// 可以的话，dp[i] = 1
// 否则,dp[i] = 0
//
// 边界条件，初始时，dp[0] = word[0] == 'a' ? 1 : 0;
// 由于我们要考虑word[word.size()-1]是否是美丽字符串
//
// 很遗憾，超时！
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        if (word.empty()) {
            return 0;
        }
        int size = word.size();
        if (size < 5) {
            return 0;
        }
        int *dp = new int[size]();
        dp[0] = word[0] == 'a' ? 1 : 0;
        std::set<char> tmp({'a', 'e', 'i', 'o', 'u'});
        auto pos = tmp.begin();
        for (int i = 1; i < size; ++i) {
            if (dp[i - 1] > 0) {
                // 只需要word[i]和word[i-1]相等
                // 或者word[i]为word[i-1]为下一个元音字母
                pos = tmp.find(word[i - 1]);
                if ((word[i] == word[i - 1]) ||
                    ((pos != tmp.end()) && (++pos != tmp.end()) && (*pos == word[i]))) {
                    dp[i] = dp[i - 1] + 1;
                    continue;
                }
            }
            dp[i] = word[i] == 'a' ? 1 : 0;
        }
        int result = INT_MIN;
        bool flag = false;
        int bit = 0;
        int cond = 0;
        cond |= (1 << ('a' - 'a'));
        cond |= (1 << ('e' - 'a'));
        cond |= (1 << ('i' - 'a'));
        cond |= (1 << ('o' - 'a'));
        cond |= (1 << ('u' - 'a'));
        for (int i = 4; i < size; ++i) {
            if (dp[i] >= 5) {
                bit = 0;
                for (int j = i - dp[i] + 1; j <= i; ++j) {
                    bit |= (1 << (word[j] - 'a'));
                }
                if (bit == cond) {
                    flag = true;
                    result = std::max(result, dp[i]);
                }
            }
        }
        return flag ? result : 0;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
