//�Լ�����
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
			minheap.push(maxheap.top());//�Ѷ���top
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

//��΢��
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


//follow up1��ʹ�ü�������
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
//�о�����ҪͰ��ͳ��һ�²��ڷ�Χ���ж������֣�������λ���϶���99%��0~100������
//��� 99 % 99 % ��������[0, 100]�ķ�Χ�ڣ����Ƕ���С��0�ʹ���100����������ֱ�һ��Ͱ����¼���ֵ�
//������������Ͱ���������������ƽ������������������ʵ�֣�����������Ͱ��ʱ��������Ҫά��Ͱ�������
//���ʣ�����[0, 100]֮��ĸ���һ��follow - upһ����ͬ���ķ�����λ����ʱ��������Ҫ�ж�һ����λ������
//�ĸ���Χ��