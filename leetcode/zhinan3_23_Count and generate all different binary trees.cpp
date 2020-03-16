#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int Findall(int n)
	{
		int mod = (int)1e9 + 7;
		if (n<2)
		{
			return 1;
		}
		vector<long> res(n + 1, 0);//注意long型
		res[0] = 1;
		for (int i = 1; i<n + 1; ++i)
		{
			for (int j = 1; j<i + 1; ++j)
			{
				res[i] += res[j - 1] * res[i - j];//写成1e9 + 7的话前面必须加int
				res[i] %= mod;
			}
		}
		return res.back();
	}
};
int main()
{
	Solution s;
	int n;
	cin >> n;
	int res = s.Findall(n);
	cout << res;
	return 0;
}




//进阶
class TreeNode
{
public:
	int value;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v) :value(v), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<TreeNode*> generateTrees(int n)
	{
		//vector<TreeNode*> res;
		return generate(1, n);
	}
	vector<TreeNode*> generate(int start, int end)
	{
		vector<TreeNode*> res;
		if (start > end)
		{
			res.push_back(NULL);//必须有这个，否则子节点的时候没有res.push_back(cloneTree(head));
		}
		TreeNode* head = NULL;
		for (int i = start; i < end + 1; i++)
		{
			head = new TreeNode(i);
			vector<TreeNode*> lsub = generate(start, i - 1);
			vector<TreeNode*> rsub = generate(i + 1, end);
			/*for (auto a = left.begin(); a != left.end(); ++a)
			{
				for (auto b = right.begin(); b != right.end(); ++b)
				{
					head->left = *a;
					head->right = *b;
					res.push_back(cloneTree(head));
				}
			}*///auto形式也可
			for (TreeNode* l : lsub)
			{
				for (TreeNode* r : rsub)
				{
					head->left = l;
					head->right = r;
					//res.push_back(head);//不能直接push_back原来的树，会造成交叉，因为第一个push进去以后，第二个push进去的树还是head，它会修改第一个push进去的指针值
					res.push_back(cloneTree(head));
				}
			}
		}
		return res;
	}

	TreeNode* cloneTree(TreeNode* head)
	{
		if (!head)
		{
			return NULL;
		}
		TreeNode* res = new TreeNode(head->value);
		res->left = cloneTree(head->left);
		res->right = cloneTree(head->right);
		return res;
	}
};
int main()
{
	Solution s;
	vector<TreeNode* > res = s.generateTrees(3);
	return 0;
}