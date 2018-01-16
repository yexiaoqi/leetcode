//Given a binary tree, flatten it to a linked list in - place.
//
//For example,
//Given
//
//1
/// \
//2   5
/// \   \
//3   4   6
//The flattened tree should look like :
//1
//\
//2
//\
//3
//\
//4
//\
//5
//\
//6

//µÝ¹é°æ±¾
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
	void flatten(TreeNode* root)
	{
		if (!root)
		{
			return;
		}
		if (root->left)
		{
			flatten(root->left);
		}
		if (root->right)
		{
			flatten(root->right);
		}
		TreeNode *tmp = root->right;
		root->right = root->left;
		root->left = NULL;
		while (root->right)
		{
			root = root->right;
		}
		root->right = tmp;
	}
};

//µü´ú°æ±¾
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
	void flatten(TreeNode* root)
	{
		TreeNode *cur = root;
		while (cur)
		{
			if (cur->left)
			{
				TreeNode *p = cur->left;
				while (p->right)
				{
					p = p->right;
				}
				p->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
	}
};