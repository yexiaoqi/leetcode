//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
/*
struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};
*/
//ע�������struct���趨�������ʼ��ֻ��Ҫ��x����next��random���Զ���ʼ��ΪNULL�ģ����Գ�ʼ��Ϊ
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
			res.push_back(new RandomListNode(cur->label));//ע�������struct���趨�������ʼ��ֻ��Ҫ��x����next��random���Զ���ʼ��ΪNULL�ģ����Գ�ʼ��Ϊ������������������
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