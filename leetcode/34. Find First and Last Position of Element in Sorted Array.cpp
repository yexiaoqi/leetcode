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