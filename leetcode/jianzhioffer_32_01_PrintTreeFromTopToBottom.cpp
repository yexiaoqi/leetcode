//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
//同leetcode102
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		vector<vector<int>> path;
		int level = 0;
		TopToBottom(root, path, level);
		for (int i = 0; i<int(path.size()); ++i)
		{
			for (int j = 0; j<int(path[i].size()); ++j)
			{
				res.push_back(path[i][j]);
			}
		}
		return res;
	}
	void TopToBottom(TreeNode* root, vector<vector<int>> &path, int level)
	{
		if (!root)
		{
			return;
		}
		if (level == path.size())
		{
			path.push_back(vector<int>());
		}
		path[level].push_back(root->val);
		TopToBottom(root->left, path, level + 1);
		TopToBottom(root->right, path, level + 1);
	}
};