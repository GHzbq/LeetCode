//
// Created by zhangbaqing on 2020/11/24.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#if 1

// 解法一：递归求解
//       计算左子树的节点+计算右子树的节点
class Solution {
public:
    int countNodes(TreeNode *root);
};

int Solution::countNodes(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

#endif

#if 0
// 默认代码模板
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
