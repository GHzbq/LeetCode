//
// Created by zhangbaqing on 2021/5/19.
//
// 111.二叉树的最小深度
// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
// easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <algorithm>
#include <cstdint>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#if false

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return depth(root, 0);
    }

private:
    int depth(TreeNode *, int);
};

int Solution::depth(TreeNode *root, int num) {
    if ((root->left == nullptr) && (root->right == nullptr)) {
        return num + 1;
    }
    int lDepth = (root->left == nullptr) ? INT_MAX : depth(root->left, num + 1);
    int rDepth = (root->right == nullptr) ? INT_MAX : depth(root->right, num + 1);
    return std::min(lDepth, rDepth);
}

#endif

#if true

class Solution {
public:
    int minDepth(TreeNode *root);
};

int Solution::minDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    if ((root->left == nullptr) && (root->right == nullptr)) {
        return 1;
    }
    int depth = INT_MAX;
    if (root->left != nullptr) {
        depth = std::min(minDepth(root->left), depth);
    }
    if (root->right != nullptr) {
        depth = std::min(minDepth(root->right), depth);
    }
    return depth + 1;
}

#endif

#if false
class Solution {
public:
    int minDepth(TreeNode* root) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
