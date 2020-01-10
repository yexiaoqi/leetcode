//最差情况会变成o(n)
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		int lindex = -1, rindex = -1;
		vector<int> res;
		for (int i = 0; i<2; ++i)
		{
			res.push_back(-1);
		}
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] == target)
			{
				lindex = rindex = mid;
				while (lindex>0 && nums[lindex - 1] == target)
				{
					--lindex;
				}
				while (rindex<nums.size() - 1 && nums[rindex + 1] == target)
				{
					++rindex;
				}
				res[0] = lindex;
				res[1] = rindex;
				//if(begin==end)
				{
					return res;
				}
			}
			else if (nums[mid]<target)
			{
				if (mid == nums.size() - 1 || nums[mid + 1]>target)
				{
					return res;
				}
				begin = mid + 1;
			}
			else
			{
				if (mid == 0 || nums[mid - 1]<target)
				{
					return res;
				}
				end = mid - 1;
			}
		}

		return res;
	}
};

//真正的二分
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		vector<int> res(2, -1);
		int left = 0;
		int right = data.size();
		while (left<right)
		{
			int mid = left + (right - left) / 2;
			if (data[mid]<k)
			{
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		if (right == data.size() || data[right] != k)
		{
			return 0;
		}
		res[0] = right;
		//left=0;
		right = data.size();
		while (left<right)
		{
			int mid = left + (right - left) / 2;
			if (data[mid] <= k)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		res[1] = right - 1;
		return res[1] - res[0] + 1;
	}
};

//写成调用一个函数的形式
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		vector<int> res(2, -1);
		res[0] = get(data, k);
		if (res[0] == data.size() || data[res[0]] != k)
		{
			return 0;
		}
		res[1] = get(data, k + 1) - 1;
		return res[1] - res[0] + 1;
	}
	int get(vector<int> data, int k)
	{
		int left = 0;
		int right = data.size();
		while (left<right)
		{
			int mid = (right + left) / 2;
			if (data[mid]<k)
			{
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return right;
	}
};


//复习
//自己写的方法，这样和经常的写法一致，推荐
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		if (nums.size() == 0)
		{
			return res;
		}
		res[0] = findleft(nums, target);
		if (res[0] != -1)
		{
			res[1] = findright(nums, target);
		}
		return res;
	}
	int findleft(vector<int>& nums, int target)
	{
		int begin = 0, end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] == target)
			{
				if (mid == 0 || nums[mid - 1] != target)
				{
					return mid;
				}
				else
				{
					end = mid - 1;
				}
			}
			else if (nums[mid]>target)
			{
				end = mid - 1;
			}
			else
			{
				begin = mid + 1;
			}
		}
		return -1;
	}
	int findright(vector<int>& nums, int target)
	{
		int begin = 0, end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] == target)
			{
				if (mid == nums.size() - 1 || nums[mid + 1] != target)
				{
					return mid;
				}
				else
				{
					begin = mid + 1;
				}
			}
			else if (nums[mid]>target)
			{
				end = mid - 1;
			}
			else
			{
				begin = mid + 1;
			}
		}
		return -1;
	}
};

//增强复用
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		if (nums.size() == 0)
		{
			return res;
		}
		int left = 0, right = 1;
		res[0] = find(nums, target, 0);
		if (res[0] != -1)
		{
			res[1] = find(nums, target, 1);
		}
		return res;
	}
	int find(vector<int>& nums, int target, int index)
	{
		int begin = 0, end = nums.size() - 1;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] == target)
			{
				if (index == 0)
				{
					if (mid == 0 || nums[mid - 1] != target)
					{
						return mid;
					}
					else
					{
						end = mid - 1;
					}
				}
				else
				{
					if (mid == nums.size() - 1 || nums[mid + 1] != target)
					{
						return mid;
					}
					else
					{
						begin = mid + 1;
					}
				}
			}
			else if (nums[mid]>target)
			{
				end = mid - 1;
			}
			else
			{
				begin = mid + 1;
			}
		}
		return -1;
	}
};