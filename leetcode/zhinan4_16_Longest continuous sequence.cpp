//ͬleetcode128
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> us(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			int cnt = 1;
			if (us.count(nums[i]))
			{
				int tmp = nums[i] + 1;
				while (us.count(tmp))
				{
					++cnt;
					us.erase(tmp);
					++tmp;
				}
				tmp = nums[i] - 1;
				while (us.count(tmp))
				{
					++cnt;
					us.erase(tmp);
					--tmp;
				}
			}
			if (res<cnt)
			{
				res = cnt;
			}
		}
		return res;
	}
};