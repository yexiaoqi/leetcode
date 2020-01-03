//同leetcode239
//双端队列，时间复杂度O(n)
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		deque<int> q;
		vector<int> res;
		if (num.size()<size)
		{
			return vector<int>();
		}
		if (k <= 0)
		{
			return res;
		}
		for (int i = 0; i<num.size(); ++i)
		{
			if (!q.empty() && q.front() == i - size)//先判断q.empty(),否则如果为空q.front()出错
			{
				q.pop_front();
			}
			while (!q.empty() && num[i]>num[q.back()])
			{
				q.pop_back();
			}
			q.push_back(i);
			if (i >= size - 1)
			{
				res.push_back(num[q.front()]);
			}
		}
		return res;
	}
};

//方法二： 大顶堆
//用大顶堆存窗口元素，堆顶就是当前窗口最大值，依次后移，删除最左边，加入一个新元素，堆删除操作时间复杂度O(log(n))，插入操作O(1)，这种方法总的时间复杂度O(n·log(k))


class Solution {
public:
	vector<int> maxInWindows(vector<int>& nums, int k)
	{
		vector<int> res;
		priority_queue<pair<int, int>> q;
		if (num.size()<size)
		{
			return vector<int>();
		}
		if (k <= 0)
		{
			return res;
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			while (!q.empty() && q.top().second <= i - k)
			{
				q.pop();
			}
			q.push({ nums[i],i });
			if (i >= k - 1)
			{
				res.push_back(q.top().first);
			}
		}
		return res;
	}
};