//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.

//https://www.cnblogs.com/grandyang/p/4325648.html
//二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段，我们观察上面红色的数字都是升序的，
//由此我们可以观察出规律，如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，
//我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了
class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		int first = 0, last = nums.size();
		while (first != last)//不是nums[first]!=nums[last]
		{
			const int mid = first + (last - first) / 2;
			if (nums[mid] == target)return mid;
			if (nums[first] <= nums[mid])
			{
				if (nums[first] <= target&&nums[mid]>target)
					last = mid;
				else
					first = mid + 1;
			}
			else
			{
				if (nums[mid]<target&&nums[last - 1] >= target)
					first = mid + 1;
				else
					last = mid;
			}
		}
		return -1;
	}
};
//https://www.bilibili.com/video/av29912609/?p=6 例3
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid]>target)
			{
				if (nums[mid]>nums[begin])
				{
					if (target >= nums[begin])
					{
						end = mid - 1;
					}
					else
					{
						begin = mid + 1;
					}
				}
				else if (nums[mid]<nums[begin])
				{
					end = mid - 1;
				}
				else
				{
					begin = mid + 1;
				}
			}
			else
			{
				if (nums[mid]>nums[begin])
				{
					begin = mid + 1;
				}
				else if (nums[mid]<nums[begin])
				{
					if (target >= nums[begin])
					{
						end = mid - 1;
					}
					else
					{
						begin = mid + 1;
					}
				}
				else
				{
					begin = mid + 1;
				}
			}

		}
		return -1;
	}
};



class Solution {
public:
	int search(vector<int>&nums, int target)
	{
		if (nums.size() == 0)
		{
			return -1;
		}
		int begin = 0, end = nums.size() - 1;
		while (begin < end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] < nums[end])
			{
				if (target == nums[mid])
				{
					return mid;
				}
				else if (target < nums[mid])
				{
					end = mid - 1;
				}
				else
				{
					if (target < nums[mid])
					{
						end = mid - 1;
					}
					else
					{
						begin = mid + 1;
					}
				}
			}
			else
			{
				if (target == nums[mid])
				{
					return mid;
				}
				else if (target > mid)
				{
					begin = mid + 1;
				}
				else
				{
					end = mid - 1;
				}
			}
		}
		return -1;
	}
	
};
//复习
//自己写的，一遍ac
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int begin = 0, end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid]<nums[end])
			{
				if (target == nums[mid])
				{
					return mid;
				}
				else if (target<nums[mid])
				{
					end = mid - 1;
				}
				else
				{
					if (target>nums[end])
					{
						end = mid - 1;
					}
					else
					{
						begin = mid + 1;
					}
				}
			}
			else
			{
				if (target == nums[mid])
				{
					return mid;
				}
				else if (target>nums[mid])
				{
					begin = mid + 1;
				}
				else
				{
					if (target<nums[begin])
					{
						begin = mid + 1;
					}
					else
					{
						end = mid - 1;
					}
				}
			}
		}
		return -1;
	}
};


//复习
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid]<nums[end])
			{
				if (nums[mid] == target)
				{
					return mid;
				}
				else if (nums[mid]>target)
				{
					end = mid - 1;
				}
				else
				{
					if (target>nums[end])
					{
						end = mid - 1;
					}
					else
					{
						begin = mid + 1;
					}
				}
			}
			else
			{
				if (nums[mid] == target)
				{
					return mid;
				}
				else if (nums[mid]<target)
				{
					begin = mid + 1;
				}
				else
				{
					if (target<nums[begin])
					{
						begin = mid + 1;
					}
					else
					{
						end = mid - 1;
					}
				}
			}
		}
		return -1;
	}
};