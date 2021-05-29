//
// Created by zhangbaqing on 2021/3/25.
//
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <stack>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#if false

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);

        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

#endif

#if true

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // 如果链表为空或者只有一个元素，直接返回head
        if ((nullptr == head) || (nullptr == head->next)) {
            return head;
        }
        // 考虑到可能会移动头节点的指向，我们创建一个哑节点
        ListNode *dumpNode = new ListNode(-102, head);
        ListNode *pCur = dumpNode;
        while ((nullptr != pCur->next) && (nullptr != pCur->next->next)) {
            if (pCur->next->val == pCur->next->next->val) {
                int value = pCur->next->val;
                // -102 ->  1 -> 1 -> 2 -> 2 -> 3 -> null
                // pCur
                // 这里需要将所有值为value的全部删除
                while ((nullptr != pCur->next) && (pCur->next->val == value)) {
                    pCur->next = pCur->next->next;
                }
            } else {
                // -102 -> 1 -> 3 -> 3 -> 3 -> null
                //        pCur
                pCur = pCur->next;
            }
        }
        head = dumpNode->next;
        delete dumpNode;
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
