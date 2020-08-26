#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i<N; ++i)
	{
		cin >> arr[i];
	}
	int begin = 0;
	int i = 0;
	int size = (N + 1) / 2;
	while (i<N)
		//while(i<N&&begin<=size)
	{
		if (arr[i] != arr[begin])
		{
			swap(arr[i++], arr[++begin]);
		}
		else
		{
			i++;
		}
	}
	for (int i = 0; i<N; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}