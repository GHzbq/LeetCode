//
// Created by zhangbaqing on 2021/5/18.
//
// 94.二叉树的中序遍历
// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <stack>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#if false

// 递归！
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> ret;
        inOrder(root, ret);
        return ret;
    }

private:
    void inOrder(TreeNode *, std::vector<int> &);
};

void Solution::inOrder(TreeNode *root, std::vector<int> &in) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left, in);
    in.push_back(root->val);
    inOrder(root->right, in);
}

#endif

#if true

// 借助栈，迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        std::stack<TreeNode *> s;
        std::vector<int> in;
        while (!s.empty() || root != nullptr) {
            if (root != nullptr) {
                s.emplace(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                in.push_back(root->val);
                root = root->right;
            }
        }
        return in;
    }
};

#endif

#if false
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
