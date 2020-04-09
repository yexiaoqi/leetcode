//������ָ��4_14һ��

//˼·��
//dp[i][j]��ʾ��nums[i]��nums[j]���ֱ���һλ��Ҷ������������󷵻�dp[0][nums.length - 1]�Ƿ����0����
//
//����dp[i][j]�������������nums[i]������һλ��ұ����ֶ�dp[i + 1][j]��dp[i][j] = nums[i] - dp[i + 1][j]�������������nums[j]������һλ��ұ����ֶ�dp[i][j - 1]��dp[i][j] = nums[j] - dp[i][j - 1]
//���ϣ�dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
//��i = jʱ������һ��Ӯ������һλ��Ҷ�dp[i][j] = nums[i]
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





//����dp����Ľⷨ
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
				f[i][j] = max(arr[i] + s[i + 1][j], arr[j] + s[i][j - 1]);//��Ϊ f[i][j]����s[i+1][j]��������i���뵹������Ϊ������[j-1]������j��������
				s[i][j] = min(f[i + 1][j], f[i][j - 1]);
			}
		}
		//return max(f[0][n-1],s[0][n-1]);
		return f[0][n - 1] >= s[0][n - 1] ? true : false;//ע�����
	}
};


//�����ⷨ��ע�ⲻ��&�ᳬʱ
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
	int f(vector<int> &arr, int i, int j)//�����ⷨ��ע�ⲻ��&�ᳬʱ
	{
		if (i == j)
		{
			return arr[i];
		}
		return max(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));
	}
	int s(vector<int> &arr, int i, int j)//�����ⷨ��ע�ⲻ��&�ᳬʱ
	{
		if (i == j)
		{
			return arr[i];
		}
		return min(f(arr, i + 1, j), f(arr, i, j - 1));
	}
};


//�����ⷨ��ϰ
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