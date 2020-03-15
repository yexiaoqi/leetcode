//https://www.nowcoder.com/questionTerminal/5ae5174f17674e458028ce12bc8bfe0b 在线测试
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	vector<int> Findpostorder(vector<int> preorder, vector<int> inorder,
		int pleft, int pright, int ileft, int iright)
	{
		vector<int> postorder;
		Findpostorder2(preorder, inorder, pleft, pright, ileft, iright, postorder);
		return postorder;
	}
	void Findpostorder2(vector<int> preorder, vector<int> inorder,
		int pleft, int pright, int ileft, int iright, vector<int> &postorder)
	{
		if (ileft > iright || pleft>pright)
		{
			return;
		}
		int i = ileft;
		for (; i <= iright; ++i)
		{
			if (inorder[i] == preorder[pleft])
			{
				break;
			}
		}
		Findpostorder2(preorder, inorder, pleft + 1, pleft + i - ileft, ileft, i - 1, postorder);  //递归处理左子树
		Findpostorder2(preorder, inorder, pleft + i - ileft + 1, pright, i + 1, iright, postorder);  //递归处理右子树
		postorder.insert(postorder.begin(), inorder[i]);//注意insert用法
	}
};
int main()
{
	int n;
	cin >> n;
	vector<int> preorder(n, 0), inorder(n, 0);
	for (int j = 0; j<n; ++j)
	{
		cin >> preorder[j];
	}
	for (int j = 0; j<n; ++j)
	{
		cin >> inorder[j];
	}
	Solution s;
	vector<int> postorder = s.Findpostorder(preorder, inorder, 0, n - 1, 0, n - 1);
	return 0;
}









//打印形式
class Solution
{
public:
	void Findpostorder(vector<int> preorder, vector<int> inorder,
		int pleft, int pright, int ileft, int iright)
	{
		if (ileft > iright || pleft>pright)
		{
			return;
		}
		int i = ileft;
		for (; i <= iright; ++i)
		{
			if (inorder[i] == preorder[pleft])
			{
				break;
			}
		}
		Findpostorder(preorder, inorder, pleft + 1, pleft + i - ileft, ileft, i - 1);  //递归处理左子树
		Findpostorder(preorder, inorder, pleft + i - ileft + 1, pright, i + 1, iright);  //递归处理右子树
		cout << inorder[i] << " ";
	}
};
int main()
{
	int n;
	cin >> n;
	vector<int> preorder(n, 0), inorder(n, 0);
	for (int j = 0; j<n; ++j)
	{
		cin >> preorder[j];
	}
	for (int j = 0; j<n; ++j)
	{
		cin >> inorder[j];
	}
	Solution s;
	s.Findpostorder(preorder, inorder, 0, n - 1, 0, n - 1);
	return 0;
}