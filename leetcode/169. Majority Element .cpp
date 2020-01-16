//Í¬½£Ö¸offer39
class Solution {
public:
	int partition(vector<int> &nums, int begin, int end)
	{
		int key = nums[begin];
		while (begin<end)
		{
			while (begin<end&&nums[end] >= key)
			{
				--end;
			}
			nums[begin] = nums[end];
			while (begin<end&&nums[begin] <= key)
			{
				++begin;
			}
			nums[end] = nums[begin];
		}
		nums[begin] = key;
		return begin;
	}

	int majorityElement(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int begin = 0, end = nums.size() - 1;
		int mid = (begin + end) / 2;
		int index = partition(nums, begin, end);
		while (index != mid)
		{
			if (index>mid)
			{
				end = index - 1;
				index = partition(nums, begin, end);
			}
			else
			{
				begin = index + 1;
				index = partition(nums, begin, end);
			}
		}
		return nums[index];
	}
};


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int res = 0;
		int cnt = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (cnt == 0)
			{
				res = nums[i];
				++cnt;
			}
			else if (res == nums[i])
			{
				++cnt;
			}
			else {
				--cnt;
			}
		}
		return res;
	}
};