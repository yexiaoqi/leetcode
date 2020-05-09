//ͬleetcode45
class Solution {
public:
	int jump(vector<int>& nums) {
		int maxpos = 0;
		int step = 0;
		int end = 0;
		int n = nums.size();
		for (int i = 0; i<n; ++i)
		{
			maxpos = max(maxpos, nums[i] + i);
			if (i == end)
			{
				if (i == n - 1)
				{
					return step;
				}
				end = maxpos;
				++step;
			}
		}
		return step;
	}
};