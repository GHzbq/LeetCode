//
// Created by zhangbaqing on 2021/4/26.
//
// 1011. 在D天送达包裹的能力
// https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
// 难度：中等

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

#if true

class Solution {
public:
    int shipWithinDays(vector<int> &weights, int D) {
        int left = *std::max_element(weights.begin(), weights.end());
        int right = std::accumulate(weights.begin(), weights.end(), 0);
        // 在[left, right] 这个区间内，一定可以将货物全部运走
        // 但是使用left，花费的天数可能超过D
        // 如果使用right，未必是最低最低运载能力
        // 所以考虑使用二分，
        // 找到一个合适的运载能力，恰好可以在D天内将所有货物运走，同时具有最低的运载能力
        //
        // 又回到了哪个经典问题，这里的判断，要不要加上等号呢？
        // 假如我们有[1,2,3]这些货物，需要在1天内运完，
        // 那么运载能力可能为[3, 4, 5, 6]
        // 模拟二分，第一次取到4，需要两天，不满足，将left设置为mid+1
        // 第二次取5，还是需要2天，将left设置为mid+1
        // 经过第二次二分，left已经放到了right的位置，同时left也是我们想要的答案
        while (left < right) {
            int mid = left + (right - left) / 2;
            int sum = 0, need = 1;
            for (int weight : weights) {
                if (sum + weight > mid) {
                    ++need;
                    sum = weight;
                } else {
                    sum += weight;
                }
            }
            if (need > D) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
