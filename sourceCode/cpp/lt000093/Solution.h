//
// Created by zhangbaqing on 2021/3/26.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <unordered_map>

using std::string;


#if true
// 输入：s = "226"
// 输出：3
// 解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
/**
 * 解法一：
 * 思路：用dp[i+1]表示s[0]~s[i]共有dp[i+1]种解决方案
 *      如果s[i] == '0'，那么s[i-1]只能是'1'或者'2' dp[i+1] = dp[i-1]，否则返回0
 *         解释：s[i-1]s[i]只有唯一解码方式
 *      如果s[i-1] == '1', 那么dp[i+1] = dp[i] + dp[i-1]
 *      如果s[i-1] == '2' && '1' <= s[i] <= '6', 那么dp[i+1] = dp[i] + dp[i-1]
 *      否则，dp[i+1] = dp[i]，也只有一种解码方式，不会新增
 *      例如 "106",当i=2时，s[i-1]: '0', s[i]: '6'
 *      他其实只能从 "10"+"6"这一种方式演化而来，不肯有别的方式
 *      再比如"32",当i=1时，s[i-1]: '3', s[i]: '2'
 *      他也只能通过 "3" + "2"演化而来，唯一的解码方式，不会变多
 *      再比如"2227",当i=3时，s[i-1]: '2', s[i]: '7'
 *      显然他的解码方式只能取决于"222"有多少种解码方式，因为"27"不能作为一种解码方式，只能时"...2" + "7"
 * */
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int size = s.size();
        auto dp = std::vector<int>(size + 1, 0);
        dp[0] = dp[1] = 1; // s[0] == '0'的情况已被排除
        for (int i = 1; i < size; ++i) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    dp[i + 1] = dp[i - 1];
                } else {
                    return 0;
                }
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                dp[i + 1] = dp[i] + dp[i - 1];
            } else {
                dp[i + 1] = dp[i];
            }
        }
        return dp[size];
    }
};

#endif

#if false
class Solution {
public:
    int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    int size = s.size();
    auto dp = std::vector<int>(size + 1, 0);
    dp[0] = dp[1] = 1; // s[0] == '0'的情况已被排除
    for (int i = 1; i < size; ++i) {
        if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2') {
                dp[i + 1] = dp[i - 1];
            } else {
                return 0;
            }
        } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
            dp[i + 1] = dp[i] + dp[i - 1];
        }
    }
    return dp[size];
}
};
#endif

#endif //LEETCODE_SOLUTION_H
