//
// Created by zhangbaqing on 2021/3/23.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if false
/**
 * 解法一：
 * 思路：return nums[left]+nums[left+1]+nums[left+2]+nums[right]
 * */
class NumArray {
private:
    std::vector<int> &data;
public:
    NumArray(vector<int> &nums)
            : data(nums) {}

    int sumRange(int left, int right) {
        int result = 0;
        for (int i = left; i < data.size() && i <= right; ++i) {
            result += data[i];
        }
        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
#endif


#if true

/**
 * 解法二：
 * 思路：提前处理好数据呗！
 *      return sum[right]-sum[left]+nums[left];
 * */
class NumArray {
private:
    std::vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        int size = nums.size();
        sum.reserve(size + 1);
        int result = 0;
        for (int i = 0; i < size; ++i) {
            sum.push_back(result);
            result += nums[i];
        }
        sum.push_back(result);
    }

    int sumRange(int left, int right) {
        if (0 <= left && left <= right && right < sum.size()) {
            return sum[right + 1] - sum[left];
        }
        return 0;
    }
};

#endif

#if false
class NumArray {
public:
    NumArray(vector<int>& nums) {

    }

    int sumRange(int left, int right) {

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
#endif

#endif //LEETCODE_SOLUTION_H
