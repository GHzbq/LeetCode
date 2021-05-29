//
// Created by zhangbaqing on 2020/11/20.
//
// https://leetcode-cn.com/problems/insertion-sort-list/
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};


#if 1

/**
 * 解法一：
 *
 * 暴力一点，每次找合适的位置，插入节点
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        // 链表为空或者链表只有一个节点，直接返回
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto pHead = new ListNode(0);
        pHead->next = head;
        auto pCur = head->next;
        auto pSortedLast = head;
        auto pPos = head;
        while (pCur != nullptr) {
            if (pCur->val >= pSortedLast->val) {
                // 此时是有序的，不需要移动
                pSortedLast = pSortedLast->next;
            } else {
                // 需要找合适位置
                pPos = pHead;
                while (pPos->next->val <= pCur->val) {
                    pPos = pPos->next;
                }
                pSortedLast->next = pCur->next;
                pCur->next = pPos->next;
                pPos->next = pCur;
            }
            pCur = pSortedLast->next;
        }
        head = pHead->next;
        delete pHead;
        return head;
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
