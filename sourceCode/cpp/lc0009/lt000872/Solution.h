//
// Created by zhangbaqing on 2021/5/10.
//
// 872. 叶子相似的树
// https://leetcode-cn.com/problems/leaf-similar-trees/
// easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>

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
private:
    std::vector<int> v1;
    std::vector<int> v2;
private:
    void preOrder(TreeNode *root, std::vector<int> &v) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            v.push_back(root->val);
        }
        if (root->left != nullptr) {
            preOrder(root->left, v);
        }
        if (root->right != nullptr) {
            preOrder(root->right, v);
        }
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        // 前序遍历，即可获得叶值序列
        // 然后比较两个序列是否相等喽
        v1.clear();
        v2.clear();
        preOrder(root1, v1);
        preOrder(root2, v2);
        int size = v1.size(), size2 = v2.size();
        if (size != size2) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
