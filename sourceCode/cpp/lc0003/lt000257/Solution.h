//
// Created by zhangbaqing on 2021/4/28.
//
// 257. 二叉树的所有路径
// https://leetcode-cn.com/problems/binary-tree-paths/
// 难度： easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <string>

using std::vector;
using std::string;


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
    vector<string> binaryTreePaths(TreeNode *root) {
        // 写个DFS叭
        std::vector<std::string> paths;
        dfs(root, std::string(), paths);
        return paths;
    }

private:
    void dfs(TreeNode *root, std::string path, std::vector<std::string> &paths);
};

void Solution::dfs(TreeNode *root, std::string path, std::vector<std::string> &paths) {
    if (root == nullptr) {
        return;
    }
    path += std::to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) {
        paths.push_back(path);
        return;
    }
    path += "->";
    if (root->left != nullptr) {
        dfs(root->left, path, paths);
    }
    if (root->right != nullptr) {
        dfs(root->right, path, paths);
    }
}

#endif

#endif //LEETCODE_SOLUTION_H
