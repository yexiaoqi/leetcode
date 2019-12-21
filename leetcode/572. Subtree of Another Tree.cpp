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
	bool Equal(double num1, double num2)
	{
		if (abs(num1 - num2)<0.0000001)
		{
			return true;
		}
		return false;
	}//注意判断两个浮点数是否相等时，不能直接写成==，因为计算机内表示小数有误差
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool res = false;

		if (pRoot1&&pRoot2)
		{
			if (Equal(pRoot1->val, pRoot2->val))
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
		if (!Equal(s->val, t->val))
		{
			return false;
		}
		return issame(s->left, t->left) && issame(s->right, t->right);
	}
};

