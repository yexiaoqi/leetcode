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

//下面这样更清晰
//遍历整个链表，统计出链表的长度，然后如果长度大于等于k，交换节点，当 k = 2 时，每段只需要交换一次，
//当 k = 3 时，每段需要交换2此，所以i从1开始循环，注意交换一段后更新 pre 指针，然后 num 自减k，
//直到 num<k 时循环结束
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(-1);
		ListNode* pre = dummy;
		dummy->next = head;
		ListNode* cur = head;
		int num = 0;
		while (cur)
		{
			++num;
			cur = cur->next;
		}
		while (num >= k)
		{
			cur = pre->next;
			for (int i = 1; i<k; ++i)
			{
				ListNode* t = cur->next;
				cur->next = t->next;
				t->next = pre->next;
				pre->next = t;
			}
			pre = cur;
			num -= k;
		}
		return dummy->next;
	}
};