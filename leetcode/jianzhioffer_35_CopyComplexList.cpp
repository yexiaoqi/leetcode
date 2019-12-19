//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
/*
struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};
*/
//注意给定的struct的设定，这里初始化只需要给x，而next和random是自动初始化为NULL的，所以初始化为
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		map<RandomListNode*, int> mapping;
		vector<RandomListNode*> res;
		RandomListNode* cur = pHead;
		int i = 0;
		while (cur)
		{
			mapping[cur] = i;
			//res.push_back(new RandomListNode(cur->label,NULL,NLL));
			res.push_back(new RandomListNode(cur->label));//注意给定的struct的设定，这里初始化只需要给x，而next和random是自动初始化为NULL的，所以初始化为这样而不是上面这行
			// res[i]->next=NULL;
			//res[i]->random=NULL;
			cur = cur->next;
			++i;
		}
		res.push_back(NULL);
		cur = pHead;
		i = 0;
		while (cur)
		{
			res[i]->next = res[i + 1];
			if (cur->random)
			{
				res[i]->random = res[mapping[cur->random]];
			}
			++i;
			cur = cur->next;
		}
		return res[0];
	}
};