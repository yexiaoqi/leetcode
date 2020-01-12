/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//������������������Ҫ����ÿ���ڵ�����ӽڵ�С�ڸ�ֵ��Ӧ��Ҫ��������ڵ���������ϵ����нڵ㶼С�ڸ�ֵ
//����[10,5,15,null,null,6,20]�Ͳ���һ�ö���������
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isvalid(root, LONG_MIN, LONG_MAX);//Ҫ����Ϊlong �������Сֵ
	}
	bool isvalid(TreeNode* root, long mn, long mx)//Ҫ����Ϊlong 
	{
		if (!root)
		{
			return true;
		}
		if (root->val <= mn || root->val >= mx)
		{
			return false;
		}
		return isvalid(root->left, mn, root->val) && isvalid(root->right, root->val, mx);
	}

};


//������
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		vector<int> res;
		if (!root)
		{
			return true;
		}
		isvalid(root, res);
		for (int i = 0; i<res.size() - 1; ++i)
		{
			if (res[i + 1] <= res[i])
			{
				return false;
			}
		}
		return true;
	}
	void isvalid(TreeNode* root, vector<int> &res)//Ҫ����Ϊlong 
	{
		if (!root)
		{
			return;
		}
		isvalid(root->left, res);
		res.push_back(root->val);
		isvalid(root->right, res);
	}

};