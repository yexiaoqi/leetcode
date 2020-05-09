//https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/
//同指南4_15
//这种写法循环条件和平时一致，在里面判断是否到了最后，更容易理解
class Solution {
public:
	int jump(vector<int>& nums) {
		int maxpos = 0;
		int step = 0;
		int end = 0;
		int n = nums.size();
		for (int i = 0; i<n; ++i)
		{
			maxpos = max(maxpos, nums[i] + i);
			if (i == end)
			{
				if (i == n - 1)
				{
					return step;
				}
				end = maxpos;
				++step;
			}
		}
		return step;
	}
};




class Solution {
public:
	int jump(vector<int>& nums) {
		int end = 0;
		int maxpos = 0; //找能跳的最远的
		int step = 0;
		for (int i = 0; i<nums.size() - 1; ++i)//注意i<nums.size()-1，因为开始的时候边界是第 0 个位置，
//steps 已经加 1 了。如果最后一步刚好跳到了末尾，此时 steps 其实不用加 1 了。
//如果是 i < nums.length，i 遍历到最后的时候，会进入 if 语句中，steps 会多加 1。
//因为题目保证了能跳到末尾，所以只要能到达末尾前一个位置，就一定能到末尾
		{
			maxpos = max(maxpos, nums[i] + i);
			if (i == end)
			{
				end = maxpos;//遇到边界，就更新边界，并且步数加一
				step++;
			}
		}
		return step;
	}
};

//复习
class Solution {
public:
	int jump(vector<int>& nums) {
		int step = 0, maxres = 0, end = 0;
		for (int i = 0; i<nums.size() - 1; ++i)
		{
			maxres = max(maxres, nums[i] + i);
			if (i == end)
			{
				++step;
				end = maxres;
			}
		}
		return step;
	}
};


//复习
class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1)
		{
			return 0;
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			nums[i] += i;
		}
		int res = 1;
		int jump = nums[0];
		int i = 0;
		while (i <= jump)
		{
			int tmp = jump;
			if (tmp >= n - 1)
			{
				return res;
			}
			for (int j = i + 1; j <= jump; ++j)
			{
				if (tmp<nums[j])
				{
					tmp = nums[j];
				}

			}
			i = jump;
			jump = tmp;
			++res;
			if (jump >= n - 1)
			{
				return res;
			}
		}
		return res;
	}
};