//题目： 将一个数组分成两部分，不要求两部分所包含的元素个数相等，要求使得这两个部分的和的差值最小。比如对于数组{ 1,0,1,7,2,4 }，可以分成{ 1,0,1,2,4 }和{ 7 }，使得这两部分的差值最小。
//
//思路：差最小就是说两部分的和最接近，而且和所有数的和SUM的一半也是最接近的。假设用sum1表示第一部分的和，sum2表示第二部分的和，SUM表示所有数的和，那么sum1 + sum2 = SUM。假设sum1<sum2 那么SUM / 2 - sum1 = sum2 - SUM / 2;
//所以我们就有目标了，使得sum1 <= SUM / 2的条件下尽可能的大。也就是说从n个数中选出某些数，使得这些数的和尽可能的接近或者等于所有数的和的一半。这其实就是简单的背包问题了： 
//背包容量是SUM / 2. 每个物体的体积是数的大小，然后尽可能的装满背包。 
//dp方程：f[i][V] = max(f[i - 1][V - v[i]] + v[i], f[i - 1][V])
//f[i][V]表示用前i个物体装容量为V的背包能够装下的最大值，f[i - 1][V - v[i]] + v[i]表示第i个物体装进背包的情况，f[i - 1][V]表示第i件物品不装进背包的情况。 

class Solution
{
public:
	int FindMindiff(vector<int> nums)
	{
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += nums[i];
		}
		int halfsum = sum / 2;
		vector<int> dp(halfsum + 1, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = halfsum; j >= nums[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		return sum - 2 * dp.back();
	}
};
int main()
{
	Solution s;
	vector<int> nums = { 1,0,1,7,2,4 };
	int res = s.FindMindiff(nums);
	cout << res;
	return 0;
}




//得到分割的数放入halfnum，也即背包问题找到具体的物品

class Solution
{
public:
	int FindMindiff(vector<int> nums)
	{
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += nums[i];
		}
		int halfsum = sum / 2;
		vector<int> dp(halfsum + 1, 0);
		vector<int> halfnum;
		nums.insert(nums.begin(), -1);//在前面加一个不用的数字，否则后面对应关系太乱了
		vector<vector<pair<int, int>>> pos(n + 1, vector<pair<int, int>>(halfsum + 1, pair<int, int>()));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= halfsum; ++j)
			{
				pos[i][j] = make_pair(i - 1, j);
			}//比如数组是1,0,1,9,2,4，碰到9的时候进不了下面的循环，所以pos[i][j] = make_pair(i - 1, j);得在上面就定好
			for (int j = halfsum; j >= nums[i]; --j)
			{
				if (dp[j] < dp[j - nums[i]] + nums[i])
				{
					pos[i][j] = make_pair(i - 1, j - nums[i]);
				}
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);//因为选择 dp[j - nums[i]] + nums[i]说明新放入物品nums[i]，所以下面当pos[i][j].first == i - 1 && pos[i][j].second == j - nums[i]的时候能逐渐找到所有放入的物品
			}
		}
		int i = n, j = dp.back();
		//从后往前找
		while (!(i == 0 && j == 0))
		{
			if (pos[i][j].first == i - 1 && pos[i][j].second == j - nums[i])
			{
				halfnum.push_back(nums[i]);
			}
			int tmp = pos[i][j].first;
			j = pos[i][j].second;
			i = tmp;
		}

		return sum - 2 * dp.back();
	}
};
int main()
{
	Solution s;
	vector<int> nums = { 1,0,1,9,2,4 };
	int res = s.FindMindiff(nums);
	cout << res;
	return 0;
}