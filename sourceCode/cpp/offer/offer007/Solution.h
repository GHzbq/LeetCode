//
// Created by zhangbaqing on 2021/4/14.
//
// 剑指offer07 重建二叉树
// https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <unordered_map>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if true

// 二叉树前序遍历，每次访问的节点，一定是某颗子树的根节点
// 而中序遍历，需要等这颗子树的左子树遍历结束之后，才能访问这颗子树的根节点，
// 根据题意，二叉树中没有重复的元素
// 依次访问前序序列，每次访问，在中序序列中找到这个元素，
// 那么这个元素左边的子序列，就是左子树的所有元素
// 右边的子序列就是右子树的所有元素
//
// 优化：为避免在中序遍历中反复寻找某个子树根节点在中序序列中的位置，可以将中序序列处理一下
//      保存在map里，以元素的值为key，以元素在中序序列中的位置为value
//
// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
class Solution {
private:
    // key为中序序列中的元素，value为元素在中序序列的索引
    std::unordered_map<int, int> m;

    TreeNode *helper(const std::vector<int> &, int, int,
                     const std::vector<int> &, int, int);

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || preorder.size() != inorder.size()) {
            return nullptr;
        }
        // 二叉树节点的个数！
        int n = preorder.size();
        if (n == 1) {
            return new TreeNode(preorder[0]);
        }
        for (int i = 0; i < n; ++i) {
            m[inorder[i]] = i;
        }
        return helper(preorder, 0, n - 1,
                      inorder, 0, n - 1);
    }
};

TreeNode *Solution::helper(const std::vector<int> &preOrder, int preLeft, int preRight,
                           const std::vector<int> &inOrder, int inLeft, int inRight) {
    if (preLeft > preRight) {
        return nullptr;
    }
    int rootVal = preOrder[preLeft];
    int inOrderPos = m[rootVal];
    TreeNode *root = new TreeNode(rootVal);
    int leftSubSize = inOrderPos - inLeft;
    root->left = helper(preOrder, preLeft + 1, preLeft + leftSubSize,
                        inOrder, inLeft, inOrderPos - 1);
    root->right = helper(preOrder, preLeft + leftSubSize + 1, preRight,
                         inOrder, inOrderPos + 1, inRight);
    return root;
}

#endif

#if false
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
