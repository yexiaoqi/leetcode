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