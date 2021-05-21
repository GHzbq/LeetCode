//
// Created by zhangbaqing on 2021/5/20.
//
// 112.路径总和
// https://leetcode-cn.com/problems/path-sum/
// easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#if true

// 解法一：递归
//       可以转化为子问题，dfs，直到走到叶子节点，判断targetNum是否为0
class Solution {
public:
    bool hasPathSum(TreeNode *root, int targetSum);
};

bool Solution::hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
        return false;
    }
    if ((root->left == nullptr) && (root->right == nullptr)) {
        return targetSum == root->val;
    }
    bool ret = false;
    if (root->left != nullptr) {
        ret = hasPathSum(root->left, targetSum - root->val);
    }
    if (root->right != nullptr) {
        ret = ret == true ? true : hasPathSum(root->right, targetSum - root->val);
    }
    return ret;
}

#endif

#if false
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
