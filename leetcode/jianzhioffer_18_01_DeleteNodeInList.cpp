struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL)
	{
	}
};
class Solution {
public:
	ListNode* deletenode(ListNode *phead, ListNode *deleten)
	{
		if (deleten->next)
		{
			deleten->val = deleten->next->val;
			deleten->next = deleten->next->next;
		}
		else if (phead == deleten)
		{
			phead = NULL;
		}
		else
		{
			ListNode* cur = phead;
			while (cur->next != deleten)
			{
				cur = cur->next;
			}
			cur->next = NULL;
		}
		return phead;
	}
};