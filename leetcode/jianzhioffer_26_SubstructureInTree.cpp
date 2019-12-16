//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��


//�Լ�д�ģ����ԣ���Ϊ���ظ�����������AΪһ����1��������1��BΪ1����ֻ�ж���A�ĸ��ڵ��B�ȣ��������ṹ��һ���ͷ���false�ˣ�ʵ���Ͽ�����A�ĵڶ���1��B��
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		TreeNode* root1 = new TreeNode(-1);
		DFS(pRoot1, pRoot2->val, root1);
		if (!root1)
		{
			return false;
		}
		else
		{
			bool res = judge(root1, pRoot2);
			return res;
		}
	}
	bool judge(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot1 && !pRoot2)
		{
			return true;
		}
		if ((pRoot1 && !pRoot2) || (pRoot2 && !pRoot1) || pRoot1->val != pRoot2->val)
		{
			return false;
		}
		if (pRoot1->val == pRoot2->val)
		{
			judge(pRoot1->left, pRoot2->left);
			judge(pRoot1->right, pRoot2->right);
		}

	}
	TreeNode* DFS(TreeNode* root, int target, TreeNode* &res)
	{
		if (!root)
		{
			return NULL;
		}
		if (root->val == target)
		{
			res = root;
			return root;
		}
		DFS(root->left, target, res);
		DFS(root->right, target, res);
		return res;
	}
};