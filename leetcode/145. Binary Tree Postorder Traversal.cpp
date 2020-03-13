/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root)
		{
			return{};//返回空而不是root，类型不同
		}
		stack<TreeNode*> s{ { root } };//栈的初始化
									   //stack<TreeNode*> s={{root}};
		vector<int> res;
		TreeNode* head = root;
		while (!s.empty())
		{
			TreeNode* t = s.top();
			if ((!t->left && !t->right) || t->left == head || t->right == head)//叶节点或者子节点为已经处理过的节点的情况
			{
				res.push_back(t->val);
				s.pop();
				head = t;
			}
			else
			{
				if (t->right)
				{
					s.push(t->right);
				}
				if (t->left)
				{
					s.push(t->left);
				}
			}
		}
		return res;
	}
};


//模板解法
//由于后序遍历的顺序是左 - 右 - 根，而先序遍历的顺序是根 - 左 - 右，二者其实还是很相近的
//，可以先在先序遍历的方法上做些小改动，使其遍历顺序变为根 - 右 - 左，然后翻转一下，就是左 - 右 - 根啦，
//翻转的方法我们使用反向Q，哦不，是反向加入结果 res，每次都在结果 res 的开头加入结点值，
//而改变先序遍历的顺序就只要该遍历一下入栈顺序，先左后右，这样出栈处理的时候就是先右后左啦
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode *p = root;
		while (!s.empty() || p) {
			if (p) {
				s.push(p);
				res.insert(res.begin(), p->val);
				p = p->right;
			}
			else {
				TreeNode *t = s.top(); s.pop();
				p = t->left;
			}
		}
		return res;
	}
};

//复习
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode* p = root;
		while (!s.empty() || p)
		{
			if (p)
			{
				s.push(p);
				res.insert(res.begin(), p->val);
				p = p->right;
			}
			else
			{
				p = s.top();
				s.pop();
				p = p->left;
			}
		}
		return res;
	}
};