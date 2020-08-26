//第一种print
//自己的方法，层序遍历，得到左边界i == 0，右边界i == n - 1和叶子节点!tmp->left && !tmp->right，
//然后按照左边界，叶子节点，右边界（倒过来），的顺序打印
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
vector<int> reverseprint1(TreeNode *root)
{
	vector<int> left;
	vector<int> right;
	vector<int> leaf;
	vector<int> res;
	if (!root)
	{
		return vector<int>();
	}
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int n = q.size();
		for (int i = 0; i < n; ++i)
		{
			TreeNode *tmp = q.front();
			q.pop();
			if (i == 0)
			{
				left.push_back(tmp->val);
			}
			else if (i == n - 1)
			{
				right.push_back(tmp->val);
			}
			else if (!tmp->left && !tmp->right)
			{
				leaf.push_back(tmp->val);
			}
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
	/*if (root->left || root->right)
	{
	res.push_back(root->val);
	}*/
	res.insert(res.end(), left.begin(), left.end());
	res.insert(res.end(), leaf.begin(), leaf.end());
	res.insert(res.end(), right.rbegin(), right.rend());
	return res;
}


int main()
{
	TreeNode a1(1);
	TreeNode a2(2);
	TreeNode a3(3);
	TreeNode a4(4);
	TreeNode a5(5);
	TreeNode a6(6);
	TreeNode a7(7);
	TreeNode a8(8);
	TreeNode a9(9);
	TreeNode a10(10);
	TreeNode a11(11);
	TreeNode a12(12);
	TreeNode a13(13);
	TreeNode a14(14);
	TreeNode a15(15);
	TreeNode a16(16);
	a1.left = &a2;
	a1.right = &a3;
	a2.right = &a4;
	a3.left = &a5;
	a3.right = &a6;
	a4.left = &a7;
	a4.right = &a8;
	a5.left = &a9;
	a5.right = &a10;
	a8.right = &a11;
	a9.left = &a12;
	a11.left = &a13;
	a11.right = &a14;
	a12.left = &a15;
	a12.right = &a16;
	vector<int> res = reverseprint1(&a1);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	return 0;
}



//第二种print方法同leetcode545
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
void Findleaf(TreeNode* root, vector<int> &res)
{
	if (!root)
	{
		return;
	}
	if (!root->left && !root->right)
	{
		res.push_back(root->val);
	}
	Findleaf(root->left, res);
	Findleaf(root->right, res);
}
void Findleftboundary(TreeNode* root, vector<int> &res)
{
	if (!root || (!root->left && !root->right))
	{
		return;
	}
	res.push_back(root->val);
	if (root->left)
	{
		Findleftboundary(root->left, res);
	}
	else
	{
		Findleftboundary(root->right, res);
	}
}
void Findrightboundary(TreeNode* root, vector<int> &res)
{
	if (!root || (!root->left && !root->right))
	{
		return;
	}
	if (root->right)
	{
		Findrightboundary(root->right, res);
	}
	else
	{
		Findrightboundary(root->left, res);
	}
	res.push_back(root->val);
}
vector<int> reverseprint2(TreeNode* root)
{
	if (!root)
	{
		return vector<int>();
	}
	vector<int> res;
	if (root->left || root->right)
	{
		res.push_back(root->val);
	}
	Findleftboundary(root->left, res);
	Findleaf(root, res);
	Findrightboundary(root->right, res);
	return res;
}
//TreeNode* ConstructTree(vector<vector<int>> nums, int i, TreeNode* root)
//{
//	if (i>nums.size())
//	{
//		return root;
//	}
//	if (nums[i][1] != 0)
//	{
//		root->left = new TreeNode(nums[i][1]);
//	}
//}


int main()
{
	TreeNode a1(1);
	TreeNode a2(2);
	TreeNode a3(3);
	TreeNode a4(4);
	TreeNode a5(5);
	TreeNode a6(6);
	TreeNode a7(7);
	TreeNode a8(8);
	TreeNode a9(9);
	TreeNode a10(10);
	TreeNode a11(11);
	TreeNode a12(12);
	TreeNode a13(13);
	TreeNode a14(14);
	TreeNode a15(15);
	TreeNode a16(16);
	a1.left = &a2;
	a1.right = &a3;
	a2.right = &a4;
	a3.left = &a5;
	a3.right = &a6;
	a4.left = &a7;
	a4.right = &a8;
	a5.left = &a9;
	a5.right = &a10;
	a8.right = &a11;
	a9.left = &a12;
	a11.left = &a13;
	a11.right = &a14;
	a12.left = &a15;
	a12.right = &a16;
	vector<int> res = reverseprint1(&a1);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	return 0;
}
//不太清楚从牛客的输入方式怎么建立树
int main()
{
	int rootval, n;
	cin >> n >> rootval;
	TreeNode* root = new TreeNode(rootval);
	TreeNode* tmp = root;
	for (int i = 0; i<n; ++i)
	{
		int fa, lch, rch;
		cin >> fa >> lch >> rch;
		if (lch)
		{
			root->left = new TreeNode(lch);
		}
		if (rch)
		{
			root->right = new TreeNode(rch);
		}
	}
}