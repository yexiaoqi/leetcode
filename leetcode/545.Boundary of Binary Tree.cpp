//最直接的方法就是分别按顺序求出左边界结点，叶结点，和右边界结点。那么如何求的，
//对于树的操作肯定是用递归最简洁啊，所以可以写分别三个递归函数来分别求左边界结点，
//叶结点，和右边界结点。首先要处理根结点的情况，当根结点没有左右子结点时，
//其也是一个叶结点，那么一开始就将其加入结果 res 中，那么再计算叶结点的时候又会再加入一次，
//这样不对。所以判断如果根结点至少有一个子结点，才提前将其加入结果 res 中。然后再来看求左边界结点的函数，
//如果当前结点不存在，或者没有子结点，直接返回。否则就把当前结点值加入结果 res 中，然后看如果左子结点存在，
//就对其调用递归函数，反之如果左子结点不存在，那么对右子结点调用递归函数。而对于求右边界结点的函数就反过来了，
//如果右子结点存在，就对其调用递归函数，反之如果右子结点不存在，就对左子结点调用递归函数，
//注意在调用递归函数之后才将结点值加入结果 res，因为是需要按逆时针的顺序输出。最后就来看求叶结点的函数，
//没什么可说的，就是看没有子结点存在了就加入结果 res，然后对左右子结点分别调用递归即可，
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

	void LeftBoundary(TreeNode* root, vector<int> &res)
	{
		if (!root || (!root->left && !root->right))
		{
			return;
		}
		res.push_back(root->val);
		if (root->left)
		{
			LeftBoundary(root->left, res);
		}
		else
		{
			LeftBoundary(root->right, res);
		}
	}
	void RightBoundary(TreeNode* root, vector<int> &res)
	{
		if (!root || (!root->left && !root->right))
		{
			return;
		}
		if (root->right)
		{
			RightBoundary(root->right, res);
		}
		else
		{
			RightBoundary(root->left, res);
		}
		res.push_back(root->val);
	}
	void Leaf(TreeNode* root, vector<int> &res)
	{
		if (!root)
		{
			return;
		}
		if (!root->left && !root->right)
		{
			res.push_back(root->val);
		}
		Leaf(root->left, res);
		Leaf(root->right, res);
	}
	vector<int> boundaryOfBinaryTree(TreeNode* root) {
		vector<int> res;
		if (!root)
		{
			return res;
		}
		if (root->left || root->right)
		{
			res.push_back(root->val);
		}
		LeftBoundary(root->left, res);
		Leaf(root, res);
		RightBoundary(root->right, res);
		return res;
	}
};