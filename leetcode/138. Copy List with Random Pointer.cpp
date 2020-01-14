//ͬ��ָoffer 35
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


//1. ��ԭ�����ÿ���ڵ���濽����һ���µĽڵ㡣
//
//2. ���θ��µĽڵ�����ָ�븳ֵ�����������ֵ�ǳ����� cur->next->random = cur->random->next��
//
//3. �Ͽ�����ɵõ���ȿ������������
/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node() {}

Node(int _val, Node* _next, Node* _random) {
val = _val;
next = _next;
random = _random;
}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head)
		{
			return NULL;
		}
		Node* cur = head;
		while (cur)
		{
			Node* t = new Node(cur->val, NULL, NULL);
			t->next = cur->next;
			cur->next = t;
			cur = t->next;
		}
		cur = head;
		while (cur)
		{
			if (cur->random)
			{
				cur->next->random = cur->random->next;
			}
			cur = cur->next->next;
		}
		cur = head;
		Node* res = cur->next;
		while (cur)
		{
			Node* t = cur->next;
			cur->next = t->next;
			if (t->next)
			{
				t->next = t->next->next;
			}
			cur = cur->next;
		}
		return res;
	}
};
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


//ʹ�� HashMap
/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node() {}

Node(int _val, Node* _next, Node* _random) {
val = _val;
next = _next;
random = _random;
}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head)
		{
			return NULL;
		}
		unordered_map<Node*, int> listmap;//��unordered_map
		vector<Node*> newlist;//����vector�ȴ洢������Node*��Ȼ���ٱ���һ�δ�����
		Node* cur = head;
		int i = 0;
		while (cur)
		{
			newlist.push_back(new Node(cur->val, NULL, NULL));
			//newlist[i]->next=NULL;
			// newlist[i]->random=NULL;//ע��Ҫ�����,��Ϊrandomָ��NULL��û�н���ӳ��//�޸�Ϊ�������ʼ��new Node(cur->val,NULL,NULL)
			listmap[cur] = i;
			++i;
			cur = cur->next;
		}
		newlist.push_back(NULL);//�������ö����һ�����⴦����
		cur = head;
		i = 0;
		while (cur)
		{
			if (cur->random)
			{
				int id = listmap[cur->random];
				newlist[i]->random = newlist[id];
			}

			newlist[i]->next = newlist[i + 1];
			cur = cur->next;

			++i;
		}
		return newlist[0];

	}
};

//��ϰ
/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		unordered_map<Node*, int> m;
		Node* cur = head;
		vector<Node*> list;
		int i = 0;
		while (cur)
		{
			m[cur] = i;
			++i;
			list.push_back(new Node(cur->val));
			cur = cur->next;
		}
		list.push_back(NULL);
		cur = head;
		i = 0;
		while (cur)
		{
			list[i]->next = list[i + 1];
			if (cur->random)
			{
				list[i]->random = list[m[cur->random]];
			}
			cur = cur->next;
			++i;
		}
		return list[0];
	}
};