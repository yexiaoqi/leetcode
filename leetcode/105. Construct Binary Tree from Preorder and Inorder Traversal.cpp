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
		for (i = ileft; i <= iright; ++i) // ���������ҵ����ڵ��λ�ã������Ρ����������к��������зֳ������������ֱ𹹽�����������//i��ileft������0��ʼ
		{
			if (preorder[pleft] == inorder[i])
			{
				break;
			}
		}
		TreeNode* cur = new TreeNode(preorder[pleft]);//��һ�в�����if (pleft>pright || ileft>iright)���棬����pleft�п���Խ��
		cur->left = build(preorder, pleft + 1, pleft + i - ileft, inorder, ileft, i - 1);//pleft+i-ileft��pleft��ʼ�����ұ��Ǽ���i-ileft
	/*����preorder = {7,10,4,3,1,2,8,11},inorder = {4,10,3,1,7,11,8,2}��
	pleft��preorder�е�2��i��inorder��2����λ�ã�ileft��inorder��11����λ�ã������2��pleft+2����preorder�е�11*/
		cur->right = build(preorder, pleft + i - ileft + 1, pright, inorder, i + 1, iright);
		return cur;
	}
};