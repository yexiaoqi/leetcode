//基本和指南4_14一样

//思路：
//dp[i][j]表示从nums[i]到nums[j]先手比另一位玩家多的最大分数，最后返回dp[0][nums.length - 1]是否大于0即可
//
//对于dp[i][j]，如果先手拿了nums[i]，则另一位玩家比先手多dp[i + 1][j]，dp[i][j] = nums[i] - dp[i + 1][j]，如果先手拿了nums[j]，则另一位玩家比先手多dp[i][j - 1]，dp[i][j] = nums[j] - dp[i][j - 1]
//综上，dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
//当i = j时，先手一定赢，比另一位玩家多dp[i][j] = nums[i]
class Solution {
public:
	bool PredictTheWinner(vector<int>& arr) {
		//dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1])
		//if dp[0][n-1]>=0,win
		int n = arr.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = 0; i<n; ++i)
		{
			dp[i][i] = arr[i];
		}
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i + 1; j<n; ++j)
			{
				dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
			}
		}
		return dp[0][n - 1] >= 0;
	}
};





//两个dp数组的解法
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


//暴力解法，注意不加&会超时
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
	int f(vector<int> &arr, int i, int j)//暴力解法，注意不加&会超时
	{
		if (i == j)
		{
			return arr[i];
		}
		return max(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));
	}
	int s(vector<int> &arr, int i, int j)//暴力解法，注意不加&会超时
	{
		if (i == j)
		{
			return arr[i];
		}
		return min(f(arr, i + 1, j), f(arr, i, j - 1));
	}
};


//暴力解法复习
class Solution {
public:
	int first(vector<int>& nums, int i, int j)
	{
		if (i == j)
		{
			return nums[i];
		}
		return max(nums[i] + second(nums, i + 1, j), nums[j] + second(nums, i, j - 1));
	}
	int second(vector<int>&nums, int i, int j)
	{
		if (i == j)
		{
			return 0;
		}
		return min(first(nums, i + 1, j), first(nums, i, j - 1));
	}
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		int i = 0, j = n - 1;
		if (first(nums, 0, n - 1) >= second(nums, 0, n - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};