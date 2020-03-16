#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int win2(vector<int> arr)
	{
		if (arr.empty())
		{
			return 0;
		}
		int n = arr.size();
		vector<vector<int>> f(n, vector<int>(n, 0));
		vector<vector<int>> s(n, vector<int>(n, 0));
		for (int j = 0; j<n; ++j)
		{
			f[j][j] = arr[j];
			for (int i = j - 1; i >= 0; --i)
			{
				f[i][j] = max(arr[i] + s[i + 1][j], arr[j] + s[i][j - 1]);
				s[i][j] = min(f[i + 1][j], f[i][j - 1]);
			}
		}
		return max(f[0][n - 1], s[0][n - 1]);
	}
};
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i<n; ++i)
	{
		cin >> arr[i];
	}
	Solution s;
	cout << s.win2(arr);
	return 0;
}