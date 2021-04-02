package com.zhang.interview1721;

// https://leetcode-cn.com/problems/volume-of-histogram-lcci/
public class Solution {
    public int trap(int[] height) {
        int size = height.length;
        if (size <= 1) {
            return 0;
        }
        int[] leftMax = new int[size];
        int[] rightMax = new int[size];
        leftMax[0] = height[0];
        rightMax[size - 1] = height[size - 1];
        for (int i = 1; i < size; ++i) {
            leftMax[i] = Math.max(leftMax[i - 1], height[i]);
        }
        for (int i = size - 2; i >= 0; --i) {
            rightMax[i] = Math.max(rightMax[i + 1], height[i]);
        }
        int result = 0;
        for (int i = 0; i < size; ++i) {
            result += Math.min(leftMax[i], rightMax[i]) - height[i];
        }
        return result;
    }
}
