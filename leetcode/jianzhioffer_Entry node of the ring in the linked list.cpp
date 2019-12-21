//ͬleetcode142
//��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
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
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		set<ListNode*> res;
		while (pHead)
		{
			if (res.find(pHead) != res.end())
			{
				return pHead;
			}
			res.insert(pHead);
			pHead = pHead->next;
		}
		return NULL;
	}
};

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
//��Ϊ��ָ��ÿ����2����ָ��ÿ����1����ָ���ߵľ�������ָ�������������ָ���ֱ���ָ�������һȦ������ head ��������� + ������㵽���������ĵ�ľ��� �� ��һȦ�ľ�����ȡ��������¿�ʼ��head ���е������ �� �����㵽����� �ľ���Ҳ����ȵģ��൱������ͬʱ������ ������㵽���������ĵ�ľ��롣
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* fast = pHead;
		ListNode* slow = pHead;
		ListNode* meet = NULL;
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
			if (fast)
			{
				fast = fast->next;
			}
			if (fast == slow)
			{
				meet = fast;
				break;
			}
		}
		if (meet == NULL)
		{
			return NULL;
		}
		while (pHead)
		{
			if (pHead == meet)
			{
				return pHead;
			}
			pHead = pHead->next;
			meet = meet->next;

		}
	}
};