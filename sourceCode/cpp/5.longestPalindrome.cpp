/**
 * 5. 最长回文串
 * https://leetcode-cn.com/problems/longest-palindromic-substring/
 * */
#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        // 考虑中心扩展算法
        // 如果一段字符串是回文串，那么以某个字符为中心的前缀和后缀必定相同
        // "aba" 以 'b' 为中心 前缀 "a" 和 后缀 "a"是相同的
        // 枚举中心位置，然后再在该位置上扩展，记录并更新得到的最长回文串长度
        int n = static_cast<int>(s.length());
        if(n < 1)
        {
            return "";
        }

        int max_len = 0;
        int start = 0;
        int temp = 0;
        for(int i = 0; i < n; ++i)
        {
            // 回文长度为奇数
            for(int j = 0; ((i-j>=0) && (i+j < n)); ++j)
            {
                if(s[i-j] != s[i+j])
                {
                    break;
                }
                temp = j * 2 + 1;
            }

            if(temp > max_len)
            {
                max_len = temp;
                start = i - max_len/2;
            }

            // 回文串为偶数
            for(int j = 0; ((i-j >= 0) && (i+j+1 < n)); ++j)
            {
                if(s[i-j] != s[i+j+1])
                {
                    break;
                }
                temp = j * 2 + 2;
            }

            if(temp > max_len)
            {
                max_len = temp;
                start = i - max_len/2 + 1;
            }
        }

        return s.substr(start, max_len);
    }
};

#if 0

class Solution {
public:
    string longestPalindrome(string s) {
        // 考虑动态规划
        // 状态转移方程
        // dp[j][i] 表示从第j到第i个字符串是回文串
        // dp[j][i] = dp[j+1][i-1] && s[j] == s[i]
        // 时间复杂度 O(n^2)
        // 空间复杂度 O(n^2)
        int n = static_cast<int>(s.length());
        if( n < 1)
        {
            return "";
        }

        // 记录最长回文串长度
        int max_len = 0;
        // 记录最长回文串起始下标
        int start = 0;
        // 状态数组
        bool dp[1001][1001] = {{0}};
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                // 如果 i,j 相邻或相等，直接判断s[i]与s[j]是否相等
                if(i-j < 2)
                {
                    dp[j][i] = (s[j] == s[i]);
                }
                else
                {
                    dp[j][i] = (dp[j+1][i-1] && (s[i] == s[j]));
                }

                if(dp[j][i] && max_len < i-j+1)
                {
                    max_len = i-j+1;
                    start = j;
                }
            }
        }

        return s.substr(start, max_len);
    }
};

#endif
