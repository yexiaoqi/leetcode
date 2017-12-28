//Reverse a linked list from position m to n.Do it in - place and in one - pass.
//
//For example :
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note :
//	Given m, n satisfy the following condition :
//1 ¡Ü m ¡Ü n ¡Ü length of list.
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
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *pre = dummy, *cur = head;
		for (int i = 1;i<m;++i)
		{
			pre = cur;
			cur = cur->next;
		}
		ListNode *p1, *p2;
		if (cur)
		{
			p1 = cur->next;
		}
		if (p1)
		{
			p2 = p1->next;
		}
		for (int j = m;j<n;++j)
		{
			p1->next = cur;
			cur = p1;
			p1 = p2;
			if (p2)
			{
				p2 = p2->next;
			}
		}
		pre->next->next = p1;
		pre->next = cur;
		return dummy->next;
	}

};