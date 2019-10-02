//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example :
//Given binary tree[1, null, 2, 3],
//1
//\
//2
///
//3
//return[1, 3, 2].
//
//Note: Recursive solution is trivial, could you do it iteratively ?
//

//方法一 迭代
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int>result;
		vector<TreeNode*> temp;
		while (root || !temp.empty())
		{
			if (root)
			{
				temp.push_back(root);
				root = root->left;
			}
			else
			{
				root = temp.back();
				result.push_back(temp.back()->val);
				temp.pop_back();
				root = root->right;
			}
		}
		return result;
	}
};

//方法二 递归
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution
{
public:
	vector<int> v;
	vector<int> inorderTraversal(TreeNode* root)
	{
		if (root)
		{
			inorderTraversal(root->left);
			v.push_back(root->val);
			inorderTraversal(root->right);
		}
		return v;
	}
};


class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> res;
		inorder(root, res);
		return res;
	}
	void inorder(TreeNode* root, vector<int> &res)
	{
		if (!root)
		{
			return;
		}
		if (root->left)
		{
			inorder(root->left, res);
		}
		res.push_back(root->val);
		if (root->right)
		{
			inorder(root->right, res);
		}
	}
};



class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode* p = root;
		while (p || !s.empty())
		{
			while (p)
			{
				s.push(p);
				p = p->left;
			}
			p = s.top(); s.pop();
			res.push_back(p->val);
			p = p->right;
		}
		return res;
	}

};

//模板解法
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode *p = root;
		while (!s.empty() || p) {
			if (p) {
				s.push(p);
				p = p->left;
			}
			else {
				p = s.top(); s.pop();
				res.push_back(p->val);
				p = p->right;
			}
		}
		return res;
	}
};