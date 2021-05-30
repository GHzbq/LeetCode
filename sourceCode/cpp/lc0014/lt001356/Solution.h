//
// Created by zhangbaqing on 2020/11/7.
//

#ifndef CPP_STUDY_SOLUTION_H
#define CPP_STUDY_SOLUTION_H

#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<int> sortByBits(std::vector<int> &arr) {
        if (arr.empty()) {
            return arr;
        }

        std::sort(arr.begin(), arr.end(), compare);
        return arr;
    }

private:
    static int compare(int left, int right) {
        int leftCount = numberBinaryOneCount(left);
        int rightCount = numberBinaryOneCount(right);
        if (leftCount == rightCount) {
            return left < right;
        }
        return leftCount < rightCount;
    }


    static int numberBinaryOneCount(int num) {
        int count = 0;
        while ((num = num & (num - 1))) {
            ++count;
        }
        return ++count;
    }
};


#endif //CPP_STUDY_SOLUTION_H
