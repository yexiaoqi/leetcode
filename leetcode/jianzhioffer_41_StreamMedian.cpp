//同leetcode295
class Solution {
public:
	void Insert(int num)
	{
		small.push(num);
		large.push(small.top());
		small.pop();//large中的元素要大于small中的元素，把small（最大堆）中最大的元素给large
		if (small.size()<large.size())
		{
			small.push(large.top());
			large.pop();
		}
	}

	double GetMedian()
	{
		return small.size()>large.size() ? small.top() : 0.5*(small.top() + large.top());//注意是double类型，不能用/2，要用*0.5
	}
private:
	priority_queue<int> small;
	priority_queue<int, vector<int>, greater<int>> large;
};