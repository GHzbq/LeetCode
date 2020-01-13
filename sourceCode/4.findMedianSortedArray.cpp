/**
 * 4. 寻找两个有序数组的中位数
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * */
#include <iostream>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // 也就是说 这个题目要求合并两个有序数组？
        // 要求的时间复杂度为 O(log(m+n))
        int m = static_cast<int>(nums1.size());
        int n = static_cast<int>(nums2.size());
        std::vector<int> temp;
        double result = 0;
        for(int i = 0, j = 0; (i < m || j < n); )
        {
            if( (i<m) && ( (j>=n) || (nums1[i] <= nums2[j]) ))
            {
                temp.push_back(nums1[i]);
                ++i;
            }

            if( (j < n) && ( (i>= m) || (nums2[j] <= nums1[i]) ))
            {
                temp.push_back(nums2[j]);
                ++j;
            }
        }

        // 次数序列长度为偶数
        if((m+n)%2 == 0)
        {
            int right = (m+n) / 2;
            int left = right - 1;
            result = (temp[left] + temp[right]) / 2.0;
        }
        else
        {
            result = temp[(m+n)/2];
        }

        return result;
    }
};
