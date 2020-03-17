//https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/
class Solution {
public:
	int jump(vector<int>& nums) {
		int end = 0;
		int maxpos = 0; //找能跳的最远的
		int step = 0;
		for (int i = 0; i<nums.size() - 1; ++i)//注意i<nums.size()-1，因为开始的时候边界是第 0 个位置，
//steps 已经加 1 了。如果最后一步刚好跳到了末尾，此时 steps 其实不用加 1 了。
//如果是 i < nums.length，i 遍历到最后的时候，会进入 if 语句中，steps 会多加 1。
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