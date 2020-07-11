

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
	TreeNode* build(vector<int>& inorder, int ileft, int iright, vector<int>& postorder, int pleft, int pright)
	{
		if (pleft>pright || ileft>iright)
		{
			return NULL;
		}
		int i = 0;
		for (i = ileft; i <= iright; ++i)
		{
			if (postorder[pright] == inorder[i])
			{
				break;
			}
		}
		TreeNode* cur = new TreeNode(postorder[pright]);//ע���½��ڵ㣬������ֱ�Ӹ�ֵpostorder[pright]
		cur->left = build(inorder, ileft, i - 1, postorder, pleft, pleft + i - ileft - 1);
		/*����in[]   = {4, 8, 2, 5, 1, 6, 3, 7}��post[] = {8, 4, 5, 2, 6, 7, 3, 1}
		i��in�е�1��λ�ã�ileft��in�е�4��λ�ã������4��pleft��post��8��λ�ã�+4-1�õ�post��2����λ��*/
		cur->right = build(inorder, i + 1, iright, postorder, pleft + i - ileft, pright - 1);

		return cur;
	}
};

//��ϰ
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}
	TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder, int ileft, int iright, int pleft, int pright)
	{
		if (ileft>iright || pleft>pright)
		{
			return NULL;
		}
		TreeNode* res = new TreeNode(postorder[pright]);
		int i = ileft;
		for (; i <= iright; ++i)
		{
			if (inorder[i] == postorder[pright])
			{
				break;
			}
		}
		res->left = buildTree(inorder, postorder, ileft, i - 1, pleft, pleft + i - ileft - 1);
		res->right = buildTree(inorder, postorder, i + 1, iright, pleft + i - ileft, pright - 1);
		return res;
	}
};