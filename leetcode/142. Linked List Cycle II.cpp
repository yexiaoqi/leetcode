//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//
//Note: Do not modify the linked list.
//
//	Follow up :
//Can you solve it without using extra space ?
//


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
	ListNode *detectCycle(ListNode *head)
	{
		if (!head)
		{
			return NULL;
		}
		ListNode *runner = head;
		ListNode *walker = head;
		while (runner&&runner->next)
		{
			walker = walker->next;
			runner = runner->next->next;
			if (runner == walker)
			{
				break;
			}
		}
		if (!runner || !runner->next)
		{
			return NULL;
		}
		walker = head;
		while (runner != walker)
		{
			runner = runner->next;
			walker = walker->next;
		}
		return walker;
	}
};