//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
//
//Note : The solution set must not contain duplicate triplets.
//
//	For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//	A solution set is :
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> res;
		std::sort(nums.begin(), nums.end());
		for (int i = 0;i<nums.size();++i)
		{
			int target = -nums[i];
			int front = i + 1;
			int back = nums.size() - 1;
			if (target<0)
			{
				break;
			}
			while (front<back)
			{
				int sum = nums[front] + nums[back];
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
					vector<int> triplet(3, 0);
					triplet[0] = nums[i];
					triplet[1] = nums[front];
					triplet[2] = nums[back];
					res.push_back(triplet);
					while (front<back&&nums[front] == triplet[1])
					{
						++front;
					}//注意去重
					while (front<back&&nums[back] == triplet[2])
					{
						--back;
					}//注意去重
				}
			}
			while (nums[i + 1] == nums[i] && i + 1<nums.size())
			{
				++i;
			}//注意去重
		}
		return res;
	}
};