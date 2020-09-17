//类似题目78，90，39，40，46，47
//位运算法
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int count_all = 1 << nums.size();
		vector<vector<int>> res;
		for (int i = 0; i<count_all; ++i)
		{
			vector<int> oneset;
			for (int j = 0; j<nums.size(); ++j)
			{
				if (i&(1 << j))
				{
					oneset.push_back(nums[j]);
				}
			}
			res.push_back(oneset);
		}
		return res;
	}
};

//回溯法
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> item;
		vector<vector<int>> res;
		res.push_back({});
		generate(0, nums, item, res);
		return res;
	}
	void generate(int i, vector<int>& nums, vector<int> &item, vector<vector<int>> &res)
	{
		if (i >= nums.size())
		{
			return;
		}
		item.push_back(nums[i]);
		res.push_back(item);
		generate(i + 1, nums, item, res);
		item.pop_back();
		generate(i + 1, nums, item, res);

	}
};

//复习
//自己写的，这样超时
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
		{
			res.push_back(vector<int>());
			return res;
		}
		vector<int> marker(nums.size(), 0);
		set<vector<int>> res_set;
		vector<int> one;
		sub(nums, res_set, one, marker);
		//sub(nums, res, one, marker);
		vector<vector<int>> res2(res_set.begin(), res_set.end());
		res2.push_back(vector<int>());
		return res2;
	}
	//void sub(vector<int>& nums, vector<vector<int>> &res, vector<int>& one, vector<int> &marker)
	void sub(vector<int>& nums, set<vector<int>> &res_set, vector<int>& one, vector<int> &marker)
	{
		for (int i = 0; i<nums.size(); ++i)
		{
			if (marker[i] == 0)
			{
				one.push_back(nums[i]);
				marker[i] = 1;
				/*sort(one.begin(), one.end());
				res.push_back(one);*/
				//不能像上面这样，因为改变one的顺序以后后面one.pop_back();应该pop的值被改变了
				vector<int> two = one;
				sort(two.begin(), two.end());
				res_set.insert(two);
				sub(nums, res_set, one, marker);
				one.pop_back();
				marker[i] = 0;
			}
		}
	}
};

//正确
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> one;
		sub(nums, res, one, 0);
		return res;
	}
	void sub(vector<int>& nums, vector<vector<int>> &res, vector<int>& one, int level)
	{
		res.push_back(one);
		for (int i = level; i<nums.size(); ++i)//注意i从level开始
		{
			one.push_back(nums[i]);
			sub(nums, res, one, i + 1);
			one.pop_back();
		}
	}
};

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		int countall = 1 << nums.size();
		for (int i = 0; i<countall; ++i)
		{
			vector<int> one;
			for (int j = 0; j<nums.size(); ++j)
			{
				if (i & 1 << j)
				{
					one.push_back(nums[j]);
				}
			}
			res.push_back(one);
		}
		return res;
	}

};

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		vector<int> path;
		vector<vector<int>> res;
		int pos = 0;
		subs(nums, path, res, pos);
		res.push_back({});
		return res;
	}
	void subs(vector<int>& nums, vector<int> &path, vector<vector<int>> &res, int pos)
	{
		if (pos >= nums.size())
		{
			return;
		}
		path.push_back(nums[pos]);
		res.push_back(path);
		subs(nums, path, res, pos + 1);
		path.pop_back();
		subs(nums, path, res, pos + 1);
	}
};