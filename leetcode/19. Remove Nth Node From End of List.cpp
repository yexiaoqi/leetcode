//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note :
//	Given n will always be valid.
//	Try to do this in one pass.

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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode *start = new ListNode(0);
		ListNode *slow, *fast;
		start->next = head;
		slow = fast = start;
		for (int i = 0;i <= n;++i)//slow和fast之间还有n个，所以fast=slow+n+1
		{
			fast = fast->next;
		}
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return start->next;//不能是head,因为比如[1]，n=1,此时应该得到[],start->next是NULL,但head是1
	}
};

//复习
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *cur = head;
		ListNode *pre = head;
		for (int i = 0; i<n; ++i)
		{
			cur = cur->next;
		}
		if (!cur)
		{
			return head->next;
		}
		while (cur->next)
		{
			cur = cur->next;
			pre = pre->next;
		}
		pre->next = pre->next->next;
		return head;
	}
};

//复习2
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (n <= 0)
		{
			return head;
		}
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* slow = dummy, *fast = dummy;//从dummy开始
		while (n--)
		{
			fast = fast->next;
			if (!fast)
			{
				return head;
			}
		}

		while (fast&&fast->next)//fast&&fast->next不是fast
		{
			slow = slow->next;
			fast = fast->next;
		}
		slow->next = slow->next->next;
		return dummy->next;
	}
};