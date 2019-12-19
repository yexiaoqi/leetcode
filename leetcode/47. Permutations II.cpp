//dfs回溯法
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
		{
			return res;
		}
		sort(nums.begin(), nums.end());
		vector<int> path, visited(nums.size(), 0);
		find(nums, res, path, visited, 0);
		return res;
	}
	void find(vector<int>& nums, vector<vector<int>> &res, vector<int> &path, vector<int> &visited, int level)
	{
		if (level == nums.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			if (visited[i] == 1)
			{
				continue;
			}
			if (i>0 && nums[i] == nums[i - 1] && visited[i - 1] == 0)
			{
				continue;
			}
			path.push_back(nums[i]);
			visited[i] = 1;
			find(nums, res, path, visited, level + 1);
			path.pop_back();
			visited[i] = 0;
		}
	}
};

//dfs回溯法，偷懒使用set去重
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		set<vector<int>> res;
		if (nums.size() == 0)
		{
			return vector<vector<int>>(res.begin(), res.end());
		}
		//sort(nums.begin(), nums.end());
		vector<int> path, visited(nums.size(), 0);
		find(nums, res, path, visited, 0);
		return vector<vector<int>>(res.begin(), res.end());
	}
	void find(vector<int>& nums, set<vector<int>> &res, vector<int> &path, vector<int> &visited, int level)
	{
		if (level == nums.size())
		{
			res.insert(path);
			return;
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			if (visited[i] == 1)
			{
				continue;
			}
			if (i>0 && nums[i] == nums[i - 1] && visited[i - 1] == 0)
			{
				continue;
			}
			path.push_back(nums[i]);
			visited[i] = 1;
			find(nums, res, path, visited, level + 1);
			path.pop_back();
			visited[i] = 0;
		}
	}
};


//交换法
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
		{
			return res;
		}
		sort(nums.begin(), nums.end());
		find(nums, res, 0);
		return res;
	}
	void find(vector<int> &nums, vector<vector<int>> &res, int level)
	{
		if (level == nums.size())
		{
			res.push_back(nums);
		}
		for (int i = level; i<nums.size(); ++i)
		{
			if (level != i&&nums[level] == nums[i])
			{
				continue;
			}
			int j = i - 1;
			while (j >= level&&nums[j] != nums[i])
			{
				--j;
			}
			if (j != level - 1)
			{
				continue;
			}
			swap(nums[level], nums[i]);
			find(nums, res, level + 1);
			swap(nums[level], nums[i]);
		}
	}
};

//交换法，偷懒使用set去重
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		set<vector<int>> res;
		if (nums.size() == 0)
		{
			return vector<vector<int>>(res.begin(), res.end());
		}
		find(nums, res, 0);
		return vector<vector<int>>(res.begin(), res.end());
	}
	void find(vector<int>& nums, set<vector<int>> &res, int level)
	{
		if (level == nums.size())
		{
			res.insert(nums);
		}
		for (int i = level; i<nums.size(); ++i)
		{
			// if (level != i&&nums[level] == nums[i])
			// {
			// 	continue;
			// }
			swap(nums[level], nums[i]);
			find(nums, res, level + 1);
			swap(nums[level], nums[i]);
		}
	}
};
