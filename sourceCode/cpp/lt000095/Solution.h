//
// Created by zhangbaqing on 2021/3/27.
//
// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/

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

/**
 * 解法一：
 * 思路：搜索二叉的关键特性为：根节点的值，大于左子树所有节点的值，小于右子树所有节点的值，并且左右子树也为搜索二叉
 *      对长度为n的搜索二叉，假如我们枚举所有根节点的位置i，则左子树为[0, i-1]，右子树为[i+1, n]
 *      而左子树和右子树的生成，相对原问题，是一个序列长度缩小的子问题
 *      获得所有组成左右子树的序列之后，我们选取任一左子树的序列，再选取任意右子树的序列，结合根节点，都可以生成唯一的一颗搜索二叉
 * */
class Solution {
public:
    vector<TreeNode *> generateTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode *> allTrees;
        // 枚举可行根节点
        for (int i = start; i <= end; i++) {
            // 获得所有可行的左子树集合
            vector<TreeNode *> leftTrees = generateTrees(start, i - 1);

            // 获得所有可行的右子树集合
            vector<TreeNode *> rightTrees = generateTrees(i + 1, end);

            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
            for (auto &left : leftTrees) {
                for (auto &right : rightTrees) {
                    TreeNode *currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.emplace_back(currTree);
                }
            }
        }
        return allTrees;
    }

    vector<TreeNode *> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return generateTrees(1, n);
    }
};

#endif

#if false
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
