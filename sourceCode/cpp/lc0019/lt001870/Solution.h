//
// Created by zhangbaqing on 2021/5/23.
//
// 1870. 准时到达的列车最小时速
// 5764.准时到达的列车最小时速
// https://leetcode-cn.com/problems/minimum-speed-to-arrive-on-time/
// medium

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <cmath>

using std::vector;

#if true

// 通过二分，查找最短通勤时间
// right上限为10^7
class Solution {
public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        int n = dist.size();
        // 将时间化为整数
        long long hr = std::llround(hour * 100);
        // 时间必须大于路程段数减一
        if (hr <= (n - 1) * 100) {
            return -1;
        }
        int l = 1;
        int r = 1e7;
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long t = 0;
            // 前n-1段中第i段贡献的时间：ceil(dist[i] / mid);
            for (int i = 0; i < n - 1; ++i) {
                t += (dist[i] - 1) / mid + 1;
            }
            // 最后一段贡献的时间
            t *= mid;
            t += dist[n - 1];
            if (t * 100 <= hr * mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
