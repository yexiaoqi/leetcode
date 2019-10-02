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