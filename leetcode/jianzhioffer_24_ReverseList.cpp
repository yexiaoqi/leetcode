//同leetcode206
//输入一个链表，反转链表后，输出新链表的表头。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* ReverseList(ListNode* head) {
		ListNode* newhead = NULL;
		while (head)
		{
			ListNode* t = head->next;
			head->next = newhead;
			newhead = head;
			head = t;
		}
		return newhead;
	}
};