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