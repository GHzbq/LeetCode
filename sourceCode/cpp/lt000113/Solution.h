//
// Created by zhangbaqing on 2021/5/20.
//
// 113.路径总和II
// https://leetcode-cn.com/problems/path-sum-ii/
// medium

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

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

#if true

// 解法一： dfs
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        std::vector<int> tmpPath;
        std::vector<std::vector<int>> result;
        dfs(root, targetSum, result, tmpPath);
        return result;
    }

private:
    void dfs(TreeNode *, int, std::vector<std::vector<int>> &, std::vector<int> &);
};

void Solution::dfs(TreeNode *root,
                   int targetSum,
                   std::vector<std::vector<int>> &result,
                   std::vector<int> &tmpPath) {
    if (root == nullptr) {
        return;
    }
    if ((root->left == nullptr) && (root->right == nullptr)) {
        if (root->val == targetSum) {
            tmpPath.emplace_back(root->val);
            result.emplace_back(std::vector<int>(tmpPath));
            tmpPath.pop_back();
        }
        return;
    }
    tmpPath.emplace_back(root->val);
    dfs(root->left, targetSum - root->val, result, tmpPath);
    dfs(root->right, targetSum - root->val, result, tmpPath);
    tmpPath.pop_back();
}

#endif


#if false
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
