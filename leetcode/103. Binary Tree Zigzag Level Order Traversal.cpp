//同剑指offer 32.3
//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its zigzag level order traversal as :
//[
//	[3],
//	[20, 9],
//	[15, 7]
//]

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution
{
public:
	vector<vector<int>> ret;

	void buildVector(TreeNode *root, int depth)
	{
		if (root == NULL) return;
		if (ret.size() == depth)
			ret.push_back(vector<int>());

		ret[depth].push_back(root->val);
		buildVector(root->left, depth + 1);
		buildVector(root->right, depth + 1);
	}

	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		buildVector(root, 0);
		for (int i = 0;i<ret.size();++i)
		{
			if (i % 2 != 0)
			{
				reverse(ret[i].begin(), ret[i].end());
			}
		}
		return ret;
	}

};


class Solution
{
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		if (!root)
		{
			return{};
		}
		vector<vector<int>> res;
		queue<TreeNode*> q{ { root } };
		int cnt = 0;
		while (!q.empty())
		{
			vector<int> onelevel;
			for (int i = q.size(); i>0; --i)
			{
				TreeNode* t = q.front();
				q.pop();
				onelevel.push_back(t->val);//->val不要忘了！！！
				if (t->left)
				{
					q.push(t->left);
				}
				if (t->right)
				{
					q.push(t->right);
				}
			}
			if (cnt % 2 == 1)
			{
				reverse(onelevel.begin(), onelevel.end());
			}
			cnt += 1;
			res.push_back(onelevel);
		}
		return res;
	}

};

class Solution
{
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		if (!root)
		{
			return{};
		}
		vector<vector<int>> res;
		queue<TreeNode*> q{ { root } };
		// int cnt=0;
		bool reve = true;
		while (!q.empty())
		{
			int size = q.size();
			vector<int> onelevel(size);
			for (int i = size - 1; i >= 0; --i)
			{
				TreeNode* t = q.front();
				q.pop();
				int idx = reve ? (size - 1 - i) : i;
				// int idx = reve ? i : (size - 1 - i);
				//int idx=reve?i:(size-i-1);
				onelevel[idx] = t->val;
				//onelevel.push_back(t->val);//->val不要忘了！！！
				if (t->left)
				{
					q.push(t->left);
				}
				if (t->right)
				{
					q.push(t->right);
				}
			}

			reve = !reve;
			res.push_back(onelevel);
		}
		return res;
	}

};

//复习
//自己做出，一遍ac
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		levels(root, res, 0);
		return res;
	}
	void levels(TreeNode* root, vector<vector<int>> &res, int level)
	{
		if (!root)
		{
			return;
		}
		if (level == res.size())
		{
			res.push_back(vector<int>());
		}
		if (level % 2)
		{
			res[level].insert(res[level].begin(), root->val);
		}
		else
		{
			res[level].push_back(root->val);
		}
		levels(root->left, res, level + 1);
		levels(root->right, res, level + 1);
	}
};


//简单
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		int depth = 0;
		zigzag(root, res, depth);
		for (int i = 0; i<res.size(); ++i)
		{
			if (i & 0x1)
			{
				reverse(res[i].begin(), res[i].end());
			}
		}
		return res;
	}
	void zigzag(TreeNode* root, vector<vector<int>> &res, int depth)
	{
		if (!root)
		{
			return;
		}
		if (res.size() == depth)
		{
			res.push_back(vector<int>());
		}
		res[depth].push_back(root->val);
		zigzag(root->left, res, depth + 1);
		zigzag(root->right, res, depth + 1);
	}
};

//
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		int depth = 0;
		zigzag(root, res, depth);
		for (int i = 0; i<res.size(); ++i)
		{
			if (i & 0x1)
			{
				reverse(res[i].begin(), res[i].end());
			}
		}
		return res;
	}
	void zigzag(TreeNode* root, vector<vector<int>> &res, int depth)
	{
		if (!root)
		{
			return;
		}
		if (res.size() == depth)
		{
			res.push_back(vector<int>());
		}
		res[depth].push_back(root->val);
		zigzag(root->left, res, depth + 1);
		zigzag(root->right, res, depth + 1);
	}
};