//输入一个链表，输出该链表中倒数第k个结点。



/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/


//这样写内存超限
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		int cnt = 0;
		map<int, ListNode*> mapping;
		while (pListHead)
		{
			++cnt;
			mapping[cnt] = pListHead;
		}
		if ((cnt - k)<0)
		{
			return NULL;
		}
		return mapping[cnt - k];
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* aptr = pListHead;
		ListNode* bptr = pListHead;
		if (k == 0 || !pListHead)
		{
			return NULL;
		}
		for (int i = 0; i<k - 1; ++i)
		{
			if (aptr->next)
			{
				aptr = aptr->next;
			}
			else
			{
				return NULL;
			}
		}
		while (aptr->next)
		{
			aptr = aptr->next;
			bptr = bptr->next;
		}
		return bptr;
	}
};