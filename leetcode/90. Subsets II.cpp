class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<int> item;
		vector<vector<int>> res;
		set<vector<int>> res_set;
		res.push_back({});
		sort(nums.begin(), nums.end());
		generate(0, nums, item, res, res_set);
		return res;
	}
	void generate(int i, vector<int>& nums, vector<int> &item, vector<vector<int>> &res, set<vector<int>> &res_set)
	{
		if (i >= nums.size())
		{
			return;
		}
		item.push_back(nums[i]);
		if (res_set.find(item) == res_set.end())//使用set去重
		{
			res_set.insert(item);//set是用insert
			res.push_back(item);
		}
		generate(i + 1, nums, item, res, res_set);
		item.pop_back();
		generate(i + 1, nums, item, res, res_set);

	}
};