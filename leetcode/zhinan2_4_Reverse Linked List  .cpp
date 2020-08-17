//单链表反转
//ͬleetcode206
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
		ListNode *pre = dummy;
		ListNode *cur = head;
		while (cur&&cur->next)
		{
			ListNode* tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = pre->next;
			pre->next = tmp;


		}
		return dummy->next;
	}
};


//双链表反转
struct ListNode
{
	int val;
	ListNode* next;
	ListNode* last;
	ListNode(int x) :val(x), next(NULL), last(NULL) {}
};
ListNode* ReverseList(ListNode* head)
{
	ListNode* pre = NULL;
	ListNode* cur = NULL;
	while (head)
	{
		cur = head->next;
		head->next = pre;
		head->last = cur;
		pre = head;
		head = cur;
	}
	return pre;
}
int main()
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	a.next = &b;
	b.next = &c;
	c.last = &b;
	b.last = &a;
	ListNode * res = ReverseList(&a);
	return 0;
}