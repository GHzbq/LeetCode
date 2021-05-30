//
// Created by zhangbaqing on 2021/4/25.
//
// 897.递增顺序搜索树
// https://leetcode-cn.com/problems/increasing-order-search-tree/
// 难度：easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
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

// 中序遍历二叉搜索树
class Solution {
private:
    std::vector<TreeNode *> v;
public:
    TreeNode *increasingBST(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        v.clear();
        TreeNode *pCur = root;
        std::stack<TreeNode *> s;
        while (!s.empty() || pCur != nullptr) {
            if (pCur != nullptr) {
                s.emplace(pCur);
                pCur = pCur->left;
            } else {
                pCur = s.top();
                s.pop();
                v.emplace_back(pCur);
                pCur = pCur->right;
            }
        }
        auto it = v.begin();
        root = pCur = *it++;
        pCur->left = nullptr;
        for (; it != v.end(); ++it) {
            pCur->right = *it;
            pCur = pCur->right;
            pCur->left = nullptr;
        }
        return root;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
