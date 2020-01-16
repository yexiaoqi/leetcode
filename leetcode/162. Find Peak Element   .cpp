//自己写的o（n）解法，不够快
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		if (nums.size() == 1)
		{
			return 0;
		}
		if (nums.size() == 2)
		{
			nums[0]>nums[1] ? 0 : 1;//注意返回的是索引
		}
		if (nums[0]>nums[1])
		{
			return 0;
		}
		for (int i = 0; i<nums.size() - 2; ++i)
		{
			int one = nums[i];
			int two = nums[i + 1];
			int three = nums[i + 2];
			if (two>one&&two>three)
			{
				return i + 1;
			}
		}
		if (nums[nums.size() - 2]<nums[nums.size() - 1])
		{
			return nums.size() - 1;
		}
		return -1;
	}
};

//o（n）解法，简化版
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		for (int i = 1; i<nums.size(); ++i)
		{
			if (nums[i]<nums[i - 1])
			{
				return i - 1;
			}
		}
		return nums.size() - 1;
	}
};

//o(logn)
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int left = 0, right = nums.size() - 1;
		while (left<right)
		{
			int mid = (left + right) / 2;//由于left小于right，所以必有nums[mid+1]
			if (nums[mid]<nums[mid + 1])
			{
				left = mid + 1;
			}
			else//此时也是nums[mid]>nums[mid+1]的时候，此时mid就是所求值，在下面right=mid，那么return right
			{
				right = mid;
			}
		}
		return right;
	}
};