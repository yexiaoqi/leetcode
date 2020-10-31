//时间复杂度O(n),空间复杂度O(n）
//用哈希表

//空间复杂度为O(1)，时间复杂度为0(nlogn）
//类似于下题，下题是数字，书上是字母
//https://www.nowcoder.com/questionTerminal/33376cab7c714d46b0853a985420b977?answerType=1&f=discussion
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
void adjustheap(vector<int> &arr, int i, int len)
{
	int tmp = arr[i];
	for (int k = 2 * i + 1; k < len; k = 2 * k + 1)
	{
		if (k + 1 < len&&arr[k] < arr[k + 1])
		{
			k += 1;
		}
		if (tmp < arr[k])
		{
			arr[i] = arr[k];
			i = k;
		}
		else
		{
			break;
		}
	}
	arr[i] = tmp;
}

void heapsort(vector<int> &arr)
{
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		adjustheap(arr, i, n);
	}
	for (int i = arr.size() - 1; i > 0; --i)
	{
		swap(arr[0], arr[i]);
		adjustheap(arr, 0, i);
	}
}

bool judgeonce(vector<int> &arr)
{
	heapsort(arr);
	for (int i = 1; i < arr.size(); ++i)
	{
		if (arr[i] == arr[i - 1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	bool res = judgeonce(arr);
	if (res)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}








//复习
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void adjustheap(vector<int> &arr, int i, int len)
{
	int tmp = arr[i];
	for (int k = 2 * i + 1; k < len; k = 2 * k + 1)
	{
		if (k + 1 < len&&arr[k] < arr[k + 1])
		{
			k += 1;
		}
		if (tmp < arr[k])
		{
			arr[i] = arr[k];
			i = k;
		}
		else
		{
			break;
		}
	}
	arr[i] = tmp;
}

void heapsort(vector<int> &arr)
{
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		adjustheap(arr, i, n);
	}
	for (int i = n - 1; i>0; --i)
	{
		swap(arr[0], arr[i]);
		adjustheap(arr, 0, i);
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i<n; ++i)
	{
		cin >> arr[i];
	}
	heapsort(arr);
	for (int i = 0; i<n - 1; ++i)
	{
		if (arr[i] == arr[i + 1])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
