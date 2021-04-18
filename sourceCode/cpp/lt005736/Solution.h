//
// Created by zhangbaqing on 2021/4/18.
//
// 5736.单线程CPU
// https://leetcode-cn.com/problems/single-threaded-cpu/
// 难度：中等

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <numeric>

using std::vector;
using std::pair;
using std::iota;
using std::max;
using std::greater;
using std::priority_queue;

//#if false
//// 挑战失败版本！！！
//class Task {
//public:
//    int en;
//    int pro;
//    int in;
//
//    Task(int en, int pro, int in) : en(en), pro(pro), in(in) {}
//};
//
//class Solution {
//public:
//    vector<int> getOrder(vector<vector<int>> &tasks) {
//        // 先按进入队列时间排序，再按执行时间排序
//        auto cmp = [](const Task &left, const Task &right) {
//            if (left.en < right.en) {
//                return true;
//            } else if (left.en > right.en) {
//                return false;
//            } else {
//                return left.pro <= right.pro;
//            }
//        };
//        auto cmp2 = [&cmp](const Task &left, const Task &right) {
//            return !cmp(left, right);
//        };
//        auto cmp3 = [](const std::vector<int> &left,
//                       const std::vector<int> &right) {
//            if (left[0] < right[0]) {
//                return true;
//            } else if (left[0] > right[0]) {
//                return false;
//            } else {
//                return left[1] <= right[1];
//            }
//        };
//        std::sort(tasks.begin(), tasks.end(), cmp3);
//        for (auto &vec : tasks) {
//            std::cout << vec[0] << " " << vec[1] << std::endl;
//        }
//        auto s = std::priority_queue<Task, std::vector<Task>, decltype(cmp2)>(cmp2);
//        for (int i = 0; i < tasks.size(); ++i) {
//            s.emplace(tasks[i][0], tasks[i][1], i);
//        }
//        std::vector<int> res;
//        while (!s.empty()) {
//            res.emplace_back(s.top().in);
//            s.pop();
//        }
//        return res;
//    }
//};
//
//#endif

#if true

class Solution {
private:
    using PII = pair<int, int>;
    using LL = long long;

public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        int n = tasks.size();
        vector<int> indices(n);
        // iota函数可以以后置自增的方式，填充[begin, end)区间，自增初始值由第三个参数指定
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return tasks[i][0] < tasks[j][0];
        });

        vector<int> ans;
        // 优先队列
        // pair重载了>，首先判断key，然后判断value
        // return (left.key > right.key) || (!(left.key > right.key) && (left.value > right.value))
        // 我们期望创建一个小堆，所以用greater
        priority_queue<PII, vector<PII>, greater<PII>> q;
        // 时间戳
        LL timestamp = 0;
        // 数组上遍历的指针
        int ptr = 0;

        for (int i = 0; i < n; ++i) {
            // 如果没有可以执行的任务，直接快进
            if (q.empty()) {
                timestamp = max(timestamp, (LL) tasks[indices[ptr]][0]);
            }
            // 将所有小于等于时间戳的任务放入优先队列
            while (ptr < n && tasks[indices[ptr]][0] <= timestamp) {
                q.emplace(tasks[indices[ptr]][1], indices[ptr]);
                ++ptr;
            }
            // 选择处理时间最小的任务
            auto top = q.top();
            timestamp += top.first;
            ans.push_back(top.second);
            q.pop();
        }

        return ans;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
