//You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example
//
//Input : (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 0 -> 8
//	Explanation : 342 + 465 = 807.

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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode StackAnchor(0);
		ListNode *tail = &StackAnchor;
		div_t sum = { 0,0 };
		while (sum.quot>0 || l1 || l2)
		{
			if (l1)
			{
				sum.quot += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				sum.quot += l2->val;
				l2 = l2->next;
			}
			sum = div(sum.quot, 10);
			tail->next = new ListNode(sum.rem);
			tail = tail->next;
		}
		return StackAnchor.next;
	}
};

https://www.cnblogs.com/grandyang/p/4129891.html
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(-1), *current = dummy;
		int carry = 0;
		while (l1 || l2)
		{
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			int sum = val1 + val2 + carry;
			carry = sum / 10;
			current->next = new ListNode(sum % 10);
			current = current->next;
			if (l1)
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}
		}
		if (carry)
		{
			current->next = new ListNode(1);
		}
		return dummy->next;
	}
};