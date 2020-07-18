//Given a binary tree, flatten it to a linked list in - place.
//
//For example,
//Given
//
//1
/// \
//2   5
/// \   \
//3   4   6
//The flattened tree should look like :
//1
//\
//2
//\
//3
//\
//4
//\
//5
//\
//6

//递归版本
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
	void flatten(TreeNode* root)
	{
		if (!root)
		{
			return;
		}
		if (root->left)
		{
			flatten(root->left);
		}
		if (root->right)
		{
			flatten(root->right);
		}
		TreeNode *tmp = root->right;
		root->right = root->left;
		root->left = NULL;
		while (root->right)
		{
			root = root->right;
		}
		root->right = tmp;
	}
};

//迭代版本
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
	void flatten(TreeNode* root)
	{
		TreeNode *cur = root;
		while (cur)
		{
			if (cur->left)
			{
				TreeNode *p = cur->left;
				while (p->right)
				{
					p = p->right;
				}
				p->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
	}
};

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
	void flatten(TreeNode* root) {
		TreeNode* last = NULL;
		preorder(root, last);
	}
	void preorder(TreeNode* root, TreeNode* &last)//这里得传引用
	{
		if (!root)
		{
			return;
		}
		if (!root->left && !root->right)
		{
			last = root;
			return;
		}
		TreeNode* left = root->left;
		TreeNode* right = root->right;//需要先备份，否则下面root->right修改过后又使用left_last->right会出错
		TreeNode* left_last = NULL;
		TreeNode* right_last = NULL;
		if (left)
		{
			preorder(root->left, left_last);
			root->left = NULL;
			root->right = left;
			last = left_last;
		}
		if (right)
		{
			preorder(right, right_last);
			if (left_last)
			{
				left_last->right = right;
			}
			last = right_last;
		}
	}
};

//复习
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	void flatten(TreeNode* root) {
		if (!root)
		{
			return;
		}
		if (root->left)
		{
			flatten(root->left);
		}
		if (root->right)
		{
			flatten(root->right);
		}
		TreeNode *tmp = root->right;
		root->right = root->left;
		root->left = NULL;
		while (root->right)
		{
			root = root->right;
		}
		root->right = tmp;
		return;
	}
};