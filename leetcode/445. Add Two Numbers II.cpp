//自己的方法
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
		stack<int> st1, st2, st3;
		while (l1)
		{
			st1.push(l1->val);
			l1 = l1->next;
		}
		while (l2)
		{
			st2.push(l2->val);
			l2 = l2->next;
		}
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		int carry = 0;
		while (!st1.empty() || !st2.empty())
		{
			int val1 = !st1.empty() ? st1.top() : 0;
			int val2 = !st2.empty() ? st2.top() : 0;
			int sum = val1 + val2 + carry;
			carry = sum / 10;
			st3.push(sum % 10);
			if (!st1.empty())//啊判空，这该死的判空
			{
				st1.pop();
			}
			if (!st2.empty())
			{
				st2.pop();
			}
		}
		if (carry)
		{
			st3.push(1);
		}
		while (!st3.empty())
		{
			ListNode* t = new ListNode(st3.top());
			cur->next = t;
			cur = cur->next;
			st3.pop();
		}
		return dummy->next;
	}
};


//方法二，一遍ac
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
		ListNode* newl1 = reverse(l1);
		ListNode* newl2 = reverse(l2);
		int carry = 0;
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		while (newl1 || newl2)
		{
			int val1 = newl1 ? newl1->val : 0;
			int val2 = newl2 ? newl2->val : 0;
			int sum = val1 + val2 + carry;
			ListNode* t = new ListNode(sum % 10);
			carry = sum / 10;
			cur->next = t;
			cur = cur->next;
			if (newl1)
			{
				newl1 = newl1->next;
			}
			if (newl2)
			{
				newl2 = newl2->next;
			}
		}
		if (carry)
		{
			ListNode* t = new ListNode(carry);
			cur->next = t;
		}
		ListNode* newres = reverse(dummy->next);
		return newres;
	}
	ListNode* reverse(ListNode* head)
	{
		ListNode* dummy = new ListNode(-1);
		ListNode* pre = dummy;
		dummy->next = head;
		ListNode *cur = head;
		while (cur&&cur->next)
		{
			ListNode* t = cur->next;
			cur->next = t->next;
			t->next = pre->next;
			pre->next = t;
		}
		return dummy->next;
	}
};