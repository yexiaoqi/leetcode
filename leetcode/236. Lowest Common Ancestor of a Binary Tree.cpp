//同剑指offer68
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path;
		vector<vector<TreeNode*>> res;
		TreeNode* ancestor;
		search(root, p->val, path, res);
		search(root, q->val, path, res);
		int min_len = min(res[0].size(), res[1].size());
		for (int i = 0; i<min_len; ++i)
		{
			if (res[0][i]->val == res[1][i]->val)
			{
				ancestor = res[0][i];
			}
		}
		return ancestor;
	}
	void search(TreeNode* root, int value, vector<TreeNode*> &path, vector<vector<TreeNode*>> &res)
	{
		if (!root)
		{
			return;
		}
		path.push_back(root);
		if (value == root->val)
		{
			res.push_back(path);
			//return;//这边不能加return，否则第二次的path会被第一次影响而不是从0开始
		}
		search(root->left, value, path, res);
		search(root->right, value, path, res);
		path.pop_back();
	}
};


//复习练习重写
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !q || !p)
		{
			return NULL;
		}
		vector<vector<TreeNode*>> rightpath;
		vector<TreeNode*> path;
		FindNode(root, p, path, rightpath);
		FindNode(root, q, path, rightpath);
		TreeNode* res = root;
		//int i=0;
		int size = min(rightpath[0].size(), rightpath[1].size());
		for (int i = 0; i<size; ++i)
		{
			if (rightpath[0][i]->val == rightpath[1][i]->val)
			{
				res = rightpath[0][i];
			}
		}
		// while(path1[i]&&path2[i]&&path1[i]->val==path2[i]->val)//可能没有path1[i],不能这样写
		// {
		//     res=path1[i];
		//     ++i;
		// }
		return res;
	}
	void FindNode(TreeNode* root, TreeNode* node, vector<TreeNode*> &path, vector<vector<TreeNode*>> &rightpath)
	{
		if (!root)
		{
			return;
		}
		path.push_back(root);
		if (root->val == node->val)
		{
			rightpath.push_back(path);
		}
		FindNode(root->left, node, path, rightpath);
		FindNode(root->right, node, path, rightpath);
		path.pop_back();//不是后pop_back()
	}
};

//复习
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path1;
		vector<TreeNode*> path2;
		vector<vector<TreeNode*>> res;
		FindPath(root, p, path1, res);
		FindPath(root, q, path2, res);
		int size1 = res[0].size();
		int size2 = res[1].size();
		int minsize = min(size1, size2);
		TreeNode* resnode = new TreeNode(-1);
		for (int i = 0; i<minsize; ++i)
		{
			if (res[0][i] == res[1][i])
			{
				resnode = res[0][i];
			}
			else
			{
				break;
			}
		}
		return resnode;
	}
	void FindPath(TreeNode* root, TreeNode* node, vector<TreeNode*> &path, vector<vector<TreeNode*>> &res)
	{
		if (!root)
		{
			return;
		}
		path.push_back(root);
		if (root == node)
		{
			res.push_back(path);
			return;
		}
		FindPath(root->left, node, path, res);
		FindPath(root->right, node, path, res);
		path.pop_back();
		//return;
	}//void执行完即可，同230方法二中int kthSmallest(TreeNode* root, int k)比较，230中需要有int返回值所以return kthSmallest(root->right, k - cnt - 1);
};