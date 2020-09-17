//������Ŀ78��90��39��40��46��47
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
			// sort(path.begin(),path.end());//path���滹Ҫpop_back������ֱ������
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
		for (int i = start; i<candidates.size(); ++i)//���ܴ�0��ʼ������2,2,3��3,2,3�ظ�
		{
			target -= candidates[i];
			path.push_back(candidates[i]);
			combinationSum(candidates, target, path, res, i);//ע���������ֿ��ظ������Ի��Ǵ�i��ʼ
			path.pop_back();
			target += candidates[i];
		}
	}
};
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