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
		if (res_set.find(item) == res_set.end())//ʹ��setȥ��
		{
			res_set.insert(item);//set����insert
			res.push_back(item);
		}
		generate(i + 1, nums, item, res, res_set);
		item.pop_back();
		generate(i + 1, nums, item, res, res_set);

	}
};

//
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());//��Ҫ���򣬷���1,2��2,1��Ϊ��ͬ
		vector<int> path;
		vector<vector<int>> res;//unordered_setĬ���޷���ϣvector����Ҫ��set
		subsetsWithDup(nums, path, res, 0);
		return res;
	}
	void subsetsWithDup(vector<int> &nums, vector<int> &path, vector<vector<int>> &res, int pos)
	{
		res.push_back(path);
		for (int i = pos; i<nums.size(); ++i)
		{
			path.push_back(nums[i]);
			subsetsWithDup(nums, path, res, i + 1);//ע����i+1����pos+1
			path.pop_back();
			while (i + 1<nums.size() && nums[i] == nums[i + 1])
			{
				++i;
			}
		}
	}
};