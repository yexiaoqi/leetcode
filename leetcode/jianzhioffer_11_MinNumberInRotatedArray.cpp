//找最大数字，京东二面
class Solution
{
public:
	int MaxNumber(vector<int> nums)
	{
		if (nums.empty())
		{
			return 0;
		}
		int begin = 0, end = nums.size() - 1;
		int res = INT_MIN;
		while (begin <= end)
		{
			int mid = begin + (end - begin) / 2;
			if (nums[mid] <= nums[end])
			{
				if (res<nums[end])
				{
					res = nums[end];
				}
				if (nums[mid] == nums[end])
				{
					for (int i = mid + 1; i <= end; ++i)
						//					{
						//						if (res<nums[i])
						//						{
						//							res = nums[i];
						//						}
						//					}
					--end;//这一句代替上面的
				}
				end = mid - 1;
			}
			else
			{
				if (res<nums[mid])
				{
					res = nums[mid];
				}
				begin = mid + 1;
			}
		}
		return res;
	}
};










//牛客上可能用例不全，下面的如果碰上2,2,2,2,3这种有重复数字的不一定对
class Solution {
public:
	int minNumberInRotateArray(vector<int> nums) {
		if (int(nums.size() == 0))
		{
			return 0;
		}
		int begin = 0, end = int(nums.size()) - 1;
		int minnum = INT_MAX;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid]<minnum)
			{
				minnum = nums[mid];
			}
			if (nums[mid] <= nums[end])
			{
				end = mid - 1;
			}
			else
			{
				minnum = nums[begin];
				begin = mid + 1;
			}
		}
		return minnum;
	}
};

//复习，自己做出
class Solution {
public:
	int minNumberInRotateArray(vector<int> nums) {
		if (nums.empty())
		{
			return 0;
		}
		int begin = 0, end = nums.size() - 1;
		int res = INT_MAX;
		findnum(nums, begin, end, res);
		return res;
	}
	void findnum(vector<int> &nums, int begin, int end, int &res)
	{
		while (begin >= 0 && end<nums.size() && begin <= end)//注意要有=，begin <= end其实已经包含了begin >= 0 && end<nums.size()
		{
			int mid = begin + (end - begin) / 2;
			if (nums[mid] <= nums[end])
			{
				if (res>nums[mid])
				{
					res = nums[mid];
				}
				end = mid - 1;
				findnum(nums, begin, end, res);
			}
			else
			{
				if (res>nums[begin])
				{
					res = nums[begin];
				}
				begin = mid + 1;
				findnum(nums, begin, end, res);
			}
		}
		return;
	}
};

//简化
class Solution {
public:
	int minNumberInRotateArray(vector<int> nums) {
		if (nums.empty())
		{
			return 0;
		}
		int begin = 0, end = nums.size() - 1;
		int res = INT_MAX;
		while (begin <= end)//注意要有=
		{
			int mid = begin + (end - begin) / 2;
			if (nums[mid] <= nums[end])
			{
				if (res>nums[mid])
				{
					res = nums[mid];
				}
				end = mid - 1;
			}
			else
			{
				if (res>nums[begin])
				{
					res = nums[begin];
				}
				begin = mid + 1;
			}
		}
		return res;
	}
};