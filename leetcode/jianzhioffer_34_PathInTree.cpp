//同leetcode113
//输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
bool compare(vector<int> a, vector<int> b)
{
	return a.size()>b.size();
}
class Solution {
public:

	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> res;
		if (!root)
		{
			return res;
		}
		vector<int> path;
		Find(0, root, expectNumber, res, path);
		sort(res.begin(), res.end(), compare);
		return res;
	}
	void Find(int sum, TreeNode* root, int expectNumber, vector<vector<int>> &res, vector<int> &path)
	{
		if (!root)
		{
			return;
		}
		sum += root->val;
		path.push_back(root->val);
		if (!root->left && !root->right)
		{
			if (sum == expectNumber)
			{
				res.push_back(path);
			}
		}
		Find(sum, root->left, expectNumber, res, path);
		Find(sum, root->right, expectNumber, res, path);
		sum -= root->val;
		path.pop_back();
	}
};


//复习，自己做出，仔细
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<int> path;
		vector<vector<int>> res;
		int sum = 0;
		Find(root, expectNumber, path, res, sum);
		return res;
	}
	void Find(TreeNode* root, int target, vector<int> &path, vector<vector<int>> &res,
		int sum)
	{
		if (!root)
		{
			return;
		}
		path.push_back(root->val);
		sum += root->val;
		if (!root->left && !root->right)
		{
			if (sum == target)
			{
				res.push_back(path);
			}
		}
		Find(root->left, target, path, res, sum);
		Find(root->right, target, path, res, sum);
		path.pop_back();
		sum -= root->val;
	}
};