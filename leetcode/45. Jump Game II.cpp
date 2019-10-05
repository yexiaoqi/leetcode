//https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/
class Solution {
public:
	int jump(vector<int>& nums) {
		int end = 0;
		int maxpos = 0;
		int step = 0;
		for (int i = 0; i<nums.size() - 1; ++i)//×¢Òâi<nums.size()-1
		{
			maxpos = max(maxpos, nums[i] + i);
			if (i == end)
			{
				end = maxpos;
				step++;
			}
		}
		return step;
	}
};