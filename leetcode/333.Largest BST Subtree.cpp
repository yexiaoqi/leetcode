//�Ѷ������������ת��Ϊ���飬Ȼ����������е��뷨�����У�����[10,5,15,1,8,null,7]�������Ϊ5������
//ʵ�������Ķ������ڵ����Ϊ3



//O(n^2)���Ӷ�����
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
	int largestBSTSubtree(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		if (isValid(root, LONG_MIN, LONG_MAX))
		{
			return count(root);
		}
		return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
	}
	bool isValid(TreeNode* root, long mn, long mx)
	{
		if (!root)
		{
			return true;
		}
		if (root->val <= mn || root->val >= mx)
		{
			return false;
		}
		return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
	}
	int count(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}
		return count(root->left) + count(root->right) + 1;
	}
};



//O(n)�ⷨ
class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		vector<int> res = BST(root);
		return res[2];
	}
	vector<int> BST(TreeNode* root)
	{
		if (!root)
		{
			return{ INT_MAX,INT_MIN,0 };
		}
		vector<int> left = BST(root->left);
		vector<int> right = BST(root->right);
		if (root->val>left[1] && root->val<right[0])
		{
			return{ min(root->val,left[0]),max(root->val,right[1]),left[2] + right[2] + 1 };
		}
		else
		{
			return{ INT_MIN,INT_MAX,max(left[2],right[2]) };
		}
	}
};