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
	ListNode* middleNode(ListNode* head) {
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *slow = dummy, *fast = dummy;
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast)
		{
			slow = slow->next;
		}
		return slow;
	}
};