//自己的方法会超出内存
class Solution {
public:
	Solution(vector<int>& nums) :level(0), visit(nums.size(), 0)
	{
		// if(!nums.empty())
		// {
		//     visit.push_back(nums.size(),0);
		// }
		findpath(res, nums, visit, path, level);
	}

	void findpath(vector<vector<int>> &res, vector<int> &nums, vector<int> &visit, vector<int> &path, int level)
	{
		if (level == nums.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			if (visit[i] == 1)
			{
				continue;
			}
			path.push_back(nums[i]);
			visit[i] = 1;
			findpath(res, nums, visit, path, level + 1);
			path.pop_back();
			visit[i] = 0;
		}

	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return res[0];
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		return res[rand() % res.size()];
	}
private:
	vector<vector<int>> res;
	vector<int> visit;
	vector<int> path;
	int level;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(nums);
* vector<int> param_1 = obj->reset();
* vector<int> param_2 = obj->shuffle();
*/



//正确方法
class Solution {
public:
	Solution(vector<int>& nums) :v(nums)
	{
	}


	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return v;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> res(v);
		for (int i = v.size() - 1; i >= 0; --i)
		{
			int t = rand() % (i + 1);
			swap(res[i], res[t]);
			//下面这样是错的
			/*int t = res[rand() % (i + 1)];
			swap(res[i], t);*/
			//下面这样是对的
			/*int *t = &res[rand() % (i + 1)];
			swap(res[i], *t);*/
			//没有int *t = *res[rand() % (i + 1)];这种，&取地址
		}
		return res;
	}
private:
	vector<int> v;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(nums);
* vector<int> param_1 = obj->reset();
* vector<int> param_2 = obj->shuffle();
*/