//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

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
		ListNode *list = head;
		while (list)
		{
			if (list->next == NULL)
			{
				break;
			}
			if (list->val == list->next->val)
			{
				list->next = list->next->next;
			}
			else
			{
				list = list->next;
			}
		}
		return head;
	}
};

//自己AC的第一道题！虽然不够简洁，但记录一下
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *pre = head;
		if (pre&&pre->next)
		{
			ListNode *cur = pre->next;
			while (cur)
			{
				if (cur->val == pre->val)
				{
					//ListNode*t=cur->next;
					pre->next = cur->next;
					cur = cur->next;
				}
				else
				{
					pre = pre->next;
				}
			}
		}
		else
		{
			return head;
		}

		return head;
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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *dummy = new ListNode(-1);
		ListNode *pre = head;
		dummy->next = head;
		while (pre&&pre->next)//注意先判空
		{
			ListNode* cur = pre->next;
			while (cur&&cur->val == pre->val)//注意先判空
			{
				cur = cur->next;
			}
			pre->next = cur;
			pre = pre->next;
		}
		return dummy->next;
	}
};