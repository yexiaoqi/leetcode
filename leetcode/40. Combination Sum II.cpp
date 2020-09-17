//类似题目78，90，39，40，46，47
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> path;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());//用于去重
		combinationSum2(candidates, target, path, res, 0);
		return res;
	}
	void combinationSum2(vector<int>& candidates, int target, vector<int> &path, vector<vector<int>> &res, int start)
	{
		if (target == 0)
		{
			res.push_back(path);
			return;
		}
		if (target<0)
		{
			return;
		}
		for (int i = start; i<candidates.size(); ++i)
		{
			path.push_back(candidates[i]);
			combinationSum2(candidates, target - candidates[i], path, res, i + 1);
			path.pop_back();
			while (i + 1<candidates.size() && candidates[i] == candidates[i + 1])
			{
				++i;
			}
		}
	}
};

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> item;
		set<vector<int>> res_set;
		int sum = 0;
		sort(candidates.begin(), candidates.end());
		generate(0, sum, item, res, res_set, target, candidates);
		return res;
	}
	void generate(int i, int &sum, vector<int> &item, vector<vector<int>> &res, set<vector<int>> &res_set, int target, vector<int>& candidates)
	{
		if (i >= candidates.size() || sum>target)
		{
			return;
		}
		sum += candidates[i];
		item.push_back(candidates[i]);
		if (sum == target&&res_set.find(item) == res_set.end())
		{
			res.push_back(item);
			res_set.insert(item);
		}
		generate(i + 1, sum, item, res, res_set, target, candidates);
		item.pop_back();
		sum -= candidates[i];
		generate(i + 1, sum, item, res, res_set, target, candidates);
	}
};


//和39接近的写法
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> path;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		combination(candidates, target, 0, path, res);
		return res;
	}
	void combination(vector<int>& candidates, int target, int start, vector<int> &path, vector<vector<int>> &res)
	{
		if (target<0)
		{
			return;
		}
		if (target == 0)
		{
			res.push_back(path);
			return;
		}
		for (int i = start; i<candidates.size(); ++i)
		{
			if (i > start && candidates[i] == candidates[i - 1])
			{
				continue;
			}
			path.push_back(candidates[i]);
			combination(candidates, target - candidates[i], i + 1, path, res);
			path.pop_back();
		}
	}
};

//
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> path;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		combination(candidates, target, 0, path, res);
		return res;
	}
	void combination(vector<int>& candidates, int target, int start, vector<int> &path, vector<vector<int>> &res)
	{
		if (target<0)
		{
			return;
		}
		if (target == 0)
		{
			res.push_back(path);
			return;
		}
		for (int i = start; i<candidates.size(); ++i)
		{
			if (i > start && candidates[i] == candidates[i - 1])
			{
				continue;
			}
			path.push_back(candidates[i]);
			combination(candidates, target - candidates[i], i + 1, path, res);
			path.pop_back();
		}
	}
};