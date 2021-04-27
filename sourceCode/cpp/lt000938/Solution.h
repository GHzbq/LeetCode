//
// Created by zhangbaqing on 2021/4/27.
//
// 938. 二叉搜索树的范围和
// https://leetcode-cn.com/problems/range-sum-of-bst/
// 难度：easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <stack>

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
    int rangeSumBST(TreeNode *root, int low, int high) {
        // 中序遍历呗！
        std::stack<TreeNode *> s;
        TreeNode *pCur = root;
        int ret = 0;
        while (!s.empty() || pCur != nullptr) {
            if (pCur != nullptr) {
                s.emplace(pCur);
                pCur = pCur->left;
            } else {
                pCur = s.top();
                s.pop();
                if (pCur->val >= low && pCur->val <= high) {
                    ret += pCur->val;
                }
                pCur = pCur->right;
            }
        }
        return ret;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
