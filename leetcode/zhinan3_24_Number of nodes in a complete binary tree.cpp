//ͬleetcode222
//O(n)�ⷨ
class Solution {
public:
	int countNodes(TreeNode* root) {
		queue<TreeNode*> q;
		if (!root)
		{
			return 0;
		}
		q.push(root);
		int res = 0;
		while (!q.empty())
		{
			int n = q.size();
			for (int i = 0; i<n; ++i)
			{
				TreeNode* tmp = q.front();
				q.pop();
				++res;
				if (tmp->left)
				{
					q.push(tmp->left);
				}
				if (tmp->right)
				{
					q.push(tmp->right);
				}
			}
		}
		return res;
	}
};

//O(n)�ⷨ2,�ռ临�Ӷ�O��logn�������й����ж�ջ��ʹ�õĿռ䡣
class Solution {
public:
	int countNodes(TreeNode* root) {
		return root ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
	}
};



//O(h^2)�ⷨ��h�����ĸ߶ȣ�
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		int h = GetHeight(root);
		if (GetHeight(root->right) == h - 1)
		{
			return (1 << h) + countNodes(root->right);//ע���()��<<���ȼ���
		}
		else
		{
			return (1 << (h - 1)) + countNodes(root->left);//ע���()��<<���ȼ���
		}
	}
	int GetHeight(TreeNode* root)
	{
		return root ? (1 + GetHeight(root->left)) : -1;
	}
};