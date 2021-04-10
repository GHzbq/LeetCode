//
// Created by zhangbaqing on 2021/4/10.
//
// https://leetcode-cn.com/problems/ugly-number/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#if true

class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) {
            return false;
        }
        while (n != 1) {
            if (n % 5 == 0) {
                n /= 5;
            } else if (n % 3 == 0) {
                n /= 3;
            } else if (n % 2 == 0) {
                n /= 2;
            } else {
                return false;
            }
        }
        return true;
    }
};

#endif

#if false
class Solution {
public:
    bool isUgly(int n) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
