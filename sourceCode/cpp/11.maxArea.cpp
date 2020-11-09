/**
 * https://leetcode-cn.com/problems/container-with-most-water/
 * */
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxarea = 0;
        int left = 0;
        int right = static_cast<int>(height.size())-1;
        while(left < right)
        {
            maxarea = std::max(maxarea, std::min(height[left], height[right]) * (right - left));
            if(height[left] < height[right])
                ++left;
            else
                --right;
        }
        return maxarea;
    }
};
