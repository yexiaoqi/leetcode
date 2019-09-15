//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.

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
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (head == NULL)
		{
			return NULL;
		}//加这个判断会快一点
		ListNode *Fakehead = new ListNode(0);
		Fakehead->next = head;
		ListNode *pre = Fakehead;
		ListNode *cur = head;
		while (cur)
		{
			while (cur->next&&cur->val == cur->next->val)
			{
				cur = cur->next;
			}
			if (pre->next == cur)
			{
				pre = pre->next;
			}
			else
			{
				pre->next = cur->next;
			}
			cur = cur->next;
		}
		return Fakehead->next;
	}
};

//https://www.cnblogs.com/grandyang/p/4069003.html

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
		{
			return head;
		}
		if (head->next&&head->val == head->next->val)
		{
			while (head->next&&head->val == head->next->val)
			{
				head = head->next;
			}
			return deleteDuplicates(head->next);
		}
		head->next = deleteDuplicates(head->next);
		return head;
	}
};