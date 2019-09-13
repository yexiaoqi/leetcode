//Reverse a linked list from position m to n.Do it in - place and in one - pass.
//
//For example :
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note :
//	Given m, n satisfy the following condition :
//1 ≤ m ≤ n ≤ length of list.
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


//https://www.cnblogs.com/grandyang/p/4306611.html
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode*dummy = new ListNode(-1), *pre = dummy;
		//建一个dummy，防止从第一个节点就开始翻转（这样head节点其实就变成最后一个节点了）
		dummy->next = head;
		for (int i = 0; i<m - 1; ++i)
		{
			pre = pre->next;
		}
		ListNode* cur = pre->next;
		for (int j = 0; j<n - m; ++j)
		{
			ListNode* t = cur->next;
			cur->next = t->next;
			// t->next=cur;//只有在第一次pre->next才等于cur，我们的目的是为了把t放到pre的后面，第二次以后pre的后面不是cur
			t->next = pre->next;
			pre->next = t;
		}
		return dummy->next;
	}
};