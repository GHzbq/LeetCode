//
// Created by zhangbaqing on 2021/5/23.
//
// 5765.跳跃游戏
// https://leetcode-cn.com/problems/jump-game-vii/
// medium

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <string>
#include <vector>
#include <algorithm>

using std::string;

#if false

// 错误解法
// 错误原因：对测试案例 "00000000" 2 5
// 找到合适的跳跃位置如下：2 4 6 8
// 我的程序会返回false，实际上是可以跳过去的，错误的原因是因为
// 每次跳跃，可以跳[i+minJump, i+maxJump]的距离，而不是判断i+minJump能不能跳过去
// 至少暴力一点，也是检查[i+minJum, i+maxJump]这个区间
// 所以我们换一种滑动窗口的方式来解决吧
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int size = s.size();
        if (size == 1) {
            return true;
        }
        if (s[size - 1] != '0') {
            return false;
        }
        int i = 0, j = 1;
        while (j < size) {
            while (j < size && s[j] != '0') {
                ++j;
            }
            if ((i + minJump <= j) && (j <= std::min(i + maxJump, size - 1))) {
                i = j;
            }
            ++j;
        }
        return i == size - 1;
    }
};

#endif

#if true

// 先来分析一下题目吧
// 设s的长度为n，我们最终要判断能否跳到s[n-1]处
// 我们可以方向递推，从n-2开始，往0走，最终只要0位置能到达，就可以返回true
// 滑动窗口的区间应该是[i+minJump, maxJump]，不妨设i+minJump为j，i+maxJump为k
// 每次向左移动的时候，我们需要删除k+1这个元素，同时添加j这个元素
// 那么我们就需要维护一个O(n)空间的数组f，f[i]表示这个位置可以到达
// 那怎么更新f[i]的值呢，只需要[j,k]这个区间 f值为true的数量大于0即可
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // 如果末尾不是字符'0'，肯定不能到达
        if (s.back() != '0') {
            return false;
        }
        int n = s.length();
        std::vector<bool> f(n, false);
        f[n - 1] = true;
        int cnt = 0;
        for (int i = n - 2; i >= 0; --i) {
            int l = i + minJump;
            int r = i + maxJump;
            if (l >= n) continue;
            if (f[l] == true) {
                ++cnt;
            }
            // 滑动窗口末端的元素如果是true，应该将cnt减一
            if (r + 1 < n && f[r + 1] == true) {
                --cnt;
            }
            if (s[i] == '0' && cnt > 0) {
                f[i] = true;
            }
        }
        return f[0];
    }
};

#endif

#if false
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
