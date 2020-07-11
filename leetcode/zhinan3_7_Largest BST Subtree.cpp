//ͬleetcode 333
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


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};



class Solution
{
public:
	int GetMaxBST(TreeNode* root)
	{
		vector<int> res = GetMax(root);
		return res[2];
	}
	vector<int> GetMax(TreeNode* root)
	{
		if (!root)
		{
			return vector<int>{INT_MAX, INT_MIN, 0};
		}
		vector<int> left = GetMax(root->left);
		vector<int> right = GetMax(root->right);
		if (root->val > left[1] && root->val < right[0])
		{
			return{ min(root->val,left[0]),max(root->val,right[1]),left[2] + right[2] + 1 };
		}
		else
		{
			return{ INT_MIN,INT_MAX,max(left[2],right[2]) };
		}
	}
};
int main()
{
	TreeNode a1(6);
	TreeNode a2(1);
	TreeNode a3(12);
	TreeNode a4(0);
	TreeNode a5(3);
	TreeNode a6(10);
	TreeNode a7(13);
	TreeNode a8(4);
	TreeNode a9(14);
	TreeNode a10(20);
	TreeNode a11(16);
	TreeNode a12(2);
	TreeNode a13(5);
	TreeNode a14(11);
	TreeNode a15(15);
	a1.left = &a2;
	a1.right = &a3;
	a2.left = &a4;
	a2.right = &a5;
	a3.left = &a6;
	a3.right = &a7;
	a6.left = &a8;
	a6.right = &a9;
	a7.left = &a10;
	a7.right = &a11;
	a8.left = &a12;
	a8.right = &a13;
	a9.left = &a14;
	a9.right = &a15;
	Solution s;
	cout << s.GetMaxBST(&a1);
	return 0;
}