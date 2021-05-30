//
// Created by zhangbaqing on 2021/3/26.
//
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

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

/**
 * 解法一：
 * 思路：遇见比自己小的或者相等的，删~~
 * */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if ((nullptr == head) || (nullptr == head->next)) {
            return head;
        }
        // 1 -> 1 -> 2 -> null
        ListNode *pCur = head;
        while (nullptr != pCur->next) {
            if (pCur->next->val <= pCur->val) {
                pCur->next = pCur->next->next;
                continue;
            }
            pCur = pCur->next;
        }
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
    ListNode* deleteDuplicates(ListNode* head) {

    }
};
#endif

#endif //LEETCODE_SOLUTION_H
