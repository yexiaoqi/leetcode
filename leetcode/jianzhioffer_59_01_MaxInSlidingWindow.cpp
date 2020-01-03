//ͬleetcode239
//˫�˶��У�ʱ�临�Ӷ�O(n)
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
			if (!q.empty() && q.front() == i - size)//���ж�q.empty(),�������Ϊ��q.front()����
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

//�������� �󶥶�
//�ô󶥶Ѵ洰��Ԫ�أ��Ѷ����ǵ�ǰ�������ֵ�����κ��ƣ�ɾ������ߣ�����һ����Ԫ�أ���ɾ������ʱ�临�Ӷ�O(log(n))���������O(1)�����ַ����ܵ�ʱ�临�Ӷ�O(n��log(k))


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