/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//https://blog.csdn.net/gyqjn/article/details/52709972
//https://www.cnblogs.com/grandyang/p/4296500.html
//https://blog.csdn.net/sgbfblog/article/details/7783935
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
	TreeNode* build(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright)
	{
		if (pleft>pright || ileft>iright)
		{
			return NULL;
		}
		int i = 0;
		for (i = ileft; i <= iright; ++i) // 在中序中找到根节点的位置，【依次】将先序序列和中序序列分成左右字树，分别构建左右子树。//i从ileft而不是0开始
		{
			if (preorder[pleft] == inorder[i])
			{
				break;
			}
		}
		TreeNode* cur = new TreeNode(preorder[pleft]);//这一行不能在if (pleft>pright || ileft>iright)上面，否则pleft有可能越界
		cur->left = build(preorder, pleft + 1, pleft + i - ileft, inorder, ileft, i - 1);//pleft+i-ileft，pleft开始，最右边是加上i-ileft
	/*例如preorder = {7,10,4,3,1,2,8,11},inorder = {4,10,3,1,7,11,8,2}，
	pleft是preorder中的2，i是inorder的2所在位置，ileft是inorder的11所在位置，相减得2，pleft+2就是preorder中的11*/
		cur->right = build(preorder, pleft + i - ileft + 1, pright, inorder, i + 1, iright);
		return cur;
	}
};