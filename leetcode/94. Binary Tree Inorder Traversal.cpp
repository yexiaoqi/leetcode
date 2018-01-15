//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example :
//Given binary tree[1, null, 2, 3],
//1
//\
//2
///
//3
//return[1, 3, 2].
//
//Note: Recursive solution is trivial, could you do it iteratively ?
//

//方法一 迭代
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
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int>result;
		vector<TreeNode*> temp;
		while (root || !temp.empty())
		{
			if (root)
			{
				temp.push_back(root);
				root = root->left;
			}
			else
			{
				root = temp.back();
				result.push_back(temp.back()->val);
				temp.pop_back();
				root = root->right;
			}
		}
		return result;
	}
};

//方法二 递归
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
	vector<int> v;
	vector<int> inorderTraversal(TreeNode* root)
	{
		if (root)
		{
			inorderTraversal(root->left);
			v.push_back(root->val);
			inorderTraversal(root->right);
		}
		return v;
	}
};