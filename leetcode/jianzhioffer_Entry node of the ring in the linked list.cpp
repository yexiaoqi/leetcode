//同leetcode142
//给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
//因为快指针每次走2，慢指针每次走1，快指针走的距离是慢指针的两倍。而快指针又比慢指针多走了一圈。所以 head 到环的起点 + 环的起点到他们相遇的点的距离 与 环一圈的距离相等。现在重新开始，head 运行到环起点 和 相遇点到环起点 的距离也是相等的，相当于他们同时减掉了 环的起点到他们相遇的点的距离。
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