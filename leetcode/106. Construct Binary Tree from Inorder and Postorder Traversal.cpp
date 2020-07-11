

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
		TreeNode* cur = new TreeNode(postorder[pright]);//注意新建节点，而不是直接赋值postorder[pright]
		cur->left = build(inorder, ileft, i - 1, postorder, pleft, pleft + i - ileft - 1);
		/*比如in[]   = {4, 8, 2, 5, 1, 6, 3, 7}，post[] = {8, 4, 5, 2, 6, 7, 3, 1}
		i是in中的1的位置，ileft是in中的4的位置，相减得4，pleft是post中8的位置，+4-1得到post中2所在位置*/
		cur->right = build(inorder, i + 1, iright, postorder, pleft + i - ileft, pright - 1);

		return cur;
	}
};

//复习
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