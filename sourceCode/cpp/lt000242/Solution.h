//
// Created by zhangbaqing on 2020/11/22.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <algorithm>

#if 1

/**
 * 解法一：使用数组，作为哈希表
 *     字符串只包含小写字母
 *     int array[26] = {0};
 *     只需要定义一个数组，先遍历第一个数组，没遇到一个字符，++array[str1[i]-'a'];
 *     然后遍历第二个数组，每遇到一个字符，--array[str2[i]-'a']; 中间如果小于0，直接返回false
 *     最后再遍历array，如果其中有值大于0，返回false
 *     返回true
 */
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int array[26] = {0};
        for (auto it : s) {
            ++array[it - 'a'];
        }
        for (auto it : t) {
            --array[it - 'a'];
            if (array[it - 'a'] < 0) {
                return false;
            }
        }

        for (auto it : array) {
            if (it != 0) {
                return false;
            }
        }

        return true;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
