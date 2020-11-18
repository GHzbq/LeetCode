//
// Created by zhangbaqing on 2020/11/29.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <algorithm>

#if 1

class Solution {
public:
    int largestPerimeter(std::vector<int> &A) {
        int result = 0;
        int l = 0;
        if (A.empty() || A.size() < 3) {
            return result;
        }
        for (int i = 0; i < A.size() - 2; ++i) {
            for (int j = 1; j < A.size() - 1; ++j) {
                for (int k = 2; k < A.size(); ++k) {
                    if ((A[i] > 0) && (A[j] > 0) && (A[k] > 0) &&
                        (A[i] + A[j] > A[k]) && (A[i] - A[j] < A[k])) {
                        l = A[i] + A[j] + A[k];
                        result = std::max(result, l);
                    }
                }
            }
        }
        return result;
    }
};

#endif

#if 0
// 默认代码模板
class Solution {
public:
    int largestPerimeter(vector<int>& A) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
