//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
//
//Note : The solution set must not contain duplicate triplets.
//
//	For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//	A solution set is :
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]
class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> res;
		std::sort(nums.begin(), nums.end());
		for (int i = 0;i<nums.size();++i)
		{
			int target = -nums[i];
			int front = i + 1;
			int back = nums.size() - 1;
			if (target<0)
			{
				break;
			}
			while (front<back)
			{
				int sum = nums[front] + nums[back];
				if (sum<target)
				{
					++front;
				}
				else if (sum>target)
				{
					--back;
				}
				else
				{
					vector<int> triplet(3, 0);
					triplet[0] = nums[i];
					triplet[1] = nums[front];
					triplet[2] = nums[back];
					res.push_back(triplet);
					while (front<back&&nums[front] == triplet[1])
					{
						++front;
					}//注意去重
					while (front<back&&nums[back] == triplet[2])
					{
						--back;
					}//注意去重
				}
			}
			while (nums[i + 1] == nums[i] && i + 1<nums.size())
			{
				++i;
			}//注意去重
		}
		return res;
	}
};

//复习
//自己写的以下这种解法（先 fix 一个数，然后另外两个数使用 Two Sum 那种 HashMap 的解法）超时
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		map<char, int> m;
		if (nums.size() <3)
		{
			return vector<vector<int>>();
		}
		//vector<vector<int>> res;
		set<vector<int>> res_set;
		for (int i = 0; i<nums.size(); ++i)
		{
			m[nums[i]] = i;
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			for (int j = i + 1; j<nums.size(); ++j)
			{
				int gap = -nums[i] - nums[j];
				if (m.find(gap) != m.end() && m[gap]>j)
				{
					vector<int> one;
					one.push_back(nums[i]);
					one.push_back(nums[j]);
					one.push_back(gap);
					sort(one.begin(), one.end());
					res_set.insert(one);
					// res.push_back(one);
				}
			}
		}
		return vector<vector<int>>(res_set.begin(), res_set.end());
	}
};


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());//先排序才能有下面的判断
		if (nums.size()<3 || nums.back()<0 || nums.front()>0)//先判断是否全是正数或负数
		{
			return vector<vector<int>>();
		}
		for (int i = 0; i<nums.size() - 2; ++i)
		{
			if (nums[i]>0)
			{
				break;
			}
			if (i>0 && nums[i] == nums[i - 1])
			{
				continue;//去除重复的遍历
			}
			int begin = i + 1;
			int end = nums.size() - 1;
			while (begin<end)
			{
				if (nums[begin] + nums[end]<-nums[i])
				{
					++begin;
				}
				else if (nums[begin] + nums[end]>-nums[i])
				{
					--end;
				}
				else
				{
					res.push_back({ nums[i],nums[begin],nums[end] });
					while (begin<end&&nums[begin] == nums[begin + 1])
					{
						++begin;//去除重复的遍历
					}
					while (begin<end&&nums[end] == nums[end - 1])
					{
						--end;//去除重复的遍历
					}
					++begin;
					--end;//找到一组后要移动begin和end
				}
			}
		}
		return res;
	}
};



//复习
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size()<3)
		{
			return vector<vector<int>>();
		}
		sort(nums.begin(), nums.end());
		if (nums[0]>0 || nums[nums.size() - 1]<0)
		{
			return vector<vector<int>>();
		}
		vector<vector<int>> res;
		//set<vector<int>> res_set;
		for (int i = 0; i<nums.size() - 2; ++i)
		{
			if (nums[i]>0)
			{
				break;
			}
			if (i>0 && nums[i] == nums[i - 1])
				//if(nums[i]==nums[i+1])//比如-1，-1,2，不能用nums[i]==nums[i+1]判断这样就没有解了
			{
				continue;//不能都交给set去重，否则复杂度太高
			}
			int target = -nums[i];
			int begin = i + 1, end = nums.size() - 1;
			while (begin<end)
			{
				int sum = nums[begin] + nums[end];
				if (sum == target)
				{
					//res_set.insert({nums[i],nums[begin],nums[end]});
					res.push_back({ nums[i],nums[begin],nums[end] });
					while (begin<end&&nums[begin] == nums[begin + 1])//要保证begin<end
					{
						++begin;
					}
					while (begin<end&&nums[end] == nums[end - 1])
					{
						--end;
					}
					++begin;
					--end;
				}
				else if (sum<target)
				{
					++begin;
				}
				else
				{
					--end;
				}
			}
		}
		return res;
		//return vector<vector<int>>(res_set.begin(),res_set.end());
	}
};


//复习
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size()<3)
		{
			return res;
		}
		sort(nums.begin(), nums.end());
		int begin = 0, end = nums.size() - 1;
		if (nums[begin]>0 || nums[end]<0)
		{
			return res;
		}
		for (int i = 0; i<nums.size() - 2; ++i)
		{
			if (nums[i]>0)
			{
				break;
			}
			if (i>0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			begin = i + 1;
			end = nums.size() - 1;//注意要重新赋值，上一轮被改变过了
			while (begin<end)
			{
				int tmp = nums[i] + nums[begin] + nums[end];
				if (tmp == 0)
				{
					res.push_back({ nums[i],nums[begin],nums[end] });
					while (begin<end&&nums[begin] == nums[begin + 1])
					{
						++begin;
					}
					while (begin<end&&nums[end] == nums[end - 1])
					{
						--end;
					}
					++begin;
					--end;
				}
				else if (tmp<0)
				{
					++begin;
				}
				else
				{
					--end;
				}
			}
		}
		return res;
	}
};