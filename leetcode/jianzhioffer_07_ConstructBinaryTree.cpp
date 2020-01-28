//同leetcode105
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		return build(pre, 0, int(pre.size()) - 1, vin, 0, int(vin.size()) - 1);
	}
	TreeNode* build(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright)
	{

		if (pleft>pright || ileft>iright)
		{
			return NULL;
		}
		TreeNode* res = new TreeNode(preorder[pleft]);
		int i = 0;
		for (i = ileft; i <= iright; ++i)
		{
			if (preorder[pleft] == inorder[i])
			{
				break;
			}
		}
		res->left = build(preorder, pleft + 1, pleft + i - ileft, inorder, ileft, i - 1);
		res->right = build(preorder, pleft + i - ileft + 1, pright, inorder, i + 1, iright);
		return res;
	}
};


//复习，自己做出
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0)
		{
			return NULL;
		}
		TreeNode* root = construct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
		return root;
	}
	TreeNode* construct(vector<int> &pre, int pleft, int pright,
		vector<int> &vin, int ileft, int iright)
	{
		if (pleft>pright || ileft>iright)
		{
			return NULL;
		}
		int i = ileft;
		for (i = ileft; i <= iright; ++i)
		{
			if (vin[i] == pre[pleft])
			{
				break;
			}
		}
		TreeNode* root = new TreeNode(pre[pleft]);
		root->left = construct(pre, pleft + 1, i - ileft + pleft, vin, ileft, i - 1);
		root->right = construct(pre, i - ileft + pleft + 1, pright, vin, i + 1, iright);
		return root;
	}
};