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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path;
		vector<vector<TreeNode*>> res;
		TreeNode* ancestor;
		search(root, p->val, path, res);
		search(root, q->val, path, res);
		int min_len = min(res[0].size(), res[1].size());
		for (int i = 0; i<min_len; ++i)
		{
			if (res[0][i]->val == res[1][i]->val)
			{
				ancestor = res[0][i];
			}
		}
		return ancestor;
	}
	void search(TreeNode* root, int value, vector<TreeNode*> &path, vector<vector<TreeNode*>> &res)
	{
		if (!root)
		{
			return;
		}
		path.push_back(root);
		if (value == root->val)
		{
			res.push_back(path);
		}
		search(root->left, value, path, res);
		search(root->right, value, path, res);
		path.pop_back();
	}
};