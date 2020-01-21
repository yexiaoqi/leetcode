//自己做出
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
	ListNode* reverseKGroup(ListNode* head, int k) {
		int cnt = genlen(head);
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		if (k>cnt)
		{
			return head;
		}
		ListNode* pre = dummy;
		ListNode* cur = head;
		int i = 0;
		while (cur&&cur->next)
		{
			if (i == (cnt - cnt%k))
			{
				return dummy->next;
			}
			if ((i + 1) % k == 0)
			{
				pre = cur;
				cur = cur->next;
				++i;
				continue;
			}
			ListNode* t = cur->next;
			cur->next = t->next;
			t->next = pre->next;
			pre->next = t;
			++i;
		}
		return dummy->next;
	}
	int genlen(ListNode* head)
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