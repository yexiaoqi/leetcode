//同剑指offer 35
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


//1. 在原链表的每个节点后面拷贝出一个新的节点。
//
//2. 依次给新的节点的随机指针赋值，而且这个赋值非常容易 cur->next->random = cur->random->next。
//
//3. 断开链表可得到深度拷贝后的新链表。
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


//使用 HashMap
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
		unordered_map<Node*, int> listmap;//用unordered_map
		vector<Node*> newlist;//利用vector先存储单独的Node*，然后再遍历一次串起来
		Node* cur = head;
		int i = 0;
		while (cur)
		{
			newlist.push_back(new Node(cur->val, NULL, NULL));
			//newlist[i]->next=NULL;
			// newlist[i]->random=NULL;//注意要有这句,因为random指向NULL的没有建立映射//修改为在上面初始化new Node(cur->val,NULL,NULL)
			listmap[cur] = i;
			++i;
			cur = cur->next;
		}
		newlist.push_back(NULL);//这样不用对最后一个特殊处理了
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

//复习
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