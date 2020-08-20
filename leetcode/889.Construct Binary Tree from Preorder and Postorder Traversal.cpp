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
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		int m = pre.size(), n = post.size();
		return construct(pre, post, 0, m - 1, 0, n - 1);
	}
	TreeNode* construct(vector<int> &pre, vector<int>& post, int prel, int prer, int postl, int postr)
	{
		if (prel>prer || postl>postr)
		{
			return NULL;
		}
		TreeNode *root = new TreeNode(pre[prel]);
		if (prel == prer)
		{
			return root;
		}
		int i = postl;
		for (; i <= postr; ++i)
		{
			if (pre[prel + 1] == post[i])
			{
				break;
			}
		}
		root->left = construct(pre, post, prel + 1, prel + i - postl + 1, postl, i);
		root->right = construct(pre, post, prel + i - postl + 2, prer, i + 1, postr - 1);
		return root;
	}
};