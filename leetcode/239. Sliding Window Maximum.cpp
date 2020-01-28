
//同剑指offer59_01
//自己的方法，复杂度高
class Solution{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		if (k<1 || k>nums.size())
		{
			return vector<int>();
		}
		int n = nums.size() - k + 1;
		vector<int> res;
		int maxnum = INT_MIN;
		for (int i = 0; i<k; ++i)
		{
			dq.push_back(nums[i]);
			if (nums[i]>maxnum)
			{
				maxnum = nums[i];
			}

		}
		res.push_back(maxnum);
		for (int i = 1; i<n; ++i)
		{
			int tmp = dq.front();
			dq.pop_front();
			if (tmp == maxnum)
			{
				maxnum = nums[i];
				for (int j = i + 1; j<i + k - 1; ++j)
				{
					if (nums[j]>maxnum)
					{
						maxnum = nums[j];
					}
				}
			}
			if (nums[i + k - 1]>maxnum)
			{
				maxnum = nums[i + k - 1];
			}
			dq.push_back(nums[i + k - 1]);
			res.push_back(maxnum);
		}
		return res;
	}
};

//正确方法
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		if (k<1 || k>nums.size())
		{
			return vector<int>();
		}
		vector<int> res;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (!dq.empty() && dq.front() == i - k)
			{
				dq.pop_front();
			}
			while (!dq.empty() && nums[i]>nums[dq.back()])
			{
				dq.pop_back();
			}
			dq.push_back(i);
			if (i >= k - 1)
			{
				res.push_back(nums[dq.front()]);
			}
		}
		return res;
	}
};