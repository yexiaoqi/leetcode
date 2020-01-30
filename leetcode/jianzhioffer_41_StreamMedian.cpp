//ͬleetcode295
class Solution {
public:
	void Insert(int num)
	{
		small.push(num);
		large.push(small.top());
		small.pop();//large�е�Ԫ��Ҫ����small�е�Ԫ�أ���small�����ѣ�������Ԫ�ظ�large
		if (small.size()<large.size())
		{
			small.push(large.top());
			large.pop();
		}
	}

	double GetMedian()
	{
		return small.size()>large.size() ? small.top() : 0.5*(small.top() + large.top());//ע����double���ͣ�������/2��Ҫ��*0.5
	}
private:
	priority_queue<int> small;
	priority_queue<int, vector<int>, greater<int>> large;
};