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