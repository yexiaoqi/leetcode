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
using namespace std;

int main()
{
	string str;
	cin >> str;
	if (str.size() == 0)
	{
		cout << "";
		return 0;
	}
	string res = "";
	char ch = str[0];
	int end = str.size() - 1;
	int cnt = 1;
	for (int i = 1; i<str.size(); ++i)
	{
		if (str[i] == str[i - 1])
		{
			++cnt;
		}
		else
		{
			res = res + str[i - 1] + "_" + to_string(cnt) + "_";
			cnt = 1;
		}
	}
	res = res + str[end] + "_" + to_string(cnt);
	cout << res;
	return 0;
}