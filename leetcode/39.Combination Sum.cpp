//新加入三个变量，start 记录当前的递归到的下标，out 为一个解，res 保存所有已经得到的解，
//每次调用新的递归函数时，此时的 target 要减去当前数组的的数
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> path;
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
			path.push_back(candidates[i]);
			combination(candidates, target - candidates[i], i, path, res);
			path.pop_back();
		}
	}
};