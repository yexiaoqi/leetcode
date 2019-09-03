//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice ?
//
//For example,
//Given sorted array nums = [1, 1, 1, 2, 2, 3],
//
//Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() <= 2)return nums.size();
		int index = 2;
		for (int i = 2;i < nums.size();i++)//注意是i < nums.size();i++
		{
			if (nums[i] != nums[index - 2])
			{
				nums[index++] = nums[i];
			}
		}
		return index;
	}
};

//solution 2
//易懂
//这里允许最多重复的次数是两次，那么我们就需要用一个变量count来记录还允许有几次重复，count初始化为1，
//如果出现过一次重复，则count递减1，那么下次再出现重复，快指针直接前进一步，如果这时候不是重复的，则count恢复1，
//由于整个数组是有序的，所以一旦出现不重复的数，则一定比这个数大，此数之后不会再有重复项
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2)
		{
			return n;
		}
		int pre = 0, cur = 1, count = 1;
		while (cur<n)
		{
			if (nums[cur] == nums[pre] && count == 0)
			{
				++cur;
			}
			else
			{
				if (nums[cur] == nums[pre])
				{
					--count;
				}
				else
				{
					count = 1;
				}
				nums[++pre] = nums[cur++];
			}
		}
		return pre + 1;
	}
};