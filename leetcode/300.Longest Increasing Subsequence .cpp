//����һ��o(n^2)�ⷨ
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

//o(nlogn)�ⷨ
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
			while (left<right)//����ÿһ�������������֣��ö��ֲ��ҷ��� dp �����ҵ�һ����С����������
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
			if (right == dp.size())//���right�������������ô˵��������ֲ����ڣ���ôֱ���� dp ���������ϱ�����������
			{
				dp.push_back(nums[i]);
			}
			else
			{
				dp[right] = nums[i];//������ڣ���������ָ���Ϊ��ǰ������������
			}
		}
		return dp.size();
	}
};