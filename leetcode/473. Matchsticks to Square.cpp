//位运算法
class Solution {
public:
	bool makesquare(vector<int>& nums) {
		if (int(nums.size())<4)
		{
			return false;
		}
		int target = 0;
		int sum = 0;
		for (int i = 0; i<int(nums.size()); ++i)
		{
			sum += nums[i];
		}
		target = sum / 4;
		if (sum % 4 != 0)
		{
			return false;
		}
		int all = 1 << nums.size();
		vector<int> quat;
		for (int i = 0; i<all; ++i)
		{
			int tmp = 0;
			for (int j = 0; j<int(nums.size()); ++j)
			{
				if (i&(1 << j))
				{
					tmp += nums[j];
				}
			}
			if (tmp == target)
			{
				quat.push_back(i);
			}
		}
		vector<int> half;
		for (int i = 0; i<int(quat.size()); ++i)
		{
			for (int j = i + 1; j<int(quat.size()); ++j)
			{
				if ((quat[i] & quat[j]) == 0)
				{
					half.push_back(quat[i] | quat[j]);
				}
			}
		}
		for (int i = 0; i<int(half.size()); ++i)
		{
			for (int j = i + 1; j<int(half.size()); ++j)
			{
				if ((half[i] & half[j]) == 0)
				{
					return true;
				}
			}
		}
		return false;
	}
};


//搜索回溯
class Solution {
public:
	bool makesquare(vector<int>& nums) {
		if (int(nums.size())<4)
		{
			return false;
		}
		int target = 0;
		int sum = 0;
		for (int i = 0; i<int(nums.size()); ++i)
		{
			sum += nums[i];
		}
		target = sum / 4;
		if (sum % 4 != 0)
		{
			return false;
		}
		sort(nums.rbegin(), nums.rend());
		int bucket[4] = { 0 };
		return generate(0, nums, target, bucket);
	}
	bool generate(int i, vector<int>& nums, int target, int bucket[])
	{
		if (i >= nums.size())
		{
			return bucket[0] == target&&bucket[1] == target&&bucket[2] == target&&bucket[3] == target;
		}
		for (int j = 0; j<4; ++j)
		{
			if ((nums[i] + bucket[j])>target)
			{
				continue;
			}
			bucket[j] += nums[i];
			if (generate(i + 1, nums, target, bucket))
			{
				return true;
			}
			bucket[j] -= nums[i];
		}
		return false;
	}
};