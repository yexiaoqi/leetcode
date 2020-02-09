//自己做出,这个求的是第k小的节点，书上有误
//同leetcode230，注意有进阶题
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		TreeNode* res = 0;
		int cnt = 0;
		order(pRoot, k, res, cnt);
		return res;
	}
	void order(TreeNode* &pRoot, int k, TreeNode* &res, int &cnt)
	{
		if (!pRoot)
		{
			return;
		}
		order(pRoot->left, k, res, cnt);
		++cnt;
		if (cnt == k)
		{
			res = pRoot;
			return;
		}
		order(pRoot->right, k, res, cnt);
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


//复习，自己做出，一遍ac
class Solution {
public:
	TreeNode* KthNode(TreeNode* root, int k)
	{
		if (k <= 0 || !root)
		{
			return NULL;
		}
		int cnt = 0;
		TreeNode *res = NULL;
		KthNode(root, k, cnt, res);
		return res;
	}
	void KthNode(TreeNode* root, int k, int &cnt, TreeNode *&res)
	{
		if (!root)
		{
			return;
		}
		KthNode(root->left, k, cnt, res);
		++cnt;
		if (cnt == k)
		{
			res = root;
			return;
		}
		KthNode(root->right, k, cnt, res);
	}

};