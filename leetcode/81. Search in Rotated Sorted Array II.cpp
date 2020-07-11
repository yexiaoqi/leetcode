//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed ?
//
//Would this affect the run - time complexity ? How and why ?
//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Write a function to determine if a given target is in the array.
//
//The array may contain duplicates.

class Solution
{
public:
	bool search(vector<int>& nums, int target)
	{
		int first = 0, last = nums.size();
		while (first != last)
		{
			int mid = first + (last - first) / 2;
			if (nums[mid] == target)
			{
				return true;
			}
			if (nums[first]<nums[mid])
			{
				if (nums[first] <= target&&nums[mid]>target)//注意是nums[mid]不是nums[last]
				{
					last = mid;
				}
				else
				{
					first = mid + 1;
				}
			}
			else if (nums[first]>nums[mid])
			{
				if (nums[last - 1] >= target&&nums[mid]<target)//注意是last-1
				{
					first = mid + 1;
				}
				else
				{
					last = mid;
				}
			}
			else
			{
				first++;
			}
		}
		return false;
	}
};


class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int size = nums.size();
		if (size == 0)
		{
			return false;
		}
		int begin = 0, end = size - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (target == nums[mid])
			{
				return true;
			}
			if (nums[mid] == nums[end])
			{
				--end;
			}//比没有重复情况只多着一个if
			else if (nums[mid]<nums[end])
			{
				if (target<nums[mid])
				{
					end = mid - 1;
				}
				else
				{
					if (target>nums[end])
					{
						end = mid - 1;
					}
					else if (target == nums[end])
					{
						return true;
					}
					else
					{
						begin = mid + 1;
					}
				}
			}
			else
			{
				if (target>nums[mid])
				{
					begin = mid + 1;
				}
				else
				{
					if (target == nums[begin])
					{
						return true;
					}
					else if (target<nums[begin])
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
		return false;
	}
};