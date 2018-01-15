//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//
//For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//But the following[1, 2, 2, null, 3, null, 3] is not:
//1
/// \
//2   2
//\   \
//3    3
//Note:
//Bonus points if you could solve it both recursively and iteratively.

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
	bool isSymmetric(TreeNode* root)
	{
		return root == NULL || isSymmetricHelp(root->left, root->right);
	}
private:
	bool isSymmetricHelp(TreeNode *left, TreeNode *right)
	{
		return !left || !right ? left == right : left->val == right->val&&isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
	}
};

//方法二 迭代
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
	bool isSymmetric(TreeNode* root)
	{
		if (!root)
		{
			return true;
		}
		TreeNode *left, *right;
		queue<TreeNode*>q1, q2;
		q1.push(root->left);
		q2.push(root->right);
		while (!q1.empty() && !q2.empty())//q1,q2是队列而不是指针，所以不能用q1&&!q2
		{
			left = q1.front();
			q1.pop();
			right = q2.front();
			q2.pop();
			if (!left && !right)
			{
				continue;
			}//要加上这个判断，否则if(left->val!=right->val)有可能指向NULL的值出错
			if (!left || !right)//因为有上面这个判断，所以不用(left&&!right||!left&&right)
			{
				return false;
			}
			if (left->val != right->val)
			{
				return false;
			}
			q1.push(left->left);
			q1.push(left->right);
			q2.push(right->right);
			q2.push(right->left);
		}
		return true;
	}
};