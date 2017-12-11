//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target ? Find all unique quadruplets in the array which gives the sum of target.
//
//Note : The solution set must not contain duplicate quadruplets.
//
//	For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
//	A solution set is :
//[
//	[-1, 0, 0, 1],
//	[-2, -1, 1, 2],
//	[-2, 0, 0, 2]
//]

class Solution
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		if (nums.size()<4)
		{
			return res;
		}
		for (int i = 0;i<nums.size() - 3;++i)
		{
			for (int j = i + 1;j<nums.size() - 2;++j)
			{
				int front = j + 1;
				int back = nums.size() - 1;
				while (front<back)
				{
					int sum = nums[i] + nums[j] + nums[front] + nums[back];
					if (sum<target)
					{
						++front;
					}
					else if (sum>target)
					{
						--back;
					}
					else
					{
						vector<int> quads(4, 0);
						quads[0] = nums[i];
						quads[1] = nums[j];
						quads[2] = nums[front];
						quads[3] = nums[back];
						res.push_back(quads);
						while (nums[front] == quads[2] && front<back)
						{
							++front;
						}
						while (nums[back] == quads[3] && front<back)
						{
							--back;
						}
					}
					while (nums[j + 1] == nums[j])
					{
						++j;
					}
				}

			}
			while (nums[i + 1] == nums[i])
			{
				++i;
			}
		}
		return res;
	}
};