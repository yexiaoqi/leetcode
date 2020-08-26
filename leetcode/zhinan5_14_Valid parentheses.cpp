//‘≠Ã‚
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
using namespace std;
int main()
{
	int left = 0, right = 0;
	string str;
	cin >> str;
	for (int i = 0; i<str.size(); ++i)
	{
		if (str[i] != '('&&str[i] != ')')
		{
			cout << "NO";
			return 0;
		}
		else if (str[i] == '(')
		{
			++left;
		}
		else
		{
			if (left <= right)
			{
				cout << "NO";
				return 0;
			}
			++right;
		}
	}
	if (left == right)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}


//Ω¯Ω◊
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
using namespace std;
int main()
{
	string str;
	cin >> str;
	int n = str.size();
	vector<int> dp(n);
	int res = 0;
	for (int i = 1; i<n; ++i)
	{
		if (str[i] == ')')
		{
			int pre = i - dp[i - 1] - 1;
			if (pre >= 0 && str[pre] == '(')
			{
				dp[i] = dp[i - 1] + 2;
				if (pre - 1 >= 0)
				{
					dp[i] += dp[pre - 1];
				}
			}
		}
		if (res<dp[i])
		{
			res = dp[i];
		}
	}
	cout << res;
	return 0;
}