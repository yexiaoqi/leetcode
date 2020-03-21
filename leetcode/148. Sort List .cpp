//于两个链表是要有序的才能比较容易 merge，那么对于一个无序的链表，如何才能拆分成有序的两个链表呢？
//我们从简单来想，什么时候两个链表一定都是有序的？就是当两个链表各只有一个结点的时候，一定是有序的。
//而归并排序的核心其实是分治法 Divide and Conquer，就是将链表从中间断开，分成两部分，
//左右两边再分别调用排序的递归函数 sortList()，得到各自有序的链表后，再进行 merge()，
//这样整体就是有序的了。因为子链表的递归函数中还是会再次拆成两半，当拆到链表只有一个结点时，
//无法继续拆分了，而这正好满足了前面所说的“一个结点的时候一定是有序的”，这样就可以进行 merge 了。
//然后再回溯回去，每次得到的都是有序的链表，然后进行 merge，直到还原整个长度。这里将链表从中间断开的方法，
//采用的就是快慢指针，
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
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* slow = head, *fast = head, *pre = head;
		while (fast&&fast->next)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;
		return merge(sortList(head), sortList(slow));
	}
	ListNode* merge(ListNode* l1, ListNode* l2)
	{
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
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