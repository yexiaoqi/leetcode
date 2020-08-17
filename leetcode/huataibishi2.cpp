#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include <memory>
#include<time.h>
#include<queue>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<limits.h>
#include<math.h>
using namespace std;

//求二叉树中任意两个节点的距离
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* BuildTree(vector<int> nums, int i)
	{
		if (nums.empty() || nums[i] == -1 || i >= nums.size())
		{
			return NULL;
		}
		TreeNode *root = new TreeNode(nums[i]);
		root->left = BuildTree(nums, 2 * i + 1);
		root->right = BuildTree(nums, 2 * i + 2);
		return root;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//if (!root || p == root || q == root)
		if (!root || p->val == root->val || q->val == root->val)
		{
			return root;
		}
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left&&right)
		{
			return root;
		}
		return left ? left : right;
	}
	int GetDepth(TreeNode* root, TreeNode* tmp, int depth)
	{
		if (!root)
		{
			return -1;
		}
		if (tmp->val == root->val)
		{
			return depth;
		}
		int lev = GetDepth(root->left, tmp, depth + 1);
		if (lev == -1)
		{
			lev = GetDepth(root->right, tmp, depth + 1);
		}
		return lev;
	}
	int GetDistance(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		TreeNode *common = lowestCommonAncestor(root, p, q);
		int depth = 0;
		int dis = GetDepth(root, p, depth) + GetDepth(root, q, depth) - 2 * GetDepth(root, common, depth);
		return dis;
	}
};

int main()
{
	vector<int> nums{ 3,5,1,6,2,0,8,-1,-1,7,4 };
	Solution s;
	TreeNode* root = s.BuildTree(nums, 0);
	TreeNode *p = new TreeNode(4);
	TreeNode *q = new TreeNode(3);
	int result = s.GetDistance(root, p, q);
	cout << result;
	return 0;
}