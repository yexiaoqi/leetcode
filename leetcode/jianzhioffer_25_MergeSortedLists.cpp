//���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/

//һ�����Լ�AC
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* dummy = new ListNode(-1);
		ListNode* res = dummy;
		while (pHead1&&pHead2)
		{
			if (pHead1->val<pHead2->val)
			{
				res->next = pHead1;
				pHead1 = pHead1->next;
			}
			else {
				res->next = pHead2;
				pHead2 = pHead2->next;
			}
			res = res->next;
		}
		if (pHead1)
		{
			res->next = pHead1;
		}
		if (pHead2)
		{
			res->next = pHead2;
		}
		return dummy->next;
	}
};