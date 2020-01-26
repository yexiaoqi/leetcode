class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int m1 = INT_MAX, m2 = INT_MAX;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (m1 >= nums[i])//为了防止m2更新为和m1一样的值，一定要有=
			{
				m1 = nums[i];
			}
			else if (m2 >= nums[i])
			{
				m2 = nums[i];
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};