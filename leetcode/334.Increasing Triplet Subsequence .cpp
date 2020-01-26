class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int m1 = INT_MAX, m2 = INT_MAX;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (m1 >= nums[i])//Ϊ�˷�ֹm2����Ϊ��m1һ����ֵ��һ��Ҫ��=
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