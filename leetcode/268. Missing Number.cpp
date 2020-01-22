//由于不是排序好的数组，无法使用剑指offer53_02中的二分查找方法，只能用书上说的第一种方法
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		int allsum = n*(n + 1) / 2;
		int sum = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			sum += nums[i];
		}
		int res = allsum - sum;
		return res;
	}
};