//
// Created by zhangbaqing on 2021/4/18.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

using std::vector;

#if true

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }
        int fast = 1, slow = 1, last = nums[0];
        while (fast < n) {
            if (nums[fast] == last) {
                ++fast;
            } else {
                last = nums[fast];
                nums[slow++] = nums[fast++];
            }
        }
        return slow;
    }
};

#endif

#if false
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
