//
// Created by zhangbaqing on 2020/11/8.
//

#ifndef CPP_STUDY_SOLUTION_H
#define CPP_STUDY_SOLUTION_H

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int size = prices.size();
        // dp[i][0] 表示第i天交易完成之后，手里没有股票的最大收益
        // dp[i][1] 表示第i天交易完成之后，手里持有一只股票的最大收益
        auto dp = std::vector<std::vector<int>>(size, std::vector<int>(2));
        // init
        dp[0][0] = 0;
        dp[0][1] = dp[0][0] - prices[0];
        for (int i = 1; i < size; ++i) {
            // dp[i-1][0]前一天没有持有股票
            // dp[i-1][1] + prices[i] 表示前一天持有股票，今天卖了
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // dp[i-1][0]-prices[i] 表示前一天没有持有股票，今天买一股
            // dp[i-1][1] 表示前一天持有股票，并且今天不卖，继续持股
            dp[i][1] = std::max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        }
        return dp[size - 1][0];
    }
};

#endif //CPP_STUDY_SOLUTION_H
