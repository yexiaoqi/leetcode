//�Լ�����
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

//��������������
//������������ͳ�Ƴ�����ĳ��ȣ�Ȼ��������ȴ��ڵ���k�������ڵ㣬�� k = 2 ʱ��ÿ��ֻ��Ҫ����һ�Σ�
//�� k = 3 ʱ��ÿ����Ҫ����2�ˣ�����i��1��ʼѭ����ע�⽻��һ�κ���� pre ָ�룬Ȼ�� num �Լ�k��
//ֱ�� num<k ʱѭ������
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