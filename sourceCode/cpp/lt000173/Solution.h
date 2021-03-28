//
// Created by zhangbaqing on 2021/3/28.
//
// https://leetcode-cn.com/problems/binary-search-tree-iterator/

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


#if false
/**
 * 解法一：
 * 思路：既然只是想判断有没有下一个元素，或者获取下一个元素
 *      不考虑空间复杂度，我们可以将搜索二叉中序遍历的结果保存在一个vector里
 *      并用一个指针指向当前访问的位置
 * */
class BSTIterator {
private:
    std::vector<int> data;
    std::vector<int>::iterator cur;
public:
    BSTIterator(TreeNode *root) {
        if (nullptr == root) {
            data = std::vector<int>();
            cur = data.begin();
            return;
        }
        auto pCur = root;
        auto s = std::stack<TreeNode *>();
        while (!s.empty() || nullptr != pCur) {
            // 将左子树全部入栈
            while (nullptr != pCur) {
                s.emplace(pCur);
                pCur = pCur->left;
            }
            // 左子树遍历完成之后，出栈，遍历右子树
            if (!s.empty()) {
                pCur = s.top();
                s.pop();
                data.push_back(pCur->val);
                pCur = pCur->right;
            }
        }
        cur = data.begin();
    }

    int next() {
        return *cur++;
    }

    bool hasNext() {
        return cur != data.end();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
#endif

#if true

class BSTIterator {
private:
    std::stack<TreeNode *> s;
    TreeNode *cur;
public:
    BSTIterator(TreeNode *root) : cur(root) {}

    int next() {
        // 左子树全部入栈嘛
        while (nullptr != cur) {
            s.emplace(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        int ret = cur->val;
        cur = cur->right;
        return ret;
    }

    bool hasNext() {
        return !s.empty() || (nullptr != cur);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {

    }

    int next() {

    }

    bool hasNext() {

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
#endif

#endif //LEETCODE_SOLUTION_H
