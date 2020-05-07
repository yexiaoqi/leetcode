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
	ListNode* reverseList(ListNode* head) {
		ListNode *new_head = NULL;
		while (head)
		{
			ListNode *next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}
		return new_head;
	}
};
//递归版本
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
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* newhead = reverseList(head->next);//比如1->2->3,先到了newhead=3return，然后 head->next->next也就是3->next指向2， head->next指向NULL；然后newhead（始终是头结点）还是3，head变成1，head->next->next也就是2->next指向1,1->next指向空，一个一个翻转
		head->next->next = head;
		head->next = NULL;
		return newhead;
	}
};


//复习
//自己做出，一遍ac（迭代版本）
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
	ListNode* reverseList(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = head;
		while (cur&&cur->next)
		{
			ListNode *t = cur->next;
			cur->next = t->next;
			t->next = pre->next;
			pre->next = t;
		}
		return dummy->next;
	}
};

//复习2
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* newhead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return newhead;
	}
};


//完整输出
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution
{
public:
	ListNode* Reverse(ListNode *node)
	{
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = node;
		ListNode* pre = dummy;
		pre->next = node;
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

int main()
{
	Solution s;
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	ListNode* res = s.Reverse(&a);
	while (res)
	{
		cout << res->val;
		res = res->next;
	}
	return 0;
}