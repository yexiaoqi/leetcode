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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> path;
		int path_value = 0;
		search(root, path_value, sum, path, res);
		return res;
	}
	void search(TreeNode* root, int &pathvalue, int sum, vector<int> &path, vector<vector<int>> &res)
	{
		if (!root)
		{
			return;
		}
		path.push_back(root->val);
		pathvalue += root->val;
		if (!root->left&&!root->right&&pathvalue == sum)
		{
			res.push_back(path);
		}
		search(root->left, pathvalue, sum, path, res);
		search(root->right, pathvalue, sum, path, res);
		path.pop_back();
		pathvalue -= root->val;
	}
};