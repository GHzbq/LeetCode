//
// Created by zhangbaqing on 2021/5/18.
//
// 110.平衡二叉树
// https://leetcode-cn.com/problems/balanced-binary-tree/
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

class Solution {
public:
    bool isBalanced(TreeNode *root) {

    }
};

#endif


#if false
class Solution {
public:
    bool isBalanced(TreeNode* root) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
