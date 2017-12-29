//Given a list, rotate the list to the right by k places, where k is non - negative.
//
//
//Example:
//
//Given 1->2->3->4->5->NULL and k = 2,
//
//return 4->5->1->2->3->NULL.

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
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (!head)
		{
			return head;
		}
		ListNode *tail, *newH;
		tail = newH = head;
		int len = 1;
		while (tail->next)
		{
			tail = tail->next;
			++len;
		}
		tail->next = head;
		if (k %= len)//比如[1,2]，k=3这种情况，就需要k%=len
		{
			for (int i = 0;i<len - k;++i)
			{
				tail = tail->next;
			}
		}
		newH = tail->next;
		tail->next = NULL;
		return newH;
	}
};