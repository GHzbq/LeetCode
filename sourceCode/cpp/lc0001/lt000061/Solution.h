//
// Created by zhangbaqing on 2021/3/27.
//
// https://leetcode-cn.com/problems/rotate-list/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#if true

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if ((nullptr == head) || (nullptr == head->next)) {
            return head;
        }
        int len = 0;
        ListNode *pCur = head;
        // 获取链表的长度
        while (nullptr != pCur) {
            ++len;
            pCur = pCur->next;
        }
        // 去掉没必要的循环
        // 1->2->3->null 循环3次，和没旋转一样，循环4次，和旋转一次一样
        k %= len;
        k = len - k;
        pCur = head;
        for (int i = 1; i < k; ++i) {
            pCur = pCur->next;
        }
        ListNode *pTail = pCur;
        while (pTail->next) {
            pTail = pTail->next;
        }
        pTail->next = head;
        head = pCur->next;
        pCur->next = nullptr;
        return head;
    }
};

#endif

#if false
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
    ListNode* rotateRight(ListNode* head, int k) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
