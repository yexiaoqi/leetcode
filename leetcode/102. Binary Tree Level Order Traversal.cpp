//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its level order traversal as :
//[
//	[3],
//	[9, 20],
//	[15, 7]
//]

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution
{
public:
	vector<vector<int>> ret;
	void buildvector(TreeNode *root, int depth)
	{
		if (!root)
		{
			return;
		}
		if (ret.size() == depth)
		{
			ret.push_back(vector<int>());//每次新多一层，就要新建一个vector<int>()存放该层的值
		}
		ret[depth].push_back(root->val);//在第depth层增加值
		buildvector(root->left, depth + 1);
		buildvector(root->right, depth + 1);
	}
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		buildvector(root, 0);
		return ret;
	}
};