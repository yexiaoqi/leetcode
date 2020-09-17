class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size()<2)
		{
			return 0;
		}
		int mx = INT_MIN, mn = INT_MAX;
		for (int i = 0; i<nums.size(); ++i)
		{
			mx = max(mx, nums[i]);
			mn = min(mn, nums[i]);
		}
		int n = nums.size();
		int tmp = ceil((mx - mn) / n);
		int bucketsize = max(1, tmp);
		int bucketcount = (mx - mn) / bucketsize + 1;
		vector<int> bucket_min(bucketcount, INT_MAX);
		vector<int> bucket_max(bucketcount, INT_MIN);
		for (int i = 0; i<nums.size(); ++i)
		{
			int index = (nums[i] - mn) / bucketsize;
			bucket_min[index] = min(bucket_min[index], nums[i]);
			bucket_max[index] = max(bucket_max[index], nums[i]);
		}
		int pre = 0, res = 0;
		for (int i = 1; i<bucketcount; ++i)
		{
			if (bucket_max[i] == INT_MIN || bucket_min[i] == INT_MAX)
			{
				continue;
			}
			res = max(res, bucket_min[i] - bucket_max[pre]);
			pre = i;
		}
		return res;
	}
};