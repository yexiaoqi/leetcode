//����д̫���ظ�����
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (!pRoot)
		{
			return true;
		}
		int nleft = level(pRoot->left);
		int nright = level(pRoot->right);
		if (abs(nleft - nright)>1)
		{
			return false;
		}
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	}
	int level(TreeNode* pRoot)
	{
		if (!pRoot)
		{
			return 0;
		}
		int nleft = level(pRoot->left);
		int nright = level(pRoot->right);
		return nleft>nright ? (nleft + 1) : (nright + 1);
	}
};


class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
		return IsBalanced(pRoot, depth);
	}
	bool IsBalanced(TreeNode* pRoot, int &depth)//��������ʽ
	{
		if (!pRoot)
		{
			depth = 0;
			return true;
		}
		int left, right;
		if (IsBalanced(pRoot->left, left) && IsBalanced(pRoot->right, right))
		{
			if (abs(left - right) <= 1)
			{
				depth = 1 + (left>right ? left : right);
				return true;
			}
		}
		return false;
	}
};


class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
		return IsBalanced(pRoot, &depth);
	}
	bool IsBalanced(TreeNode* pRoot, int *depth)//depth���Ƿ���ֵ����ָ����ʽ
	{
		if (!pRoot)
		{
			*depth = 0;
			return true;
		}
		int left, right;
		if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right))
		{
			if (abs(left - right) <= 1)
			{
				*depth = 1 + (left>right ? left : right);
				return true;
			}
		}
		return false;
	}
};