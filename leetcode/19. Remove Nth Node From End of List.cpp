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
		for (int i = 0;i <= n;++i)//slow��fast֮�仹��n��������fast=slow+n+1
		{
			fast = fast->next;
		}
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return start->next;//������head,��Ϊ����[1]��n=1,��ʱӦ�õõ�[],start->next��NULL,��head��1
	}
};