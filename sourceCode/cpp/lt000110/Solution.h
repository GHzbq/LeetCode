//
// Created by zhangbaqing on 2021/5/18.
//
// 110.平衡二叉树
// https://leetcode-cn.com/problems/balanced-binary-tree/
// easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <algorithm>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#if false

// 平衡二叉树：一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1 。
// 解法一： 求出每个节点左右子树的高度，判断当前节点是否平衡，再递归判断左右子树
class Solution {
public:
    bool isBalanced(TreeNode *root);

private:
    int height(TreeNode *);
};

bool Solution::isBalanced(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    if (std::abs(lHeight - rHeight) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}

int Solution::height(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    return std::max(height(root->left), height(root->right)) + 1;
}

#endif

#if true

// 解法二：自顶向下的解法，一个节点可能会被重复计算高度，造成冗余计算
//        优化一下计算高度的函数，类似于后序遍历，先判断左右子树是否平衡
//        再判断当前节点是否平衡，height函数仍返回当前节点的高度
//        如果height返回值是个非法的情况，那么我们就可以认定为这颗树不平衡
//        高度不可能是负数，那就用-1表示该子树不平衡
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return height(root) >= 0;
    }

private:
    int height(TreeNode *);
};

int Solution::height(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int lHeight = height(root->left);
    if (lHeight < 0) {
        return lHeight;
    }
    int rHeight = height(root->right);
    if (rHeight < 0) {
        return rHeight;
    }
    if (std::abs(lHeight - rHeight) > 1) {
        return -1;
    }
    return std::max(lHeight, rHeight) + 1;
}

#endif

#if false
class Solution {
public:
    bool isBalanced(TreeNode* root) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
