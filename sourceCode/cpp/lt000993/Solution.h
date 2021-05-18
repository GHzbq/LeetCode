//
// Created by zhangbaqing on 2021/5/18.
//
// 993.二叉树的堂兄弟节点
// https://leetcode-cn.com/problems/cousins-in-binary-tree/
// easy

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

// 审题：
//      满足堂兄弟的节点的定义：1) 深度相同 2) 父节点不同
// 解法一：深度优先遍历，找到x的父节点和y的父节点，并记录x和y的深度
//       如何统计深度，每次递归(不管是往左子树还是右子树)，都让depth+1
//       为了方便统计父节点，需要我们在递归的时候，将当前节点作为参数传下去
//       所以dfs的参数，至少是4个，分别是
//       1) TreeNode* root   // 根节点
//       2) TreeNode* father // 当前根结点的父节点
//       3) int depth        // 表示当前深度
//       4) int target       // 目标值
//       考虑特殊情况：
//       1) 除了根节点，father传nullptr之外，别的都不为nullptr
//       2) 由于每个节点的值是唯一的，我们可以直接用节点的值来作为父节点
//       3) 找不到节点的时候，可以用-1标记父节点
//       4) 递归需要返回两个值，一个是父节点，一个是深度，且他们都是int，直接搞一个vector<int>就可以了
//
class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        std::vector<int> &&retX = dfs(root, nullptr, 0, x);
        std::vector<int> &&retY = dfs(root, nullptr, 0, y);
        return (retX[1] == retY[1]) && (retX[0] != retY[0]);
    }

private:
    std::vector<int> dfs(TreeNode *, TreeNode *, int, int);
};

// 对于这些递归的函数，在类外实现吧，否则可能会内联
std::vector<int> Solution::dfs(TreeNode *root, TreeNode *father, int depth, int target) {
    // 递归出口
    if (root == nullptr) {
        return std::vector<int>({-1, -1});
    }
    // 找到目标值
    if (root->val == target) {
        return std::vector<int>({(father == nullptr ? -1 : father->val), depth});
    }
    std::vector<int> &&ret = dfs(root->left, root, depth + 1, target);
    // 从左子树找到目标值，返回
    if (ret[0] != -1) {
        return ret;
    }
    // 去右子树找目标值
    return dfs(root->right, root, depth + 1, target);
}

#endif

#endif //LEETCODE_SOLUTION_H
