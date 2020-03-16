//基本和指南4_14一样
class Solution {
public:
	bool PredictTheWinner(vector<int>& arr) {
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
				f[i][j] = max(arr[i] + s[i + 1][j], arr[j] + s[i][j - 1]);//因为 f[i][j]依赖s[i+1][j]，，所以i必须倒序，又因为它依赖[j-1]，所以j必须正序
				s[i][j] = min(f[i + 1][j], f[i][j - 1]);
			}
		}
		//return max(f[0][n-1],s[0][n-1]);
		return f[0][n - 1] >= s[0][n - 1] ? true : false;//注意等于
	}
};


//暴力解法会超时
class Solution {
public:
	bool PredictTheWinner(vector<int>& arr) {
		if (arr.empty())
		{
			return 0;
		}
		int n = arr.size();
		return f(arr, 0, n - 1) >= s(arr, 0, n - 1) ? true : false;
	}
	int f(vector<int> arr, int i, int j)
	{
		if (i == j)
		{
			return arr[i];
		}
		return max(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));
	}
	int s(vector<int> arr, int i, int j)
	{
		if (i == j)
		{
			return arr[i];
		}
		return min(f(arr, i + 1, j), f(arr, i, j - 1));
	}
};