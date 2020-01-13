/**
 * 2. 两数相加
 * https://leetcode-cn.com/problems/add-two-numbers/
 * */
#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/* */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if(!l1 && !l2)
		{
			return nullptr;
		}

		ListNode* head = new ListNode(0);
		ListNode* newNode = nullptr;
		ListNode* pcur = head;
		int carry = 0;
		int res = 0;
		while(l1 && l2)
		{
			res = l1->val + l2->val + carry;
			carry = res / 10;
			newNode = new ListNode(res % 10);
			pcur->next = newNode;
			pcur = pcur->next;
			l1 = l1->next;
			l2 = l2->next;
		}

		// 假如 l1 更长一点
		while(l1)
		{
			res = l1->val + carry;
			carry = res / 10;
			newNode = new ListNode(res%10);
			pcur->next = newNode;
			pcur = pcur->next;
			l1 = l1->next;
		}

		// 假如 l2 更长一点
		while(l2)
		{
			res = l2->val + carry;
			carry = res / 10;
			newNode = new ListNode(res % 10);
			pcur->next = newNode;
			pcur = pcur->next;
			l2 = l2->next;
		}

		if(carry != 0)
		{
			pcur->next = new ListNode(carry);
			carry = 0;
			pcur = pcur->next;
		}

		pcur = head->next;
		delete head;
		return pcur;
	}
};
