//
// Created by zhangbaqing on 2021/4/11.
//
// https://leetcode-cn.com/problems/find-the-winner-of-the-circular-game/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <list>
#include <iterator>

#if true

class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n < 1) {
            return n;
        }
        std::list<int> circle(n);
        int m = 0;
        for (auto it = circle.begin(); it != circle.end(); ++it) {
            *it = ++m;
        }
        int count = 0, i = 0;
        auto pos = circle.begin();
        while (circle.size() > 1) {
            // pos = std::advance(circle.begin(), i);
            pos = circle.begin();
            while (i-- > 0) {
                ++pos;
                if (pos == circle.end()) {
                    pos = circle.begin();
                }
            }
            m = *pos;
            for (count = 1; count < k; ++count) {
                if (pos == circle.end()) {
                    pos = circle.begin();
                }
                ++pos;
            }
            if (pos == circle.end()) {
                pos = circle.begin();
                ++count;
            }
            // i = pos - circle.begin();
            i = std::distance(circle.begin(), pos);
            m = *pos;
            circle.erase(pos);
        }
        return circle.front();
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
