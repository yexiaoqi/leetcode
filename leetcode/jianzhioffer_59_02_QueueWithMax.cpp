class Solution {
public:
	Solution() :curdex(0)
	{

	}
	void push_back(int x)
	{
		while (!max_q.empty() && x >= max_q.back().num)
		{
			max_q.pop_back();
		}
		Data data = { x,curdex };
		q.push_back(data);
		max_q.push_back(data);
		++curdex;
	}
	void pop_front()
	{
		if (q.empty())
		{
			throw new exception("queue is empty()");
		}
		if (max_q.front().index == q.front().index)
		{
			max_q.pop_front();
		}
		q.pop_front();
	}
	int max()
	{
		if (max_q.empty())
		{
			throw new exception("queue is empty()");
		}
		return max_q.back().num;
	}
private:
	struct Data
	{
		int num;
		int index;
	};
	deque<Data> q;
	deque<Data> max_q;
	int curdex;
};