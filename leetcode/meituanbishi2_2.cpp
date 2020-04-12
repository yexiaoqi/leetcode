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
#include<math.h>
#include<limits.h>
using namespace std;


//struct TreeNode
//{
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
//};

int main()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	vector<int> b(n, 0);
	unordered_map<int, int> ma;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		ma[a[i]] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	vector<int> sortb(n, 0);
	for (int i = 0; i < n; ++i)
	{
		sortb[i] = ma[b[i]];
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (sortb[j] < sortb[i])
			{
				++cnt;
				break;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}


//�ұ����ĸ��Ӷȸ��͵ķ���
//�����������˺ͳ���˳���ӳ�䣬Ȼ����ڵ�����ˣ������һ���˿�ʼ��ǰ������min��¼�������ĳ���������ˣ�
//ֻҪ�������������ĳ���˳��������min����֮�󣬾���ʤ����һ���ˣ�������һ
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int mapper[n + 1];
	int t;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		mapper[t] = i;
	}

	int nums[n + 1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nums[i]);
	}

	int cnt = 0;
	int minn = mapper[nums[n]];
	for (int i = n; i>0; i--) {
		if (mapper[nums[i]] > minn) {
			//cout<<nums[i]<<endl;
			cnt++;
		}
		if (mapper[nums[i]]<minn) {
			minn = mapper[nums[i]];
		}
	}

	cout << cnt << endl;

	return 0;
}



