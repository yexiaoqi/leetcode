//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?

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
	bool hasCycle(ListNode *head)
	{
		if (!head)
		{
			return false;
		}
		ListNode *runner = head;
		ListNode *walker = head;
		while (runner&&runner->next)
		//不能是while(walker->next&&runner->next->next)，以快的runner为准，
		//如果写成walker->next，runner->next可能已经不存在，这时候用runner->next->next就不对了
		{
			runner = runner->next->next;
			walker = walker->next;
			if (runner == walker)
			{
				return true;
			}
		}
		return false;
	}
};