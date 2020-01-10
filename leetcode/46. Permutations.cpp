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

//dfs回溯法，这样生成的[[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]] 。是按字典序排列的
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


//交换法，得到的全排列不是字典序
//方法1.传引用
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
			swap(nums[pos], nums[i]);//for循环将pos~end中的每个数放到pos位置中去
			dfs(pos + 1, nums, result);//假设pos位置确定，那么对pos+1~end中的数继续递归
			swap(nums[pos], nums[i]);
		}
	}
};
//方法2.传值
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
			swap(nums[pos], nums[i]);//for循环将pos~end中的每个数放到pos位置中去
			dfs(pos + 1, nums, result);//假设pos位置确定，那么对pos+1~end中的数继续递归
									   //swap(nums[pos],nums[i]);
		}
	}
};


//复习
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		int size = nums.size();
		if (size == 0)
		{
			return vector<vector<int>>();
		}
		vector<int> one;
		vector<int> marker(size, 0);
		perm(nums, one, res, size, marker, 0);
		return res;
	}
	void perm(vector<int>& nums, vector<int> &one, vector<vector<int>> &res, int size, vector<int>& marker, int level)
	{
		if (one.size() == size)
		{
			res.push_back(one);
			return;
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			if (marker[i] == 0)
			{
				one.push_back(nums[i]);
				marker[i] = 1;
				perm(nums, one, res, size, marker, level + 1);
				one.pop_back();
				marker[i] = 0;
			}
		}


		// for(int i=0;i<nums.size();++i)
		// {
		//     if(marker[i]==0)
		//     {
		//         one.push_back(nums[i]);
		//     }
		//     perm(nums,one,res,size,marker);
		// }
	}
};