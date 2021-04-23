//
// Created by zhangbaqing on 2021/4/23.
//
// 剑指offer18. 删除链表的节点
// https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
// 难度：easy

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

#if true

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (head == nullptr) {
            return head;
        }
        if (head->val == val) {
            return head->next;
        }
        ListNode *pPre = head;
        ListNode *pCur = head->next;
        while (pCur != nullptr) {
            if (pCur->val == val) {
                pPre->next = pCur->next;
                break;
            }
            pPre = pCur;
            pCur = pCur->next;
        }
        return head;
    }
};

#endif

#endif //LEETCODE_SOLUTION_H
