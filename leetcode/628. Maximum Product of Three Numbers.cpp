//O(nlogn)
class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int n = nums.size();
		if (n<3)
		{
			return -1;
		}
		sort(nums.begin(), nums.end());
		int num1 = nums[n - 3] * nums[n - 2] * nums[n - 1];
		int num2 = nums[0] * nums[1] * nums[n - 1];
		return max(num1, num2);
	}
};


//O(n£©½â·¨
class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int n = nums.size();
		if (n<3)
		{
			return -1;
		}
		int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
		int mn1 = INT_MAX, mn2 = INT_MAX;
		for (int i = 0; i<n; ++i)
		{
			if (nums[i]>mx1)
			{
				mx3 = mx2;
				mx2 = mx1;
				mx1 = nums[i];
			}
			else if (nums[i]>mx2)
			{
				mx3 = mx2;
				mx2 = nums[i];
			}
			else if (nums[i]>mx3)
			{
				mx3 = nums[i];
			}
			if (nums[i]<mn1)
			{
				mn2 = mn1;
				mn1 = nums[i];
			}
			else if (nums[i]<mn2)
			{
				mn2 = nums[i];
			}
		}
		return max(mn2*mn1*mx1, mx1*mx2*mx3);
	}
};