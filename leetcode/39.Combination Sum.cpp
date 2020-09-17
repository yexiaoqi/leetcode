//类似题目78，90，39，40，46，47
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> path;
		set<vector<int>> res;
		combinationSum(candidates, target, path, res, 0);
		return vector<vector<int>>(res.begin(), res.end());
	}
	void combinationSum(vector<int>& candidates, int target, vector<int> &path, set<vector<int>> &res, int start)
	{
		if (target == 0)
		{
			// sort(path.begin(),path.end());//path后面还要pop_back，不能直接排序
			if (!res.count(path))
			{
				res.insert(path);
			}
			//res.insert(path);
			return;
		}
		if (target<0)
		{
			return;
		}
		for (int i = start; i<candidates.size(); ++i)//不能从0开始，否则2,2,3和3,2,3重复
		{
			target -= candidates[i];
			path.push_back(candidates[i]);
			combinationSum(candidates, target, path, res, i);//注意由于数字可重复，所以还是从i开始
			path.pop_back();
			target += candidates[i];
		}
	}
};
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

//
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