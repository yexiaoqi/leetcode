//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
//���һ������������˺���nextָ���⣬������һ��randomָ�룬��ָ��ָ���ַ����е�ĳ���ڵ����Ϊ�ա�
class Solution
{
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		if (!head)
		{
			return NULL;
		}
		RandomListNode *l1, *l2;
		l1 = head;
		for (l1 = head;l1;l1 = l1->next->next)
		{
			//RandomListNode *l2=new RandomListNode(l1->label);//l2Ҫ�����涨�壬��Ҫ�����ѭ���ﶨ�壬����֮���ѭ����l2��û�ж����
			l2 = new RandomListNode(l1->label);
			l2->next = l1->next;
			l1->next = l2;
		}
		RandomListNode *newhead;
		newhead = head->next;
		for (l1 = head;l1;l1 = l1->next->next)
		{
			if (l1->random)//ע��Ҫ������
			{
				l1->next->random = l1->random->next;
			}
		}
		for (l1 = head;l1;l1 = l1->next)
		{
			l2 = l1->next;
			l1->next = l2->next;
			if (l2->next)//Ҫ�����if�жϣ���Ϊforѭ������4�Σ���l2�Ľڵ�ֻҪ������
			{
				l2->next = l2->next->next;
			}
		}
		return newhead;
	}
};