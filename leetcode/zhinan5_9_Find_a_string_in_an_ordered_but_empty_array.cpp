//https://www.nowcoder.com/practice/92c172ef7c6d4ccc8f3103c3bc36cae2?tpId=101&tqId=33167&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
//时间复杂度O（log _{2}n）O（log 2​n）, 额外空间复杂度O（1）
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	vector<string> words(n);
	for (int i = 0; i<n; ++i)
	{
		cin >> words[i];
	}
	if (str == "")
	{
		for (int i = 0; i<n; ++i)
		{
			if (words[i] == str)
			{
				cout << i;
				return 0;
			}
		}
	}
	int begin = 0, end = n - 1;
	int res = INT_MAX;
	while (begin <= end)//注意=
	{
		int mid = (begin + end) / 2;
		if (words[mid] == str)
		{
			res = mid;
			end = mid - 1;
		}
		else if (words[mid] == "0")
		{
			int tmp = mid - 1;
			while (tmp >= 0 && words[tmp] == "0")
			{
				--tmp;
			}
			if (tmp<0)
			{
				begin = mid + 1;
			}
			else
			{
				if (words[tmp] == str)
				{
					res = tmp;
					end = mid - 1;
				}
				else if (words[tmp]<str)
				{
					begin = mid + 1;
				}
				else
				{
					end = tmp - 1;
				}
			}
		}
		else
		{
			if (words[mid]<str)
			{
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
	}
	if (res == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	cout << res;
	return 0;
}








#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n <= 0)
	{
		cout << -1;
		return 0;
	}
	string str;
	cin >> str;
	vector<string> strs(n, "");
	for (int i = 0; i<n; ++i)
	{
		cin >> strs[i];
	}
	int res = INT_MAX;
	int begin = 0, end = n - 1;
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		if (strs[mid] == str)
		{
			res = mid;
			end = mid - 1;
		}
		else if (strs[mid] != "0"&&strs[mid] != str)
		{
			if (strs[mid]<str)
			{
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		else if (strs[mid] == "0"&&strs[mid] != str)
		{
			int tmp = mid;
			while (tmp >= 0 && strs[tmp] == "0")
			{
				--tmp;
			}
			if (tmp<0)
			{
				begin = mid + 1;
			}
			else
			{
				if (strs[tmp] == str)
				{
					res = tmp;
					end = tmp - 1;
				}
				else if (strs[tmp]<str)
				{
					begin = mid + 1;
				}
				else
				{
					end = tmp - 1;
				}
			}
		}
	}
	if (res == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << res;
	}
	return 0;
}