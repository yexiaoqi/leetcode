//同leetcode572，但最优解可以是用kmp算法的
class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (isSame(s, t))
		{
			return true;
		}
		return s && (isSubtree(s->left, t) || isSubtree(s->right, t));//注意s&&，否则s为空t不为空又去找s的子节点会错
	}
	bool isSame(TreeNode* s, TreeNode *t)
	{
		if (!t && !s)
		{
			return true;
		}
		if ((t && !s) || (!t&&s) || (s->val != t->val))
		{
			return false;
		}
		return isSame(s->left, t->left) && isSame(s->right, t->right);
	}
};