#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #if 1
 // 解法一：翻转链表
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        return reverseList(assistAdd(l1, l2));
    }
private:
    ListNode* reverseList(ListNode* head) {
        // 链表翻转
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pCur = head;
        ListNode* pPre = nullptr;
        ListNode* next = head->next;

        // 1 -> 2 -> nullptr
        while(pCur != nullptr) {
            next = pCur->next;
            pCur->next = pPre;
            pPre = pCur;
            pCur = next;
        }
        return pPre;
    }

    ListNode* assistAdd(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int current = 0;
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while(l1 != nullptr && l2 != nullptr) {
            current = l1->val + l2->val + carry;
            tail->next = new ListNode(current % 10);
            tail = tail->next;
            carry = current / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr) {
            current = l1->val + carry;
            tail->next = new ListNode(current % 10) ;
            carry = current / 10;
            tail = tail->next;
            l1 = l1->next;
        }

        while(l2 != nullptr) {
            current = l2->val + carry;
            tail->next = new ListNode(current%10) ;
            carry = current / 10;
            tail = tail->next;
            l2 = l2->next;
        }

        if (carry != 0) {
            tail->next = new ListNode(carry) ;
            carry = 0;
            tail = tail->next;
        }

        ListNode* ret = head->next;
        delete head;
        return ret;
    }
};
#endif
