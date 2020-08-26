//ͬleetcode203
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pre = dummy;
		ListNode *cur = head;
		while (cur)
		{
			if (cur->val == val)
			{
				pre->next = cur->next;
				cur->next = NULL;
				cur = pre->next;
			}
			else
			{
				pre = pre->next;
				cur = cur->next;
			}
		}
		return dummy->next;
	}
};