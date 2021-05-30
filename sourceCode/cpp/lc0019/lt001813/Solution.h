//
// Created by zhangbaqing on 2021/4/3.
//
// https://leetcode-cn.com/problems/sentence-similarity-iii/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <vector>

using std::string;

#if true

/**
 * 发现一个特点：这些句子，要么开头的单词相同，要么结尾的单词相同
 * 例如示例一：第一个单词相同
 * 例如示例三：最后一个单词相同
 * 那么我可以大胆的将这个句子拆分为两个部分，一部分为相同的单词，那么只需要另一部分在另一个串里出现，那么我们就可以拼出这个句子
 * sentence1: My name is will
 * sentence2: My is
 * 通过这个示例，我们发现：即使除去相同部分，我们也需要保证剩下的部分完整的出现在另一个句子的开头或者结尾，否则也不行
 * 虽然没提交过，但是感觉：
 *    1. 可能会有大小写的问题
 *    2. 既然插入的是句子，就不应该是一个单词拼另一个单词，这点可以从示例5看出
 *
 */
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {   //////////////////两边剔的思想
        string s1 = sentence1, s2 = sentence2;
        if (s1 == s2)
            return true;
        if (s1.size() > s2.size()) {
            swap(s1, s2);
        }

        std::vector<string> a1 = split(s1);
        std::vector<string> a2 = split(s2);

        while (!a1.empty()) {
            if (!(a1[0] == a2[0] || a1.back() == a2.back()))
                return false;
            if (a1[0] == a2[0]) {
                a1.erase(a1.begin());
                a2.erase(a2.begin());
            }
            if (a1.size() > 0 && a1.back() == a2.back()) {
                a1.pop_back();
                a2.pop_back();
            }
        }
        return true;
    }

    ///////////split函数。与python的split作用相同
    std::vector<string> split(string s) {
        int n = s.size();
        vector <string> res;
        int L = 0, R = 0;
        while (R < n) {
            if (s[R] != ' ') {   //R指针，是个字母
                R++;
            } else {       //为空了
                string cur = s.substr(L, R - L);
                res.push_back(cur);
                R++;
                L = R;
            }
        }
        if (L != R) {     //别忘了收尾
            string cur = s.substr(L, R - L);
            res.push_back(cur);
        }
        return res;
    }

};

#endif

#endif //LEETCODE_SOLUTION_H
