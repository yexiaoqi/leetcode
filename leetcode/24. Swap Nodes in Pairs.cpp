//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space.You may not modify the values in the list, only nodes itself can be changed.

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution
{
public:
	ListNode* swapPairs(ListNode* head)
	{
		ListNode *newhead = new ListNode(0);
		newhead->next = head;
		ListNode *temp = newhead;
		ListNode *one = new ListNode(0);
		ListNode *two = new ListNode(0);
		while (temp->next&&temp->next->next)
		{
			one = temp->next;
			two = temp->next->next;
			one->next = two->next;
			two->next = one;
			temp->next = two;
			temp = one;
		}
		return newhead->next;
	}
};

//¸´Ï°
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
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = pre->next;
		while (cur&&cur->next)
		{
			ListNode* t = cur->next;
			pre->next = t;
			cur->next = t->next;
			t->next = cur;
			pre = cur;
			cur = cur->next;
		}
		return dummy->next;
	}
};