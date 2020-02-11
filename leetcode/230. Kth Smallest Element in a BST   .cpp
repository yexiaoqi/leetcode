//同剑指offer54，注意有进阶题
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//方法一
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		TreeNode* res = new TreeNode(-1);
		int cnt = 0;
		find(root, k, res, cnt);
		return res->val;
	}
	void find(TreeNode* &root, int k, TreeNode* &res, int &cnt)//注意&
	{
		if (!root)
		{
			return;
		}
		find(root->left, k, res, cnt);
		++cnt;
		if (cnt == k)
		{
			res = root;
			return;
		}
		find(root->right, k, res, cnt);
	}
};

//方法二
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
	int kthSmallest(TreeNode* root, int k) {
		int cnt = countnode(root->left);
		if (cnt == k - 1)
		{
			return root->val;
		}
		else if (cnt<k - 1)
		{
			return kthSmallest(root->right, k - cnt - 1);
		}
		else
		{
			return kthSmallest(root->left, k);
		}
		//return -10;
	}
	int countnode(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return 1 + countnode(root->left) + countnode(root->right);
	}
};

//进阶：
//如果二叉搜索树经常被修改（插入 / 删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
struct NewTreeNode
{
	int val;
	int cnt;
	NewTreeNode *left;
	NewTreeNode *right;
	NewTreeNode(int v, int c) :val(v), cnt(c), left(NULL), right(NULL) {}
};
class Solution {
public:
	NewTreeNode* BuildTree(TreeNode* root)
	{
		if (!root)
		{
			return NULL;
		}
		NewTreeNode* node = new NewTreeNode(root->val, 1);
		node->left = BuildTree(root->left);
		node->right = BuildTree(root->right);
		if (node->left)
		{
			node->cnt += node->left->cnt;
		}
		if (node->right)
		{
			node->cnt += node->right->cnt;
		}
		return node;
	}
	int helper(NewTreeNode* &node, int k)
	{
		if (node->left)
		{
			int cnt = node->left->cnt;
			if (cnt == k - 1)
			{
				return node->val;
			}
			else if (cnt<k - 1)
			{
				return helper(node->right, k - cnt - 1);
			}
			else
			{
				return helper(node->left, k);
			}
		}
		else
		{
			if (k == 1)
			{
				return node->val;
			}
			else
			{
				return helper(node->right, k - 1);
			}
		}
	}
	int kthSmallest(TreeNode* root, int k)
	{
		NewTreeNode* node = BuildTree(root);
		return helper(node, k);
	}
};


//复习
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
struct NewTreeNode
{
	int val;
	int cnt;
	NewTreeNode *left;
	NewTreeNode *right;
	NewTreeNode(int v, int c) :val(v), cnt(c), left(NULL), right(NULL) {}
};
class Solution {
public:
	NewTreeNode* BuildTree(TreeNode *root)
	{
		if (!root)
		{
			return NULL;
		}
		NewTreeNode *node = new NewTreeNode(root->val, 1);
		node->left = BuildTree(root->left);
		node->right = BuildTree(root->right);
		if (node->left)
		{
			node->cnt += node->left->cnt;
		}
		if (node->right)
		{
			node->cnt += node->right->cnt;
		}
		return node;
	}
	int helper(NewTreeNode* node, int k)
	{
		if (node->left)
		{
			int cnt = node->left->cnt;
			if (cnt == k - 1)
			{
				return node->val;
			}
			else if (cnt>k - 1)
			{
				return helper(node->left, k);
			}
			else
			{
				return helper(node->right, k - cnt - 1);
			}
		}
		else
		{
			if (k == 1)
			{
				return node->val;
			}
			else
			{
				return helper(node->right, k - 1);
			}

		}
	}
	int kthSmallest(TreeNode* root, int k) {
		if (k <= 0 || !root)
		{
			return -1;
		}
		NewTreeNode* node = BuildTree(root);
		return helper(node, k);
	}

};