//交换错误节点的值， O(n) 空间复杂度
class Solution {
public:
	void recoverTree(TreeNode* root) {
		TreeNode *pre = NULL, *first = NULL, *second = NULL;
		FindNode(root, pre, first, second);
		swap(first->val, second->val);
	}
	void FindNode(TreeNode* root, TreeNode* &pre, TreeNode* &first, TreeNode* &second)
	{
		if (!root)
		{
			return;
		}
		FindNode(root->left, pre, first, second);
		if (!pre)
		{
			pre = root;
		}
		else
		{
			if (pre->val>root->val)
			{
				if (!first)
				{
					first = pre;
				}
				second = root;
			}
			pre = root;
		}
		FindNode(root->right, pre, first, second);
	}
};