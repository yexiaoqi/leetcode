//同剑指offer59——01
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
	int maxDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};

//方法二
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return 1 + max(left, right);
		//return 1+max(maxDepth(root->left),maxDepth(root->right));
	}
};