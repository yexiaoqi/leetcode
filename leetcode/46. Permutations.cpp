//Given a collection of distinct numbers, return all possible permutations.
//
//For example,
//[1, 2, 3] have the following permutations :
//[
//	[1, 2, 3],
//	[1, 3, 2],
//	[2, 1, 3],
//	[2, 3, 1],
//	[3, 1, 2],
//	[3, 2, 1]
//]

//dfs���ݷ����������ɵ�[[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]] ���ǰ��ֵ������е�
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
		{
			return res;
		}
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
			path.push_back(nums[i]);
			visited[i] = 1;
			find(nums, res, path, visited, level + 1);
			path.pop_back();
			visited[i] = 0;
		}
	}
};


//���������õ���ȫ���в����ֵ���
//����1.������
class Solution
{
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>>result;
		dfs(0, nums, result);
		return result;
	}
	void dfs(int pos, vector<int>&nums, vector<vector<int>> &result)
	{
		if (pos == nums.size())
		{
			result.push_back(nums);
			return;
		}
		for (int i = pos;i<nums.size();++i)
		{
			swap(nums[pos], nums[i]);//forѭ����pos~end�е�ÿ�����ŵ�posλ����ȥ
			dfs(pos + 1, nums, result);//����posλ��ȷ������ô��pos+1~end�е��������ݹ�
			swap(nums[pos], nums[i]);
		}
	}
};
//����2.��ֵ
class Solution 
{
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>>result;
		dfs(0, nums, result);
		return result;
	}
	void dfs(int pos, vector<int>nums, vector<vector<int>> &result)
	{
		if (pos == nums.size())
		{
			result.push_back(nums);
			return;
		}
		for (int i = pos;i<nums.size();++i)
		{
			swap(nums[pos], nums[i]);//forѭ����pos~end�е�ÿ�����ŵ�posλ����ȥ
			dfs(pos + 1, nums, result);//����posλ��ȷ������ô��pos+1~end�е��������ݹ�
									   //swap(nums[pos],nums[i]);
		}
	}
};