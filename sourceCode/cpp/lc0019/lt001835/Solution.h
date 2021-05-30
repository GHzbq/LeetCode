//
// Created by zhangbaqing on 2021/4/18.
//
// 1835. 所有数对按位与结果的异或和
// 5737.所有数对按位与结果的异或和
// https://leetcode-cn.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
// 难度：hard

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

//#if false
//// 超出时间限制
//class Solution {
//public:
//    int getXORSum(vector<int> &arr1, vector<int> &arr2) {
//        std::vector<int> tmp;
//        for (int i = 0; i < arr1.size(); ++i) {
//            for (int j = 0; j < arr2.size(); ++j) {
//                tmp.emplace_back(arr1[i] & arr2[j]);
//            }
//        }
//        int result = tmp[0];
//        for (int i = 1; i < tmp.size(); ++i) {
//            result ^= tmp[i];
//        }
//        return result;
//    }
//};
//
//#endif

#endif //LEETCODE_SOLUTION_H
