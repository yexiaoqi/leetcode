//«∞–Ú leetcode144
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorderTraversal(root, res);
		return res;
	}
	void preorderTraversal(TreeNode* root, vector<int> &res)
	{
		if (!root)
		{
			return;
		}
		res.push_back(root->val);
		preorderTraversal(root->left, res);
		preorderTraversal(root->right, res);
	}
};
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (!root)
		{
			return vector<int>();
		}
		stack<TreeNode*> s;
		TreeNode *p = root;
		vector<int> res;
		while (p || !s.empty())
		{
			if (p)
			{

				res.push_back(p->val);
				s.push(p);
				p = p->left;
			}
			else
			{
				p = s.top();
				s.pop();
				p = p->right;
			}
		}
		return res;
	}

};


//÷––Ú lletcode94
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
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root)
		{
			return vector<int>();
		}
		stack<TreeNode*> s;
		vector<int> res;
		TreeNode* p = root;
		while (p || !s.empty())
		{
			if (p)
			{
				s.push(p);
				p = p->left;
			}
			else
			{
				p = s.top();
				s.pop();
				res.push_back(p->val);
				p = p->right;
			}
		}
		return res;

	}
};

//∫Û–Ú
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
			return vector<int>();
		}
		vector<int> res;
		TreeNode* p = root;
		stack<TreeNode*> s;
		while (p || !s.empty())
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