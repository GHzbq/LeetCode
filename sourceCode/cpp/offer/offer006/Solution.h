//
// Created by zhangbaqing on 2021/4/13.
//
// 剑指offer06 逆序打印链表
// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <stack>

using std::vector;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


#if false

// 顺序遍历链表
// 最后将数组逆置
class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        std::vector<int> result;
        while (head != nullptr) {
            result.push_back(head->val);
            head = head->next;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

#endif

#if false

// 借助栈，逆序遍历链表
class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        std::stack<int> s;
        while (head != nullptr) {
            s.emplace(head->val);
            head = head->next;
        }
        std::vector<int> result(s.size());
        auto pos = result.begin();
        while (!s.empty()) {
            *pos = s.top();
            s.pop();
            ++pos;
        }
        return result;
    }
};

#endif

#if true

// 递归
class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        std::vector<int> result;
        helper(head, result);
        return result;
    }

private:
    void helper(ListNode *, std::vector<int> &);
};

void Solution::helper(ListNode *head, std::vector<int> &result) {
    if (head == nullptr) {
        return;
    }
    helper(head->next, result);
    result.push_back(head->val);
}

#endif

#if false
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
