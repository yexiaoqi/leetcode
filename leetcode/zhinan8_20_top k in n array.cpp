//O（nlogn）复杂度
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include <memory>
#include<time.h>
#include<queue>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<limits.h>
#include<math.h>
#include<sstream>
#include<stack>
using namespace std;
int main()
{
	int T, K;
	cin >> T >> K;
	priority_queue<int, vector<int>> q;
	for (int i = 0; i<T; ++i)
	{
		int N;
		cin >> N;
		for (int j = 0; j<N; ++j)
		{
			int tmp;
			cin >> tmp;
			q.push(tmp);
		}
	}
	for (int i = 0; i<K; ++i)
	{
		cout << q.top() << " ";
		q.pop();
	}
	return 0;
}


//牛客自测用例通过但整体通不过
//时间复杂度为O(klogk)，空间复杂度为O(klogk)
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include <memory>
#include<time.h>
#include<queue>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<limits.h>
#include<math.h>
#include<sstream>
#include<stack>
using namespace std;
struct HeapNode
{
	int value;
	int arrNum;
	int index;
	HeapNode(int v, int ai, int i) :value(v), arrNum(ai), index(i) {}
};

void swap(vector<HeapNode*> &heap, int index1, int index2)
{
	HeapNode *tempHeapNode = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = tempHeapNode;
}
void insertHeap(vector<HeapNode*> &heap, int index)
{
	while (index != 0) 
	{
		if ((*heap[(index - 1) / 2]).value<(*heap[index]).value) 
		{
			swap(heap, (index - 1) / 2, index);
		}
		else 
		{
			break;
		}
	}
}

void heapify(vector<HeapNode*> &heapnodes, int i, int len)//这个和下面的heapify写法都行
{
	for (int k = 2 * i + 1; k < len; k = 2 * k + 1)
	{
		if (k + 1 < len && (*heapnodes[k]).value < (*heapnodes[k+1]).value)
		{
			k++;
		}
		if ((*heapnodes[i]).value < (*heapnodes[k]).value)
		{
			swap(heapnodes, k, i);
		}
		else
		{
			break;
		}
	}
}

//void heapify(vector<HeapNode*> &heapNodes, int index, int heapSize) 
//{
//	int largest = index;
//	int left = index * 2 + 1;
//	int right = index * 2 + 2;
//	while (left<heapSize) {
//		if ((*heapNodes[index]).value<(*heapNodes[left]).value) 
//		{
//			largest = left;
//			if (right<heapSize && (*heapNodes[left]).value<(*heapNodes[right]).value) 
//			{
//				largest = right;
//			}
//		}
//		else
//		{
//			if (right<heapSize && (*heapNodes[index]).value<(*heapNodes[right]).value) 
//			{
//				largest = right;
//			}
//		}
//		if (largest != index) 
//		{
//			swap(heapNodes, largest, index);
//		}
//		else 
//		{
//			break;
//		}
//		index = largest;
//		left = index * 2 + 1;
//		right = index * 2 + 2;
//	}
//}

int main()
{
	int T, topK;
	cin >> T >> topK;
	vector<vector<int>> matrix(T);
	vector<HeapNode*> heapNodes(T);
	for (int i = 0; i<T; ++i)
	{
		int N;
		cin >> N;
		for (int j = 0; j<N; ++j)
		{
			int tmp;
			cin >> tmp;
			matrix[i].push_back(tmp);
		}
	}
	int heapSize = matrix.size();
	for (int i = 0; i < heapSize; i++) 
	{
		heapNodes[i] = new HeapNode(matrix[i][matrix[i].size() - 1], i, matrix[i].size() - 1);
		insertHeap(heapNodes, i);
	}
	for (int i = 0; i < topK; i++) 
	{
		if (heapSize == 0) {
			break;
		}
		cout << (*heapNodes[0]).value << " ";
		if ((*heapNodes[0]).index != 0)
		{
			heapNodes[0] = new HeapNode(matrix[(*heapNodes[0]).arrNum][(*heapNodes[0]).index - 1], (*heapNodes[0]).arrNum, (*heapNodes[0]).index - 1);
		}
		else {
			swap(heapNodes, 0, --heapSize);
		}
		heapify(heapNodes, 0, heapSize);
	}
}
