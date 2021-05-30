//
// Created by zhangbaqing on 2021/5/1.
//
// 101.对称二叉树
// https://leetcode-cn.com/problems/symmetric-tree/
// 难度：easy

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

// [1,2,2,3,4,4,3]
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // 先来分析一波题意叭
        // 一颗对称二叉树
        // 左子树和右子树镜像对称
        // 左右子树，应该也是一样的定义叭
        // 递归
        // 不妨用两个指针，一个指向左子树，一个指向右子树
        // 如果指针所指向的节点的值相同
        // 那么就可以 判断左节点的左子树和右节点的右子树
        // 并且判断左节点的右子树和右节点的左子树
        // 都为对称二叉树的话，返回true
        return helper(root, root);
    }

private:
    bool helper(TreeNode *pLeft, TreeNode *pRight);
};

bool Solution::helper(TreeNode *pLeft, TreeNode *pRight) {
    // 左右子树都为null
    if ((pLeft == nullptr) && (pRight == nullptr)) {
        return true;
    }
    // 有一个指针为null 肯定不是对称二叉树
    if ((pLeft == nullptr) || (pRight == nullptr)) {
        return false;
    }
    return (pLeft->val == pRight->val) &&
           helper(pLeft->left, pRight->right) &&
           helper(pLeft->right, pRight->left);
}

#endif

#endif //LEETCODE_SOLUTION_H
