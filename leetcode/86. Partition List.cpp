//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//题目要求对链表分段，所有小于X的元素都排在大于等于X的前面。
class Solution
{
public:
	ListNode* partition(ListNode* head, int x)
	{
		ListNode *node1 = new ListNode(0);
		ListNode *node2 = new ListNode(0);
		ListNode *p1 = node1, *p2 = node2;
		while (head)
		{
			if (head->val<x)
			{
				p1 = p1->next = head;
			}
			else
			{
				p2 = p2->next = head;
			}
			head = head->next;
		}
		p2->next = NULL;
		p1->next = node2->next;
		return node1->next;
	}
};

//https://www.cnblogs.com/grandyang/p/4321292.html
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* dummy = new ListNode(-1), *pre = dummy;
		dummy->next = head;
		while (pre->next&&pre->next->val<x)
		{
			pre = pre->next;
		}
		ListNode*cur = pre;
		while (cur->next)
		{
			ListNode *t = cur->next;
			if (cur->next->val<x)
			{
				cur->next = t->next;
				t->next = pre->next;
				pre->next = t;
				pre = pre->next;
			}
			else
			{
				cur = cur->next;
			}
		}
		return dummy->next;
	}
};