//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.Return the sum of the three integers.You may assume that each input would have exactly one solution.
//
//For example, given array S = { -1 2 1 - 4 }, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());
		int ans;
		int min = INT_MAX;
		for (int i = 0;i<nums.size() - 1;++i)//ע����i<nums.size()-1����i<nums.size()
		{
			int front = i + 1;
			int back = nums.size() - 1;
			while (front<back)
			{
				int sum = nums[i] + nums[front] + nums[back];
				if (abs(sum - target)<min)
				{
					min = abs(sum - target);
					ans = sum;
				}
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
					ans = sum;
					i = nums.size() - 2;//��Ϊ��Ψһ�⣬��������ѭ�� for(int i=0;i<nums.size()-1;++i)
					break;//�������䣬����ᳬʱ��������ǰѭ��while(front<back)
				}
			}
		}
		return ans;
	}
};