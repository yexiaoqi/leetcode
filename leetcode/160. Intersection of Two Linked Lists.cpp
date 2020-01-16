//同剑指offer 52
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
		if (!headA || !headB)
		{
			return NULL;
		}
		int lenA = getlen(headA);//写成复用函数的形式
		int lenB = getlen(headB);
		int delta = abs(lenA - lenB);
		if (lenA>lenB)
		{
			for (int i = 0; i<delta; ++i)
			{
				headA = headA->next;
			}

		}
		else
		{
			for (int i = 0; i<delta; ++i)
			{
				headB = headB->next;
			}

		}
		while (headA&&headB)
		{
			if (headA == headB)
			{
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
	int getlen(ListNode *head)
	{
		int count = 0;
		while (head)
		{
			++count;
			head = head->next;
		}
		return count;
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int size1 = getlen(headA);
		int size2 = getlen(headB);
		int delta = abs(size1 - size2);
		if (size1>size2)
		{
			while (delta--)
			{
				headA = headA->next;
			}
		}
		else
		{
			while (delta--)
			{
				headB = headB->next;
			}
		}
		while (headA != headB)
		{
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
	}
	int getlen(ListNode *node)
	{
		int count = 0;
		while (node)
		{
			++count;
			node = node->next;
		}
		return count;
	}
};