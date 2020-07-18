/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
		{
			return{};
		}
		return generateTrees(1, n);
	}
	vector<TreeNode*> generateTrees(int begin, int end)
	{
		if (begin>end)
		{
			return{ NULL };
		}
		vector<TreeNode*> res;
		for (int i = begin; i <= end; ++i)
		{
			auto left = generateTrees(begin, i - 1);
			auto right = generateTrees(i + 1, end);
			for (auto a : left)
			{
				for (auto b : right)
				{
					TreeNode* node = new TreeNode(i);
					node->left = a;
					node->right = b;
					res.push_back(node);
				}
			}
		}
		return res;
	}
};