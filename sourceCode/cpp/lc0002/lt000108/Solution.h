//
// Created by zhangbaqing on 2021/5/1.
//
// 108.将有序数组转化为二叉搜索树
// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
// 难度：easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <stack>
#include <iostream>

using std::vector;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    static void inOrder(TreeNode *root) {
        std::stack<TreeNode *> s;
        while (!s.empty() || root != nullptr) {
            if (root != nullptr) {
                s.emplace(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                std::cout << root->val << " ";
                root = root->right;
            }
        }
        std::cout << std::endl;
    }
};


#if true

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        // 回忆一下，已知一颗完全二叉树所有节点的个数。怎么计算这颗树的高度呢
        // 假设有n个节点，则二叉树的高度为lgn
        // 题目要求我们将一个有序数组，转化为高度平衡的二叉搜索树
        // 那我造一颗完全二叉树，肯定是高度平衡的二叉搜索树了
        // 可以使用二分的方式创建这颗二叉树
        int size = nums.size();
        return createBst(nums, 0, size - 1);
    }

private:
    TreeNode *createBst(std::vector<int> &nums, int left, int right);
};

TreeNode *Solution::createBst(std::vector<int> &nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = createBst(nums, left, mid - 1);
    root->right = createBst(nums, mid + 1, right);
    return root;
}


#endif

#endif //LEETCODE_SOLUTION_H
