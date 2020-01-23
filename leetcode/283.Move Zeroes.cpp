//自己的方法，一遍ac，但需要多次扫描
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int cntzero = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] == 0)
			{
				++cntzero;
			}
		}
		int pos = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] != 0)
			{
				nums[pos] = nums[i];
				++pos;
			}
		}
		for (int i = pos; i<nums.size(); ++i)
		{
			nums[i] = 0;
		}
	}
};

//一次扫描
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = 0, j = 0; i<nums.size(); ++i)
		{
			if (nums[i])
			{
				swap(nums[i], nums[j++]);
			}
		}
	}
};