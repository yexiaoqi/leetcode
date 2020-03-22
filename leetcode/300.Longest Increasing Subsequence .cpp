//方法一，o(n^2)解法
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> dp(nums.size(), 1);
		int maxres = 1;
		for (int i = 1; i<nums.size(); ++i)
		{
			for (int j = 0; j<i; ++j)
			{
				if (nums[j]<nums[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if (maxres<dp[i])
			{
				maxres = dp[i];
			}
		}
		return maxres;
	}
};

//o(nlogn)解法
https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
//设当前已求出的最长上升子序列的长度为 \textit{ len }len（初始时为 11），从前往后遍历数组 \textit{ nums }nums，在遍历到 \textit{ nums }[i]nums[i] 时：
//
//如果 \textit{ nums }[i] > d[\textit{ len }]nums[i]>d[len] ，则直接加入到 dd 数组末尾，并更新 \textit{ len } = \textit{ len } +1len = len + 1；
//
//否则，在 dd 数组中二分查找，找到第一个比 \textit{ nums }[i]nums[i] 小的数 d[k]d[k] ，并更新 d[k + 1] = \textit{ nums }[i]d[k + 1] = nums[i]。
//
//以输入序列[0, 8, 4, 12, 2][0, 8, 4, 12, 2] 为例：
//
//第一步插入 00，d = [0]d = [0]；
//
//第二步插入 88，d = [0, 8]d = [0, 8]；
//
//第三步插入 44，d = [0, 4]d = [0, 4]；
//
//第四步插入 1212，d = [0, 4, 12]d = [0, 4, 12]；
//
//第五步插入 22，d = [0, 2, 12]d = [0, 2, 12]。
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> dp;
		for (int i = 0; i<nums.size(); ++i)
		{
			int left = 0, right = dp.size();
			while (left<right)//对于每一个遍历到的数字，用二分查找法在 dp 数组找第一个不小于它的数字
			{
				int mid = (left + right) / 2;
				if (dp[mid]<nums[i])
				{
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
			}
			if (right == dp.size())//如果right遍历到了最后，那么说明这个数字不存在，那么直接在 dp 数组后面加上遍历到的数字
			{
				dp.push_back(nums[i]);
			}
			else
			{
				dp[right] = nums[i];//如果存在，则将这个数字更新为当前遍历到的数字
			}
		}
		return dp.size();
	}
};


//用lower_bound代替自己写二分
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> dp;
		for (int i = 0; i<nums.size(); ++i)
		{
			int right = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
			if (right == dp.size())//如果right遍历到了最后，那么说明这个数字不存在，那么直接在 dp 数组后面加上遍历到的数字
			{
				dp.push_back(nums[i]);
			}
			else
			{
				dp[right] = nums[i];//如果存在，则将这个数字更新为当前遍历到的数字
			}
		}
		return dp.size();
	}
};