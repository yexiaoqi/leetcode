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
//深拷贝一个链表，链表除了含有next指针外，还包含一个random指针，该指针指向字符串中的某个节点或者为空。
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
			//RandomListNode *l2=new RandomListNode(l1->label);//l2要在上面定义，不要在这个循环里定义，否则之后的循环里l2是没有定义的
			l2 = new RandomListNode(l1->label);
			l2->next = l1->next;
			l1->next = l2;
		}
		RandomListNode *newhead;
		newhead = head->next;
		for (l1 = head;l1;l1 = l1->next->next)
		{
			if (l1->random)//注意要检查这句
			{
				l1->next->random = l1->random->next;
			}
		}
		for (l1 = head;l1;l1 = l1->next)
		{
			l2 = l1->next;
			l1->next = l2->next;
			if (l2->next)//要加这个if判断，因为for循环进行4次，但l2的节点只要连三次
			{
				l2->next = l2->next->next;
			}
		}
		return newhead;
	}
};