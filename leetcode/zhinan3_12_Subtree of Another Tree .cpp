//ͬleetcode572�������Ž��������kmp�㷨��
class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (isSame(s, t))
		{
			return true;
		}
		return s && (isSubtree(s->left, t) || isSubtree(s->right, t));//ע��s&&������sΪ��t��Ϊ����ȥ��s���ӽڵ���
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