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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		queue<pair<TreeNode*, int>> q;
		if (root)
		{
			q.push(make_pair(root, 0));
		}
		while (!q.empty())
		{
			TreeNode* node = q.front().first;
			int depth = q.front().second;
			q.pop();
			if (depth == res.size())
			{
				res.push_back(node->val);
			}
			else
			{
				res[depth] = node->val;
			}
			if (node->left)
			{
				q.push(make_pair(node->left, depth + 1));
			}
			if (node->right)
			{
				q.push(make_pair(node->right, depth + 1));
			}
		}
		return res;
	}

};



//自己写的，先push右边的，这一行第一个push进入res
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (!root)
		{
			return res;
		}
		queue<pair<TreeNode*, int>> q;
		q.push(make_pair(root, 0));
		int visit = 0;
		while (!q.empty())
		{
			TreeNode* node = q.front().first;
			int depth = q.front().second;
			if (depth == visit)
			{
				res.push_back(node->val);
				++visit;
			}

			q.pop();
			if (node->right)
			{
				q.push(make_pair(node->right, depth + 1));
			}
			if (node->left)
			{
				q.push(make_pair(node->left, depth + 1));
			}
		}
		return res;
	}
};