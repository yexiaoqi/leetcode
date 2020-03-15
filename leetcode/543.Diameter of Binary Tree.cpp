//自己的方法
class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		int left = Maxdepth(root->left);
		int right = Maxdepth(root->right);
		int res = left + right;
		res = max(res, diameterOfBinaryTree(root->left));
		res = max(res, diameterOfBinaryTree(root->right));
		return res;
	}
	int Maxdepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return 1 + max(Maxdepth(root->left), Maxdepth(root->right));
	}
};

//优化
class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int res = 0;
		Maxdepth(root, res);
		return res;
	}
	int Maxdepth(TreeNode* root, int &res)
	{
		if (!root)
		{
			return 0;
		}
		int left = Maxdepth(root->left, res);
		int right = Maxdepth(root->right, res);
		res = max(res, left + right);
		return max(left, right) + 1;
	}
};