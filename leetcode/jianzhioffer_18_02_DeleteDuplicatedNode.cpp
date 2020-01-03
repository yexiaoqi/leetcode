//ͬleetcode82
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* dummy = new ListNode(-1);
		dummy->next = pHead;
		ListNode* pre = dummy;
		while (pre->next)
		{
			ListNode* cur = pre->next;
			while (cur->next&&cur->val == cur->next->val)
			{
				cur = cur->next;
			}
			if (pre->next != cur)
			{
				pre->next = cur->next;
			}
			else {
				pre = pre->next;
			}
		}
		return dummy->next;
	}
};