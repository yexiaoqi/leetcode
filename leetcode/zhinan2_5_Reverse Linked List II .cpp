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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		// while(--m)
		// {
		//     pre=pre->next;
		// }//ע�����cnt=n-m�ֻ��õ�m����߲��ܸ�
		for (int i = 0; i<m - 1; ++i)
		{
			pre = pre->next;
		}
		ListNode* cur = pre->next;
		int cnt = n - m;
		while (cnt--)
		{
			ListNode* tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = pre->next;
			pre->next = tmp;
		}
		return dummy->next;
	}
};