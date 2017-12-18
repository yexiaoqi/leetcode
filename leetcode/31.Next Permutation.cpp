//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//
//The replacement must be in - place, do not allocate extra memory.
//
//Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//1, 2, 3 → 1, 3, 2
//3, 2, 1 → 1, 2, 3
//1, 1, 5 → 1, 5, 1

class Solution
{
public:
	void nextPermutation(vector<int>& nums)
	{
		int k = -1;
		for (int i = nums.size() - 2;i >= 0;--i)//i--和--i无所谓，都可以
		{
			if (nums[i]<nums[i + 1])
			{
				k = i;
				break;
			}//注意if后要加括号，否则break不对
		}
		if (k == -1)
		{
			reverse(nums.begin(), nums.end());
			return;
		}
		for (int i = nums.size() - 1;i>k;--i)//i--和--i无所谓，都可以
		{
			if (nums[i]>nums[k])
			{
				swap(nums[i], nums[k]);
				break;
			}
		}
		reverse(nums.begin() + k + 1, nums.end());
	}
};