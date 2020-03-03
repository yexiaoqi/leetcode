//�ڵݹ麯���У������ǰ��㲻���ڣ�ֱ�ӷ���0������ͷֱ���������ӽڵ���õݹ麯����
//����·�����п���Ϊ���������ﵱȻ��ϣ�����ϸ���·���ͣ����Ժ�0��ȣ�ȡ�ϴ���Ǹ���
//����Ҫô���ӣ��Ӿ�Ҫ��������Ȼ��������ȫ�����ֵ��� res��
//���������ӽ��Ϊ�յ����� path ֮�ͼ��������ӽ��Ϊ�յ����� path ֮�ͣ�
//��Ҫ���ϵ�ǰ���ֵ�������������һ����������·����
//������ֵ��ȡ left �� right �еĽϴ�ֵ���ϵ�ǰ���ֵ����Ϊ����ֵ�Ķ������Ե�ǰ���Ϊ�յ�� path ֮�ͣ�
//����ֻ��ȡ left �� right �нϴ���Ǹ�ֵ��������������Ҫ
public:
	int maxPathSum(TreeNode* root) {
		int maxres = 0;
		if (!root)
		{
			return maxres;
		}
		maxPath(root, maxres);
		return maxres;
	}
	int maxPath(TreeNode *root, int &res)
	{
		if (!root)
		{
			return;
		}
		int left = max(maxPath(root->left, res), 0);
		int right = max(maxPath(root->right, res), 0);
		res = max(res, left + right + root->val);
		return max(left, right) + root->val;
	}
};