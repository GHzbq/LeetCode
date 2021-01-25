//
// Created by zhangbaqing on 2020/11/21.
//
// https://leetcode-cn.com/problems/sort-list/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H


#include "../../../../../../../dev/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.25.28610/include/algorithm"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#if 0

// 解法一：冒泡排序
// 超出时间限制！！！！
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        // 链表为空或者只有一个元素，直接返回head
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        for (auto i = head; i != nullptr; i = i->next) {
            for (auto j = i->next; j != nullptr; j = j->next) {
                if (j->val < i->val) {
                    std::swap(j->val, i->val);
                }
            }
        }
        return head;
    }
};

#endif

#if 1

// 解法二：交换排序
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        // 链表为空或者只有一个元素，直接返回head
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        for (auto i = head; i != nullptr; i = i->next) {
            for (auto)
        }
    }
};

#endif

#if 0
// 默认代码模板
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
