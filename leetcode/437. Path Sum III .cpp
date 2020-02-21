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
	int pathSum(TreeNode* root, int target) {
		vector<int> path;
		int sum = 0, res = 0;
		FindPath(root, target, sum, path, res);
		return res;
	}
	void FindPath(TreeNode* root, int target, int sum, vector<int> &path, int &res)
	{
		if (!root)
		{
			return;
		}
		sum += root->val;
		path.push_back(root->val);
		if (sum == target)
		{
			++res;
		}
		int tmp = sum;
		for (int i = 0; i<path.size() - 1; ++i)
		{
			tmp -= path[i];
			if (tmp == target)
			{
				++res;
			}
		}
		FindPath(root->left, target, sum, path, res);
		FindPath(root->right, target, sum, path, res);
		sum -= root->val;
		path.pop_back();
	}
};