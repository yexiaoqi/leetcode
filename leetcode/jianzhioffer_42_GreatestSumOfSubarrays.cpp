//自己做出了
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> num) {
        if(num.size()==0)
        {
            return 0;
        }
        int sum=num[0];
        vector<int> dp(num.size(),0);
        dp[0]=num[0];
        for(int i=1;i<num.size();++i)
        {
            dp[i]=max(dp[i-1]+num[i],num[i]);
            if(sum<dp[i])
            {
                sum=dp[i];
            }
        }
        return sum;
    }
};


//复习，一遍ac，简单
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> nums) {
		vector<int> dp(nums.size(), 0);
		if (nums.empty())
		{
			return -1;
		}
		dp[0] = nums[0];
		int res = dp[0];
		for (int i = 1; i<nums.size(); ++i)
		{
			dp[i] = max(nums[i], nums[i] + dp[i - 1]);
			if (res<dp[i])
			{
				res = dp[i];
			}
		}
		return res;
	}
};