//时间复杂度: O(N),空间复杂度O（1）
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	if (str[k] >= 'a'&&str[k] <= 'z')
	{
		int i = k - 1;
		int cnt = 0;
		while (i >= 0 && str[i] >= 'A'&&str[i] <= 'Z')
		{
			--i;
			++cnt;
		}
		if (cnt & 0x1)
		{
			cout << str.substr(k - 1, 2);
			return 0;
		}
		else
		{
			cout << str[k];
			return 0;
		}
	}
	else
	{
		int i = k - 1;
		int cnt = 0;
		while (i >= 0 && str[i] >= 'A'&&str[i] <= 'Z')
		{
			--i;
			++cnt;
		}
		if (cnt & 0x1)
		{
			cout << str.substr(k - 1, 2);
			return 0;
		}
		else
		{
			cout << str.substr(k, 2);
			return 0;
		}
	}

}