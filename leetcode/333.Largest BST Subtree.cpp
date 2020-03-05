//把二叉树中序遍历转化为数组，然后看最长升序序列的想法不可行，比如[10,5,15,1,8,null,7]，最长数组为5，但是
//实际上最大的二叉树节点个数为3



//O(n^2)复杂度做法
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
	int largestBSTSubtree(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		if (isValid(root, LONG_MIN, LONG_MAX))
		{
			return count(root);
		}
		return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
	}
	bool isValid(TreeNode* root, long mn, long mx)
	{
		if (!root)
		{
			return true;
		}
		if (root->val <= mn || root->val >= mx)
		{
			return false;
		}
		return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
	}
	int count(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}
		return count(root->left) + count(root->right) + 1;
	}
};



//O(n)解法
class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		vector<int> res = BST(root);
		return res[2];
	}
	vector<int> BST(TreeNode* root)
	{
		if (!root)
		{
			return{ INT_MAX,INT_MIN,0 };
		}
		vector<int> left = BST(root->left);
		vector<int> right = BST(root->right);
		if (root->val>left[1] && root->val<right[0])
		{
			return{ min(root->val,left[0]),max(root->val,right[1]),left[2] + right[2] + 1 };
		}
		else
		{
			return{ INT_MIN,INT_MAX,max(left[2],right[2]) };
		}
	}
};