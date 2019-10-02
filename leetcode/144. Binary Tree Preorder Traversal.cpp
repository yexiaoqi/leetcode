//Given a binary tree, return the preorder traversal of its nodes' values.
//
//For example :
//Given binary tree[1, null, 2, 3],
//1
//\
//2
///
//3
//return[1, 2, 3].
//
//Note: Recursive solution is trivial, could you do it iteratively ?

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
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int>result;
		vector<TreeNode*> temp;
		while (!temp.empty() || root)
		{
			if (root)
			{
				result.push_back(root->val);//存值，所以是root->val不是root
				temp.push_back(root);
				root = root->left;
			}
			else
			{
				root = temp.back();
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
	vector<int> preorderTraversal(TreeNode* root)
	{
		if (root)
		{
			v.push_back(root->val);
			preorderTraversal(root->left);
			preorderTraversal(root->right);
		}
		return v;
	}
};


class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		if (!root)
		{
			return{};
		}
		vector<int> res;
		stack<TreeNode*> s{ { root } };
		while (!s.empty())
		{
			TreeNode *t = s.top();
			s.pop();
			res.push_back(t->val);
			if (t->right)
			{
				s.push(t->right);
			}
			if (t->left)
			{
				s.push(t->left);
			}
		}
		return res;
	}
};


//模板解法
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode *p = root;
		while (!s.empty() || p) {
			if (p) {
				s.push(p);
				res.push_back(p->val);
				p = p->left;
			}
			else {
				TreeNode *t = s.top(); s.pop();
				p = t->right;
			}
		}
		return res;
	}
};