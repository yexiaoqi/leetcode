//ͬleetcode160
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int size1 = GetSize(headA);
		int size2 = GetSize(headB);
		int minsize = abs(size1 - size2);
		if (size1<size2)
		{
			while (minsize)
			{
				headB = headB->next;
				--minsize;
			}
		}
		else
		{
			while (minsize)
			{
				headA = headA->next;
				--minsize;
			}
		}
		while (headA)
		{
			if (headA == headB)
			{
				return headB;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
	int GetSize(ListNode *head)
	{
		int cnt = 0;
		while (head)
		{
			++cnt;
			head = head->next;
		}
		return cnt;
	}
};