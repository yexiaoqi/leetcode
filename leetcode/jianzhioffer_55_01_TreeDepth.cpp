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
	int TreeDepth(TreeNode* pRoot)
	{
		if (!pRoot)
		{
			return 0;
		}
		int nleft = TreeDepth(pRoot->left);
		int nright = TreeDepth(pRoot->right);
		return nleft>nright ? (nleft + 1) : (nright + 1);
	}
};

//¸´Ï°£¬Ò»±éac
class Solution {
public:
	int TreeDepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return 1 + max(TreeDepth(root->left), TreeDepth(root->right));
	}
};