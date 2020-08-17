//Í¬½£Ö¸offer26
class Solution {
public:
	bool isSubStructure(TreeNode* a, TreeNode* b) {
		if (!b)
		{
			return false;
		}
		if (isSub(a, b))
		{
			return true;
		}
		return a && (isSubStructure(a->left, b) || isSubStructure(a->right, b));
	}
	bool isSub(TreeNode* a, TreeNode *b)
	{
		if (!b)
		{
			return true;
		}
		if (!a || (a->val != b->val))
		{
			return false;
		}
		return isSub(a->left, b->left) && isSub(a->right, b->right);
	}
};