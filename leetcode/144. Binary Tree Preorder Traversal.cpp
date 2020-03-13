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
//辅助结点p初始化为根结点，while循环的条件是栈不为空或者辅助结点p不为空，
//在循环中首先判断如果辅助结点p存在，那么先将p加入栈中，然后将p的结点值加入结果res中，
//此时p指向其左子结点。否则如果p不存在的话，表明没有左子结点，我们取出栈顶结点，将p指向栈顶结点的右子结点
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

//复习
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode *p = root;
		stack<TreeNode*> s;
		while (!s.empty() || p)
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