//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* last = NULL;
		ConvertNode(pRootOfTree, last);
		while (last&&last->left)//注意要先判断last，否则万一pRootOfTree为空直接last->left会出错
		{
			last = last->left;
		}
		return last;
	}
	void ConvertNode(TreeNode* root, TreeNode* &last)
	{
		if (!root)
		{
			return;
		}
		ConvertNode(root->left, last);
		root->left = last;
		if (last)
		{
			last->right = root;
		}
		last = root;
		ConvertNode(root->right, last);
	}
};