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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
		{
			return NULL;
		}
		int n = lists.size();
		while (n>1)
		{
			int k = (n + 1) / 2;
			for (int i = 0; i<n / 2; ++i)
			{
				lists[i] = mergeTwoLists(lists[i], lists[i + k]);
			}
			n = k;
		}
		return lists[0];
	}
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode* dummy = new ListNode(-1);
		ListNode* res = dummy;
		while (list1&&list2)
		{
			if (list1->val<list2->val)
			{
				res->next = list1;
				list1 = list1->next;
			}
			else
			{
				res->next = list2;
				list2 = list2->next;
			}
			res = res->next;
		}
		if (list1)
		{
			res->next = list1;
		}
		if (list2)
		{
			res->next = list2;
		}
		return dummy->next;
	}
};



//方法二，改成递归的
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
		{
			return NULL;
		}
		int begin = 0, end = lists.size() - 1;
		return mergesort(lists, begin, end);
	}
	ListNode* mergesort(vector<ListNode*> &lists, int begin, int end)
	{
		if (begin<end)
		{
			int mid = (begin + end) / 2;
			ListNode *left = mergesort(lists, begin, mid);
			ListNode *right = mergesort(lists, mid + 1, end);
			return mergelists(left, right);
		}
		else
		{
			return lists[begin];
		}
	}
	ListNode* mergelists(ListNode* lists1, ListNode* lists2)
	{
		ListNode *dummy = new ListNode(-1);
		ListNode *cur = dummy;
		while (lists1&&lists2)
		{
			if (lists1->val<lists2->val)
			{
				cur->next = lists1;
				lists1 = lists1->next;
			}
			else
			{
				cur->next = lists2;
				lists2 = lists2->next;
			}
			cur = cur->next;
		}
		if (lists1)
		{
			cur->next = lists1;
		}
		if (lists2)
		{
			cur->next = lists2;
		}
		return dummy->next;
	}
};


//复习，复杂度O(nlogk),k是链表个数
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
		{
			return NULL;
		}
		int  n = lists.size();
		while (n>1)
		{
			int k = (n + 1) / 2;
			for (int i = 0; i<n / 2; ++i)
			{
				lists[i] = mergelists(lists[i], lists[i + k]);
			}
			n = k;
		}
		return lists[0];
	}
	ListNode* mergelists(ListNode* lists1, ListNode* lists2)
	{
		ListNode *dummy = new ListNode(-1);
		ListNode *cur = dummy;
		while (lists1&&lists2)
		{
			if (lists1->val<lists2->val)
			{
				cur->next = lists1;
				lists1 = lists1->next;
			}
			else
			{
				cur->next = lists2;
				lists2 = lists2->next;
			}
			cur = cur->next;
		}
		if (lists1)
		{
			cur->next = lists1;
		}
		if (lists2)
		{
			cur->next = lists2;
		}
		return dummy->next;
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
		{
			return NULL;
		}
		int n = lists.size();
		return mergesort(lists, 0, n - 1);
	}
	ListNode* mergesort(vector<ListNode*>& lists, int begin, int end)
	{
		if (begin<end)
		{
			int mid = (begin + end) / 2;
			ListNode* left = mergesort(lists, begin, mid);
			ListNode* right = mergesort(lists, mid + 1, end);
			return merge(left, right);
		}
		else
		{
			return lists[begin];
		}
	}
	ListNode* merge(ListNode* list1, ListNode* list2)
	{
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		while (list1&&list2)
		{
			if (list1->val<list2->val)
			{
				cur->next = list1;
				list1 = list1->next;
			}
			else
			{
				cur->next = list2;
				list2 = list2->next;
			}
			cur = cur->next;
		}
		if (list1)
		{
			cur->next = list1;
		}
		if (list2)
		{
			cur->next = list2;
		}
		return dummy->next;
	}
};

//
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int n = lists.size();
		if (n == 0)
		{
			return NULL;
		}
		while (n != 1)
		{
			int part = (n + 1) / 2;
			for (int i = 0; i<n / 2; ++i)
			{
				lists[i] = merge2Lists(lists[i], lists[i + part]);
			}
			n = part;
		}
		return lists[0];
	}
	ListNode *merge2Lists(ListNode *l1, ListNode *l2)
	{
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