//�¼�������������start ��¼��ǰ�ĵݹ鵽���±꣬out Ϊһ���⣬res ���������Ѿ��õ��Ľ⣬
//ÿ�ε����µĵݹ麯��ʱ����ʱ�� target Ҫ��ȥ��ǰ����ĵ���
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