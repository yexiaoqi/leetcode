//https://www.nowcoder.com/questionTerminal/56f059fc033f46b98c73e2caea760a8d?toCommentId=14604
class Solution {
public:
	/**
	*	�������Ұ����ķ�ʽ������ϵ�����
	*	���룺һ���������ͷ�ڵ�head
	*	�������������ĿҪ�������
	*
	*	��̨�ĵ�����ڵ������£�
	*
	struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
	};
	*/
	void relocateList(struct ListNode* head) {
		if (!head)
		{
			return;
		}
		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *cur = new ListNode(-1);
		cur->next = head;
		ListNode *pre = head;
		while (fast->next&&fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast->next)
		{
			ListNode *slnext = slow->next;
			while (slnext)
			{
				ListNode *t = pre->next;
				cur->next = pre;
				cur = cur->next;
				cur->next = slnext;
				cur = cur->next;
				pre = t;
				slnext = slnext->next;
			}
		}
		else
		{
			while (slow->next)
			{
				ListNode *t = pre->next;
				cur->next = pre;
				cur = cur->next;
				cur->next = slow;
				cur = cur->next;
				pre = t;
				slow = slow->next;
			}
			cur->next = slow;
			cur = cur->next;
		}
	}
};