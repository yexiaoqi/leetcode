//ͬleetcode101
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot)
		{
			return true;
		}
		return Symmetrical(pRoot->left, pRoot->right);
	}
	bool Symmetrical(TreeNode* left, TreeNode* right)
	{
		if (!left && !right)
		{
			return true;
		}
		if ((left && !right) || (!left&&right) || (left->val != right->val))
		{
			return false;
		}
		return Symmetrical(left->left, right->right) && Symmetrical(left->right, right->left);
	}

};