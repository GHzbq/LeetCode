//
// Created by zhangbaqing on 2021/5/20.
//
// 692.前k个高频单词
// https://leetcode-cn.com/problems/top-k-frequent-words/
// medium

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::vector;

#if true

using PSI = std::pair<std::string, int>;

// 解法一：先统计词频，再按topK解决
class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        // 先统计词频，再topK
        std::unordered_map<std::string, int> m;
        for (auto &word : words) {
            ++m[word];
        }
        // 统计大的，建小堆
        auto pCmp = [](const PSI &left, const PSI &right) {
            if (left.second != right.second) {
                // 词频要最高的，所以重载大于号
                return left.second > right.second;
            } else {
                // 字母序要最小的，所以重载小于号
                return left.first < right.first;
            }
        };
        std::priority_queue<PSI, std::vector<PSI>, decltype(pCmp)> p(pCmp);
        auto pos = m.begin();
        int count = 0;
        // 先插入k个
        while (count < k && pos != m.end()) {
            p.push(*pos);
            ++count, ++pos;
        }
        while (pos != m.end()) {
            auto &pSI = p.top();
            if (pCmp(*pos, pSI)) {
                p.pop();
                p.push(*pos);
            }
            ++pos;
        }
        std::vector<std::string> result;
        result.resize(k);
        count = k;
        while (!p.empty()) {
            auto &pSI = p.top();
            result[--count] = pSI.first;
            p.pop();
        }
        return result;
    }
};

#endif

#if false

using PSI = std::pair<std::string, int>;

// 解法二：统计词频，直接排序
class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string> &words,
                                          int k) {
        std::unordered_map<std::string, int> wordCount;
        for (auto &word : words) {
            ++wordCount[word];
        }
        std::vector<PSI> tmp;
        tmp.reserve(wordCount.size());
        for (auto &p : wordCount) {
            tmp.emplace_back(p);
        }
        auto cmp = [](const PSI &left, const PSI &right) {
            if (left.second != right.second) {
                return left.second > right.second;
            } else {
                return left.first.compare(right.first) < 0;
            }
        };
        std::sort(tmp.begin(), tmp.end(), cmp);

        std::vector<std::string> result;
        result.reserve(k);
        for (int i = 0; i < k; ++i) {
            result.emplace_back(tmp[i].first);
        }
        return result;
    }
};

#endif

#if false
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
