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


//自己写的，还不够简洁
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
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		vector<int> one;
		vector<vector<int>> res;
		if (!root)
		{
			return res;
		}
		one.push_back(root->val);
		preorder(root, root->val, target, one, res);
		return res;
	}
	void preorder(TreeNode* root, int sum, int target, vector<int> &one, vector<vector<int>> &res)
	{
		if (!root)
		{
			return;
		}
		if (!root->left && !root->right)
		{
			if (sum == target)
			{
				sum = 0;
				res.push_back(one);
			}
			//return res;
		}
		if (root->left)
		{
			sum += root->left->val;
			one.push_back(root->left->val);
			preorder(root->left, sum, target, one, res);
			sum -= root->left->val;
			one.pop_back();
		}
		if (root->right)
		{
			sum += root->right->val;
			one.push_back(root->right->val);
			preorder(root->right, sum, target, one, res);
			sum -= root->right->val;
			one.pop_back();
		}
	}
};

//调试用
int main()
{
	Solution s;
	vector<int> nums{ 1,1,2,2,2 };
	TreeNode a(5);
	TreeNode b(4);
	TreeNode c(8);
	TreeNode d(11);
	TreeNode e(13);
	TreeNode f(4);
	TreeNode g(7);
	TreeNode h(2);
	TreeNode i(5);
	TreeNode j(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	c.left = &e;
	c.right = &f;
	d.left = &g;
	d.right = &h;
	f.left = &i;
	f.right = &j;
	s.pathSum(&a, 22);
	return 0;
}