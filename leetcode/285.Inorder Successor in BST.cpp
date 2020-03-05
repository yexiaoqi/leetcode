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
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (!root)
		{
			return NULL;
		}
		vector<TreeNode*> res;
		MakeVec(root, res);
		int n = res.size();
		for (int i = 0; i<n - 1; ++i)
		{
			if (p->val == res[i]->val)
			{
				return res[i + 1];
			}
		}
		return NULL;
	}
	void MakeVec(TreeNode* root, vector<TreeNode*> &res)
	{
		if (!root)
		{
			return;
		}
		MakeVec(root->left, res);
		res.push_back(root);
		MakeVec(root->right, res);
	}
};


//更好的方法
//我们首先看根节点值和p节点值的大小，如果根节点值大，说明p节点肯定在左子树中，
//那么此时我们先将 res 赋为 root，然后 root 移到其左子节点，循环的条件是 root 存在，
//我们再比较此时 root 值和p节点值的大小，如果还是 root 值大，我们重复上面的操作，如果p节点值>root->val，
//那么我们将 root 移到其右子节点，这样当 root 为空时，res 指向的就是p的后继节点，
class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		TreeNode *res = NULL;
		while (root)
		{
			if (root->val>p->val)
			{
				res = root;
				root = root->left;
			}
			else
			{
				root = root->right;
			}
		}
		return res;
	}
};