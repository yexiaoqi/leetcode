//操作给定的二叉树，将其变换为源二叉树的镜像。

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/

//自己做出，一遍AC
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (!pRoot)
		{
			return;
		}
		TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
		/*if (pRoot->left)
		{
			Mirror(pRoot->left);
		}
		if (pRoot->right)
		{
			Mirror(pRoot->right);
		}*/
	}

};

//复习
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (!pRoot)
		{
			return;
		}
		TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};