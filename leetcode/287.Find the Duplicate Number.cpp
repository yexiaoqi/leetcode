//同剑指offer 3_02
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int begin = 1, end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			int cnt = CountTimes(nums, begin, mid);
			if (begin == end)
			{
				if (cnt>1)
				{
					return begin;
				}
				else
				{
					return -1;
				}
			}
			if (cnt>mid - begin + 1)
			{
				end = mid;
			}
			else
			{
				begin = mid + 1;
			}
		}
		return -1;
	}
	int CountTimes(vector<int>&nums, int begin, int mid)
	{
		int cnt = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] >= begin&&nums[i] <= mid)
			{
				++cnt;
			}
		}
		return cnt;
	}
};



//简洁一点，时间复杂度o(nlogn),空间复杂度o(1)
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int begin = 1, end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			int cnt = 0;
			for (int i = 0; i<nums.size(); ++i)
			{
				if (nums[i] >= begin&&nums[i] <= mid)
				{
					++cnt;
				}
			}
			if (begin == end)
			{
				if (cnt>1)
				{
					return begin;
				}
				else
				{
					return -1;
				}
			}
			if (cnt>mid - begin + 1)
			{
				end = mid;
			}
			else
			{
				begin = mid + 1;
			}
		}
		return -1;
	}
};

//优秀的解法时间复杂度o(n),空间复杂度o(1)
//由于题目限定了区间 [1,n]，所以可以巧妙的利用坐标和数值之间相互转换，而由于重复数字的存在，
//那么一定会形成环，用快慢指针可以找到环并确定环的起始位置
http://bookshadow.com/weblog/2015/09/28/leetcode-find-duplicate-number/
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0, head = 0, meet = 0;
		while (true)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast)
			{
				meet = slow;
				break;
			}
		}
		while (true)
		{
			meet = nums[meet];
			head = nums[head];
			if (meet == head)
			{
				break;
			}
		}
		return meet;
	}
};