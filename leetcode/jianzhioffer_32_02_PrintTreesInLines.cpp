//自己做出
//同leetcode102
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		int level = 0;
		vector<vector<int>> all;
		print2(pRoot, level, all);
		return all;
	}
	void print2(TreeNode* pRoot, int level, vector<vector<int>> &all)
	{
		if (!pRoot)
		{
			return;
		}
		if (all.size() == level)
		{
			all.push_back(vector<int>());
		}
		all[level].push_back(pRoot->val);
		if (pRoot->left)
		{
			print2(pRoot->left, level + 1, all);
		}
		if (pRoot->right)
		{
			print2(pRoot->right, level + 1, all);
		}
	}
};