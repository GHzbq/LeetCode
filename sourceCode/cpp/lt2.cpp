//
// Created by will on 2020/1/14.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
    : val(x)
    , next(nullptr)
    {}
};

#if 1
// 2020.1.14
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (nullptr == l1) {
            return l2;
        }

        if (nullptr == l2) {
            return l1;
        }

        int carry = 0;
        int sum = l1->val + l2->val + carry;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* pHead = new ListNode(sum % 10);
        carry = sum / 10;
        ListNode* rear = pHead;
        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            rear->next = new ListNode(sum % 10);
            carry = sum / 10;
            rear = rear->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr) {
            sum = l1->val + carry;
            rear->next = new ListNode(sum % 10);
            carry = sum / 10;
            rear = rear->next;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            sum = l2->val + carry;
            rear->next = new ListNode(sum % 10);
            carry = sum / 10;
            rear = rear->next;
            l2 = l2->next;
        }

        if (carry > 0) {
            rear->next = new ListNode(carry);
            carry = 0;
        }

        return pHead;
    }
};

#endif

#if 0

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }

        int carry = 0; // 记录进位
        int sum = 0;
        ListNode* head = new ListNode(0);
        ListNode* pnew = nullptr;
        ListNode* tail = head;
        while (l1 && l2) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            pnew = new ListNode(sum);
            tail->next = pnew;
            tail = pnew;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            pnew = new ListNode(sum);
            tail->next = pnew;
            tail = pnew;
            l1 = l1->next;
        }

        while (l2) {
            sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            pnew = new ListNode(sum);
            tail->next = pnew;
            tail = pnew;
            l2 = l2->next;
        }

        if (carry != 0) {
            pnew = new ListNode(carry);
            tail->next = pnew;
            tail = pnew;
            carry = 0;
        }

        pnew = head->next;
        delete head;
        return pnew;
    }
};

#endif