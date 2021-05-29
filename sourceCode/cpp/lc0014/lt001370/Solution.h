//
// Created by zhangbaqing on 2020/11/25.
//
// https://leetcode-cn.com/problems/increasing-decreasing-string/
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <map>

#if 0
// 解法一：使用map统计字符出现次数，在遍历map，追加字符，得到结果
// 28ms 8MB

class Solution {
public:
    std::string sortString(const std::string &s) {
        auto charMap = std::map<char, int>();
        for (auto ch : s) {
            ++charMap[ch];
        }
        auto result = std::string();
        result.reserve(s.size());
        while (true) {
            if (result.size() == s.size()) {
                break;
            }
            for (auto &pair : charMap) {
                if (pair.second > 0) {
                    result.push_back(pair.first);
                    --pair.second;
                }
            }
            for (auto it = charMap.rbegin(); it != charMap.rend(); ++it) {
                if (it->second > 0) {
                    result.push_back(it->first);
                    --it->second;
                }
            }
        }
        charMap.clear();

        return result;
    }
};

#endif

#if 1

// 解法二：使用hash桶
// 8ms 7.5MB
class Solution {
public:
    std::string sortString(std::string s) {
        int bucket[26] = {0};
        for (auto ch : s) {
            ++bucket[ch - 'a'];
        }
        auto result = std::string();
        result.reserve(s.size());
        int i = 0;
        while (result.size() < s.size()) {
            for (i = 0; i < 26; ++i) {
                if (bucket[i] > 0) {
                    result.push_back(i + 'a');
                    --bucket[i];
                }
            }
            for (i = 25; i >= 0; --i) {
                if (bucket[i] > 0) {
                    result.push_back(i + 'a');
                    --bucket[i];
                }
            }
        }
        return result;
    }
};

#endif

#if 0
// 默认代码模板
class Solution {
public:
    string sortString(string s) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
