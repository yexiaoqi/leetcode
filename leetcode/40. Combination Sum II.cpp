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