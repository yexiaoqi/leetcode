/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//二叉搜索树，不仅仅要满足每个节点的左子节点小于该值，应该要满足这个节点的左子树上的所有节点都小于该值
//比如[10,5,15,null,null,6,20]就不是一棵二叉搜索树
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isvalid(root, LONG_MIN, LONG_MAX);//要设置为long 的最大最小值
	}
	bool isvalid(TreeNode* root, long mn, long mx)//要设置为long 
	{
		if (!root)
		{
			return true;
		}
		if (root->val <= mn || root->val >= mx)
		{
			return false;
		}
		return isvalid(root->left, mn, root->val) && isvalid(root->right, root->val, mx);
	}

};


//方法二
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		vector<int> res;
		if (!root)
		{
			return true;
		}
		isvalid(root, res);
		for (int i = 0; i<res.size() - 1; ++i)
		{
			if (res[i + 1] <= res[i])
			{
				return false;
			}
		}
		return true;
	}
	void isvalid(TreeNode* root, vector<int> &res)//要设置为long 
	{
		if (!root)
		{
			return;
		}
		isvalid(root->left, res);
		res.push_back(root->val);
		isvalid(root->right, res);
	}

};