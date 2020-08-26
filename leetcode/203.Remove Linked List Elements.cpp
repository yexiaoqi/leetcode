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