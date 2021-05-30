//
// Created by zhangbaqing on 2020/11/9.
//

#ifndef CPP_STUDY_SOLUTION_H
#define CPP_STUDY_SOLUTION_H

#include <vector>
#include <queue>
#include <algorithm>

using std::vector;

#if 0
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        auto result = vector<vector<int>>(K);
        // check
        if (points.empty()) {
            return result;
        }
        for (auto &point : points) {
            if (point.empty()) {
                return result;
            }
        }
        // sort
        std::sort(points.begin(), points.end(), compare);
        for (int i = 0; i < K; ++i) {
            result[i] = points[i];
        }
        return result;
    }

private:
    static bool compare(vector<int> &lPoint, vector<int> &rPoint) {
        auto l = powl(lPoint[0], 2) + powl(lPoint[1], 2);
        auto r = powl(rPoint[0], 2) + powl(rPoint[1], 2);
        return l < r;
    }
};
#endif

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        auto result = vector<vector<int>>(K);
        // check
        if (points.empty()) {
            return result;
        }
        for (auto &point : points) {
            if (point.empty()) {
                return result;
            }
        }

        // 建一个拥有K个元素的小堆
        auto compare = [](std::vector<int> &lPoint, std::vector<int> &rPoint) {
            auto l = powl(lPoint[0], 2) + powl(lPoint[1], 2);
            auto r = powl(rPoint[0], 2) + powl(rPoint[1], 2);
            return l > r;
        };
        auto q = std::priority_queue<std::vector<int>,
                std::vector<std::vector<int>>,
                decltype(compare)>(compare, points);
        for (int i = 0; i < K; ++i) {
            if (!q.empty()) {
                result[i] = q.top();
                q.pop();
            }
        }
        return result;
    }
};

#endif //CPP_STUDY_SOLUTION_H
