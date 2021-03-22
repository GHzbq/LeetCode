//
// Created by zhangbaqing on 2021/3/21.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>

using std::vector;

#if false
/**
 * 解法一：
 * 分析：通过题意，我们发现这场交易，貌似只买卖一次（通过示例1可以看出）
 *      [7,1,5,3,6,4]
 *      假如我在第二天买入，第三天卖出，第四天买入，第五天卖出，这样我可以赚4+3=7块钱
 *      但是题目最终答案是6块钱
 * 思路：我么可以尝试枚举所有可以买入以及卖出的位置，并统计最大的利润
 * 结果：超出时间限制
 * */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size(), ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};
#endif

#if true

/**
 * 解法二：
 * 思路：随着遍历，判断当前这天是否是最佳买入时机（价格最低）
 *      如果是，更新最低价格；
 *      如果不是，就在这天将股票卖出，并判断是否能获取最大收益；
 *      这样经过一次遍历，即可获取到最大收益；
 * */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int size = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = 0; // 不能获取任何利润，返回0
        for (int i = 0; i < size; ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                maxProfit = std::max(maxProfit, prices[i] - minPrice);
            }
        }
        return maxProfit;
    }
};

#endif

#if false
class Solution {
public:
    int maxProfit(vector<int>& prices) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
