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


//���õķ���
//�������ȿ����ڵ�ֵ��p�ڵ�ֵ�Ĵ�С��������ڵ�ֵ��˵��p�ڵ�϶����������У�
//��ô��ʱ�����Ƚ� res ��Ϊ root��Ȼ�� root �Ƶ������ӽڵ㣬ѭ���������� root ���ڣ�
//�����ٱȽϴ�ʱ root ֵ��p�ڵ�ֵ�Ĵ�С��������� root ֵ�������ظ�����Ĳ��������p�ڵ�ֵ>root->val��
//��ô���ǽ� root �Ƶ������ӽڵ㣬������ root Ϊ��ʱ��res ָ��ľ���p�ĺ�̽ڵ㣬

//Ҳ����res�ǵ�ǰ�ڵ�ֵ��Ȼ������ǰһ���ڵ㣬��ôǰһ���ڵ����p��֮��res��������Ҫ�ҵĺ�һ���ڵ�
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


//�ȽϺ����ķ���
��������ĵݹ�д����������Ҫ�������� pre �� res��Ȼ���ڽ��еݹ��������ʱ�����ڱ������Ľڵ㣬
�������ȿ� pre ��p�Ƿ���ͬ�������ͬ���� res ��Ϊ��ǰ�ڵ㣬Ȼ�� pre ��Ϊ root����ô�ڱ�����һ���ڵ�ʱ��
pre ���𵽼�¼��һ���ڵ������
class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (!p)
		{
			return NULL;
		}
		TreeNode* pre = NULL;
		TreeNode* res = NULL;
		inorder(root, pre, res, p);
		return res;
	}
	void inorder(TreeNode* root, TreeNode* &pre, TreeNode* &res, TreeNode* p)
	{
		if (!root)
		{
			return;
		}
		inorder(root->left, pre, res, p);
		if (pre == p)
		{
			res = root;
		}
		pre = root;
		inorder(root->right, pre, res, p);
	}
};