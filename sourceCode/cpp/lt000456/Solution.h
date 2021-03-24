//
// Created by zhangbaqing on 2021/3/24.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <set>
#include <algorithm>

using std::vector;
using std::multiset;
using std::min;

#if true

/**
 *  题目描述：若i<j<k且nums[i]<nums[k]<nums[j],则返回true
 *  解法一：
 *  思路：j的位置其实将nums分为3个部分，分别是nums[0]~nums[j-1], nums[j], nums[j+1]~nums[nums.size()-1]
 *       显然，i应该在[0, j-1]这个范围内，为了更方便的找到结果，我们应该使nums[i]的值尽量小
 *       k应该在[j+1, nums.size)范围内，我们在nums[j+1]~nums[nums.size()-1]这个范围选取一个最小的一个大于nums[i]的数
 *       如果nums[k]<nums[j]
 *       那么我们就可以返回true了
 * */
class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }

        // 左侧最小值
        int numsI = nums[0];
        // 右侧所有元素
        // 这里不能使用set，因为会删除元素，相同元素可能有多个，删了就没了
        multiset<int> right_all;

        for (int k = 2; k < n; ++k) {
            right_all.insert(nums[k]);
        }

        // 枚举所有的j
        for (int j = 1; j < n - 1; ++j) {
            if (numsI < nums[j]) {
                // upper_bound: returns an iterator to the first element greater than the given key
                // 在nums[j+1]~nums[nums.size()-1]范围选取一个最小的严格大于nums[i]的数，来作为num[k]
                auto k = right_all.upper_bound(numsI);
                // 如果找到了这么一个nums[k]，并且nums[k] < nums[j]，返回true
                if (k != right_all.end() && *k < nums[j]) {
                    return true;
                }
            }
            // 即时更新numsI，保证numsI是nums[0]~nums[j-1]中最小的元素
            numsI = min(numsI, nums[j]);
            // 将nums[j+1]从right_all中移除
            // nums[j+1]一定在right_all中，不需要担心程序抛异常
            right_all.erase(right_all.find(nums[j + 1]));
        }

        return false;
    }
};

#endif


#if false
class Solution {
public:
    bool find132pattern(vector<int>& nums) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
