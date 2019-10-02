//Given a binary tree, return the bottom - up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its bottom - up level order traversal as :
//[
//	[15, 7],
//	[9, 20],
//	[3]
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
class Solution {
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

	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		buildVector(root, 0);
		reverse(ret.begin(), ret.end());
		return ret;
	}
};


class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		if (!root)
		{
			return{};
		}
		vector<vector<int>> res;
		queue<TreeNode*> q{ { root } };
		while (!q.empty())
		{
			vector<int> onelevel;

			for (int i = q.size(); i>0; --i)
			{
				TreeNode* t = q.front();
				q.pop();
				onelevel.push_back(t->val);
				if (t->left)
				{
					q.push(t->left);
				}
				if (t->right)
				{
					q.push(t->right);
				}
			}

			res.insert(res.begin(), onelevel);//使用insert而不是push_back
		}
		return res;
	}
};


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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int>> res;
		order(root, 0, res);
		//return res;
		return vector<vector<int>>(res.rbegin(), res.rend());//c.rbegin() 返回一个逆序迭代器，它指向容器c的最后一个元素

															 //c.rend() 返回一个逆序迭代器，它指向容器c的第一个元素前面的位置
	}
	void order(TreeNode* node, int level, vector<vector<int>> &res)//传引用，谢谢！！
	{
		if (!node)
		{
			return;
		}
		if (res.size() == level)
		{
			//res.insert(res.begin(),{});//c.begin() 返回一个迭代器，它指向容器c的第一个元素,这样如果没有第一个元素的时候就会指向空指针报错
			res.push_back({});
		}
		res[level].push_back(node->val);
		if (node->left)
		{
			order(node->left, level + 1, res);
		}
		if (node->right)
		{
			order(node->right, level + 1, res);
		}
	}
};