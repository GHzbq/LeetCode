//
// Created by zhangbaqing on 2021/4/19.
//
// 剑指offer 13.机器人的运动范围
// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
// 难度：中等

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

#if false

// 直接暴力循环试一下！
// 解答错误！！
// 解释一下为什么解法错误！
// 机器人可能因为被阻隔而过不去！！！
// 所以，即使有其他位置满足求和小于k，也走不到哪里，因为不连通嘛，走不过去
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int count = 0;
        auto sum = [](int i, int j) {
            int ret = 0;
            while (i != 0) {
                ret += i % 10;
                i /= 10;
            }
            while (j != 0) {
                ret += j % 10;
                j /= 10;
            }
            return ret;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (sum(i, j) <= k) {
                    ++count;
                }
            }
        }
        return count;
    }
};

#endif

#if false

// 我有点好奇剑指offer的解法能否通过
// 我们来测试一把

// 很遗憾，可能我抄错代码了！
int movingCountCore(bool *visited, int m, int n, int i, int j, int k);

int getDigit(int value);

bool check(bool *visited, int m, int n, int i, int j, int k);

int movingCount(int m, int n, int k) {
    if (m <= 0 || n <= 0 || k < 0) {
        return 0;
    }
    bool *visited = new bool[m * n];
    for (int i = 0; i < m * n; ++i) {
        visited[i] = false;
    }
    int count = movingCountCore(visited, m, n, 0, 0, k);
    delete[] visited;
    return count;
}

int movingCountCore(bool *visited, int m, int n, int i, int j, int k) {
    int count = 0;
    if (check(visited, m, n, i, j, k)) {
        visited[n * i + j] = true;
        count = 1 + movingCountCore(visited, m, n, i - 1, j, k)
                + movingCountCore(visited, m, n, i + 1, j, k)
                + movingCountCore(visited, m, n, i, j - 1, k)
                + movingCountCore(visited, m, n, i, j + 1, k);
    }
    return count;
}

bool check(bool *visited, int m, int n, int i, int j, int k) {
    if (i < 0 || i >= m || j < 0 || j >= n || visited[n * i + j] || (getDigit(i) + getDigit(k) > k)) {
        return false;
    }
    return true;
}

int getDigit(int value) {
    int ret = 0;
    while (value != 0) {
        ret += value % 10;
        value /= 10;
    }
    return ret;
}

#endif

#if true

// 我们可以借助12题的思路，把过不去的位置都放上障碍物吧！
// 还是官方题解靠谱！
class Solution {
private:
    int getDigit(int number) {
        int ret = 0;
        while (number != 0) {
            ret += number % 10;
            number /= 10;
        }
        return ret;
    }

public:
    int movingCount(int m, int n, int k) {
        if (m <= 0 || n <= 0 || k < 0) {
            return 0;
        }
        std::vector<std::vector<int>> vis(m, std::vector<int>(n, 0));
        int ans = 1;
        vis[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 && j == 0) || (getDigit(i) + getDigit(j) > k)) continue;
                if (i - 1 >= 0) {
                    vis[i][j] |= vis[i - 1][j];
                }
                if (j - 1 >= 0) {
                    vis[i][j] |= vis[i][j - 1];
                }
                ans += vis[i][j];
            }
        }
        return ans;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
