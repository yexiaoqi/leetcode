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
	bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {

		if (!pRoot1)
		{
			return false;
		}
		if (issame(pRoot1, pRoot2))
		{
			return true;
		}
		return isSubtree(pRoot1->left, pRoot2) || isSubtree(pRoot1->right, pRoot2);
	}
	bool issame(TreeNode* s, TreeNode* t)
	{
		if (!s && !t)
		{
			return true;
		}
		if (!s || !t)
		{
			return false;
		}
		if (s->val != t->val)
		{
			return false;
		}
		return issame(s->left, t->left) && issame(s->right, t->right);
	}

};




class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool res = false;

		if (pRoot1&&pRoot2)
		{
			if (pRoot1->val == pRoot2->val)
			{
				res = issame(pRoot1, pRoot2);
			}
			if (!res)
			{
				res = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!res)
			{
				res = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return res;
	}
	bool issame(TreeNode* s, TreeNode* t)
	{
		if (!t)
		{
			return true;
		}
		if (!s)
		{
			return false;
		}
		if (s->val != t->val)
		{
			return false;
		}
		return issame(s->left, t->left) && issame(s->right, t->right);
	}
};