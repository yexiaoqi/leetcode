//Given a binary tree
//
//struct TreeLinkNode {
//	TreeLinkNode *left;
//	TreeLinkNode *right;
//	TreeLinkNode *next;
//}
//Populate each next pointer to point to its next right node.If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//
//You may only use constant extra space.
//You may assume that it is a perfect binary tree(ie, all leaves are at the same level, and every parent has two children).
//For example,
//Given the following perfect binary tree,
//1
/// \
//2    3
/// \ / \
//4  5  6  7
//After calling your function, the tree should look like :
//1->NULL
/// \
//2 -> 3->NULL
/// \ / \
//4->5->6->7->NULL

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		if (!root)
		{
			return;
		}
		TreeLinkNode *pre = root;
		TreeLinkNode *cur = NULL;
		while (pre->left)
		{
			cur = pre;
			while (cur)
			{
				cur->left->next = cur->right;
				if (cur->next)
				{
					cur->right->next = cur->next->left;
				}
				cur = cur->next;
			}
			pre = pre->left;
		}
		return;
	}
};


//复习
//自己的方法，没有很好地用到完美二叉树的定义
/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;

Node() : val(0), left(NULL), right(NULL), next(NULL) {}

Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

Node(int _val, Node* _left, Node* _right, Node* _next)
: val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
	Node* connect(Node* root) {
		vector<vector<Node*>> res;
		levelorder(root, 0, res);
		for (int i = 0; i<res.size(); ++i)
		{
			for (int j = 0; j<res[i].size() - 1; ++j)
			{
				res[i][j]->next = res[i][j + 1];
			}
			res[i][res[i].size() - 1]->next = NULL;
		}
		return root;
	}
	void levelorder(Node* root, int level, vector<vector<Node*>> &res)
	{
		if (!root)
		{
			return;
		}
		if (res.size() == level)
		{
			res.push_back(vector<Node*>());
		}
		res[level].push_back(root);
		levelorder(root->left, level + 1, res);
		levelorder(root->right, level + 1, res);
	}
};


//递归解法
/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;

Node() : val(0), left(NULL), right(NULL), next(NULL) {}

Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

Node(int _val, Node* _left, Node* _right, Node* _next)
: val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
	Node* connect(Node* root) {
		if (!root)
		{
			return root;
		}
		if (root->left)
		{
			root->left->next = root->right;
			root->right->next = root->next ? root->next->left : NULL;
		}
		connect(root->left);
		connect(root->right);
		return root;
	}
};

//迭代解法
/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;

Node() : val(0), left(NULL), right(NULL), next(NULL) {}

Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

Node(int _val, Node* _left, Node* _right, Node* _next)
: val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
	Node* connect(Node* root) {
		if (!root)
		{
			return root;
		}
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i<size; ++i)
			{
				Node* t = q.front();
				q.pop();
				if (i<size - 1)//是上一轮的q.size()-1，所以要放在for循环外面得到size
				{
					t->next = q.front();
				}
				if (t->left)
				{
					q.push(t->left);
					q.push(t->right);
				}
			}
		}
		return root;
	}
};

//复习
class Solution {
public:
	Node* connect(Node* root) {
		connect2(root);
		return root;
	}
	void connect2(Node* root)
	{
		if (!root)
		{
			return;
		}
		if (root->left)//要先判断(root->left
		{
			root->left->next = root->right;
			if (root->next)//这个得在if(root->left)内
			{
				root->right->next = root->next->left;
			}
		}
		connect2(root->left);
		connect2(root->right);
	}
};