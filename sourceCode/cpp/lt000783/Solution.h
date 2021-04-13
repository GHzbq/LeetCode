//
// Created by zhangbaqing on 2021/4/13.
//
// https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <stack>
#include <algorithm>


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
    int minDiffInBST(TreeNode *root) {
        std::stack<TreeNode *> s;
        int minDiff = INT_MAX, pre = INT_MAX;
        bool first = true;
        TreeNode *pCur = root;
        while ((pCur != nullptr) || !s.empty()) {
            if (pCur != nullptr) {
                s.emplace(pCur);
                pCur = pCur->left;
            } else {
                pCur = s.top();
                s.pop();
                if (first) {
                    first = false;
                } else {
                    minDiff = std::min(minDiff, pCur->val - pre);
                }
                pre = pCur->val;
                pCur = pCur->right;
            }
        }
        return minDiff;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
