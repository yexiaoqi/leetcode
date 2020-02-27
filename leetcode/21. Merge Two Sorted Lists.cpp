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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* res = new ListNode(-1);
		ListNode *tmp = res;
		while (l1&&l2)
		{
			if (l1->val<l2->val)
			{
				tmp->next = l1;
				l1 = l1->next;

			}
			else
			{
				tmp->next = l2;
				l2 = l2->next;

			}
			tmp = tmp->next;
		}
		if (l1)
		{
			tmp->next = l1;
			// l1=l1->next;
			// tmp=tmp->next;
		}
		if (l2)
		{
			tmp->next = l2;
			//l2=l2->next;
			// tmp=tmp->next;
		}
		return res->next;
	}
};

//��ϰ
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *cur = dummy;
		// ListNode *cur=dummy->next;//����д���ԣ�����cur=l2;�ǰ�NULL��ֵ��cur���Ǹ��ڵ�
		while (l1&&l2)
		{
			if (l1->val>l2->val)
			{
				cur->next = l2;
				//cur=l2;
				l2 = l2->next;
			}
			else
			{
				cur->next = l1;
				//cur=l1;
				l1 = l1->next;
			}
			cur = cur->next;
		}
		if (l1)
		{
			cur->next = l1;
			//cur=l1;
		}
		if (l2)
		{
			cur->next = l2;
			//cur=l2;
		}
		return dummy->next;
	}
};


//��ϰ2
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *cur = dummy;
		while (l1&&l2)
		{
			if (l1->val<l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if (l1)
		{
			cur->next = l1;
		}
		if (l2)
		{
			cur->next = l2;
		}
		return dummy->next;
	}
};


//��ϰ4
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *cur = dummy;
		while (l1&&l2)
		{
			if (l1->val<l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if (l1)
		{
			cur->next = l1;
		}
		if (l2)
		{
			cur->next = l2;
		}
		return dummy->next;
	}
};