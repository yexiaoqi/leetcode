//同leetcode222
//O(n)解法
class Solution {
public:
	int countNodes(TreeNode* root) {
		queue<TreeNode*> q;
		if (!root)
		{
			return 0;
		}
		q.push(root);
		int res = 0;
		while (!q.empty())
		{
			int n = q.size();
			for (int i = 0; i<n; ++i)
			{
				TreeNode* tmp = q.front();
				q.pop();
				++res;
				if (tmp->left)
				{
					q.push(tmp->left);
				}
				if (tmp->right)
				{
					q.push(tmp->right);
				}
			}
		}
		return res;
	}
};

//O(n)解法2,空间复杂度O（logn），运行过程中堆栈所使用的空间。
class Solution {
public:
	int countNodes(TreeNode* root) {
		return root ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
	}
};



//O(h^2)解法，h是树的高度，
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		int h = GetHeight(root);
		if (GetHeight(root->right) == h - 1)
		{
			return (1 << h) + countNodes(root->right);//注意加()，<<优先级低
		}
		else
		{
			return (1 << (h - 1)) + countNodes(root->left);//注意加()，<<优先级低
		}
	}
	int GetHeight(TreeNode* root)
	{
		return root ? (1 + GetHeight(root->left)) : -1;
	}
};