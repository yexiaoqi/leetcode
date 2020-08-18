//Í¬leetcode98£¬958
//98
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValid(root, LONG_MIN, LONG_MAX);
	}
	bool isValid(TreeNode* root, long mn, long mx)
	{
		if (!root)
		{
			return true;
		}
		if (root->val <= mn || root->val >= mx)
		{
			return false;
		}
		return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
	}
};
//958
class Solution {
public:
	bool isCompleteTree(TreeNode* root) {
		bool judge = true;
		if (!root)
		{
			return true;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* tmp = q.front();
			q.pop();
			if (tmp->left)
			{
				if (judge == false)
				{
					return false;
				}
				q.push(tmp->left);
			}
			else
			{
				judge = false;
			}
			if (tmp->right)
			{
				if (judge == false)
				{
					return false;
				}
				q.push(tmp->right);
			}
			else
			{
				judge = false;
			}
		}
		return true;
	}
};