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