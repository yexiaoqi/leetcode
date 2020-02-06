//自己做出
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num)
	{
		maxheap.push(num);
		if (minheap.size()<maxheap.size())
		{
			minheap.push(maxheap.top());//堆顶是top
			maxheap.pop();
		}
		if (!maxheap.empty() && (maxheap.top()>minheap.top()))
		{
			maxheap.push(minheap.top());
			minheap.pop();
			minheap.push(maxheap.top());
			maxheap.pop();
		}
	}

	double findMedian() {
		if (minheap.size() == maxheap.size() + 1)
		{
			return minheap.top();
		}
		return (maxheap.top() + minheap.top()) / 2.0;
	}
private:
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/

//稍微简化
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num)
	{
		minheap.push(num);
		maxheap.push(minheap.top());
		minheap.pop();
		if (minheap.size()<maxheap.size())
		{
			minheap.push(maxheap.top());
			maxheap.pop();
		}
	}

	double findMedian() {
		if (minheap.size() == maxheap.size() + 1)
		{
			return minheap.top();
		}
		return (maxheap.top() + minheap.top()) / 2.0;
	}
private:
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/


//follow up1，使用计数排序
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() :size(0), count(101, 0)
	{

	}

	void addNum(int num) {
		++count[num];
		++size;
	}

	double findMedian()
	{
		int cnt = 0, tmp = 0;
		for (int i = 0; i <= 100; ++i)
		{
			for (int j = 0; j<count[i]; ++j)
			{
				++cnt;
				if (cnt == size / 2)
				{
					if (!(size & 0x1))
					{
						tmp = i;
					}
				}
				if (cnt == size / 2 + 1)
				{
					if (size & 0x1)
					{
						return i;
					}
					else
					{
						return (i + tmp) / 2.0;
					}
				}
			}
		}
		return -1;
	}
private:
	vector<int> count;
	int size;
};

//follow up2
//感觉不需要桶，统计一下不在范围内有多少数字，反正中位数肯定在99%的0~100区间内
//如果 99 % 99 % 的数都在[0, 100]的范围内，我们对于小于0和大于100这两种情况分别开一个桶来记录出现的
//所有数并保持桶内有序，这里可以用平衡树或者有序数组来实现，插入这两个桶的时候我们需要维护桶内有序的
//性质，对于[0, 100]之间的跟第一个follow - up一样，同样的返回中位数的时候我们需要判断一下中位数落在
//哪个范围。