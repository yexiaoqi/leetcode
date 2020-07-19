//ͬleetcode128
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		unordered_set<int> us;
		for (int i = 0; i<nums.size(); ++i)
		{
			us.insert(nums[i]);
		}
		int maxlen = 1;
		for (int i = 0; i<nums.size(); ++i)
		{
			int tmp = nums[i];
			int len = 1;
			while (us.count(tmp + 1))
			{
				++len;
				tmp += 1;
				us.erase(tmp);
			}
			tmp = nums[i];
			while (us.count(tmp - 1))
			{
				++len;
				tmp -= 1;
				us.erase(tmp);
			}
			if (maxlen<len)
			{
				maxlen = len;
			}
		}
		return maxlen;
	}
};