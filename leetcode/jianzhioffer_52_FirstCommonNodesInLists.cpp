//自己做的，一遍ac
//同leetcode160
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
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		int size1 = 0;
		int size2 = 0;
		ListNode* h1 = pHead1;
		ListNode* h2 = pHead2;
		while (h1)
		{
			h1 = h1->next;
			size1++;
		}
		while (h2)
		{
			h2 = h2->next;
			size2++;
		}
		int delta = abs(size1 - size2);
		if (size1>size2)
		{
			while (delta)
			{
				pHead1 = pHead1->next;
				delta--;
			}
		}
		else
		{
			while (delta)
			{
				pHead2 = pHead2->next;
				delta--;
			}
		}
		while (pHead1 != pHead2)
		{
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return pHead1;
	}
};