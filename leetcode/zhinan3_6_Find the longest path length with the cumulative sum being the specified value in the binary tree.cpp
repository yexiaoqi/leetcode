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




int Preorder(TreeNode* root, int sum, int presum, int &maxlen, int level, unordered_map<int, int> &m)
{
	if (!root)
	{
		return maxlen;
	}
	int cursum = presum + root->val;
	if (m.count(cursum - sum))
	{
		int len = level - m[cursum - sum];
		if (maxlen < len)
		{
			maxlen = len;
		}
	}
	if (!m.count(cursum))
	{
		m[cursum] = level;
	}
	Preorder(root->left, sum, cursum, maxlen, level + 1, m);
	Preorder(root->right, sum, cursum, maxlen, level + 1, m);
	if (level == m[cursum])
	{
		m.erase(cursum);
	}
	return maxlen;
}


int GetMaxLen(TreeNode* root, int sum)
{
	unordered_map<int, int> m;
	m[0] = 0;
	int maxlen = 0;
	return Preorder(root, sum, 0, maxlen, 1, m);
}
int main()
{
	TreeNode a1(-3);
	TreeNode a2(3);
	TreeNode a3(-9);
	TreeNode a4(1);
	TreeNode a5(0);
	TreeNode a6(2);
	TreeNode a7(1);
	TreeNode a8(1);
	TreeNode a9(6);
	a1.left = &a2;
	a1.right = &a3;
	a2.left = &a4;
	a2.right = &a5;
	a3.left = &a6;
	a3.right = &a7;
	a5.left = &a8;
	a5.right = &a9;
	cout << GetMaxLen(&a1, -9);
	return 0;
}