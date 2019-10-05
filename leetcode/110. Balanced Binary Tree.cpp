//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

//方法1
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
	int depth(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}
		return max(depth(root->left), depth(root->right)) + 1;
	}
	bool isBalanced(TreeNode* root)
	{
		if (!root)
		{
			return true;
		}
		int left = depth(root->left);
		int right = depth(root->right);
		return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
};
//方法2
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
	int depth(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}
		int leftheight = depth(root->left);
		if (leftheight == -1)
		{
			return -1;
		}
		int rightheight = depth(root->right);
		if (rightheight == -1)
		{
			return -1;
		}
		if (abs(leftheight - rightheight)>1)
		{
			return -1;
		}
		return max(leftheight, rightheight) + 1;
	}
	bool isBalanced(TreeNode* root)
	{
		return depth(root) != -1;
	}
};


class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (!root)
		{
			return true;
		}
		if (abs(getdepth(root->left) - getdepth(root->right))>1)
		{
			return false;
		}
		return isBalanced(root->left) && isBalanced(root->right);
	}
	int getdepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return 1 + max(getdepth(root->left), getdepth(root->right));
	}

};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (checkdepth(root) == -1)
		{
			return false;
		}
		return true;
	}
	int checkdepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		int left = checkdepth(root->left);
		int right = checkdepth(root->right);
		if (left == -1)
		{
			return -1;
		}
		if (right == -1)
		{
			return -1;
		}
		if (abs(left - right)>1)
		{
			return -1;
		}
		else
		{
			return 1 + max(left, right);
		}
	}
};