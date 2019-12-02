//位运算法
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int count_all = 1 << nums.size();
		vector<vector<int>> res;
		for (int i = 0; i<count_all; ++i)
		{
			vector<int> oneset;
			for (int j = 0; j<nums.size(); ++j)
			{
				if (i&(1 << j))
				{
					oneset.push_back(nums[j]);
				}
			}
			res.push_back(oneset);
		}
		return res;
	}
};

//回溯法
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> item;
		vector<vector<int>> res;
		res.push_back({});
		generate(0, nums, item, res);
		return res;
	}
	void generate(int i, vector<int>& nums, vector<int> &item, vector<vector<int>> &res)
	{
		if (i >= nums.size())
		{
			return;
		}
		item.push_back(nums[i]);
		res.push_back(item);
		generate(i + 1, nums, item, res);
		item.pop_back();
		generate(i + 1, nums, item, res);

	}
};