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
int GetAndRemove(stack<int> &s)
{
	int res = s.top();
	s.pop();
	if (s.empty())
	{
		return res;
	}
	else
	{
		int last = GetAndRemove(s);
		s.push(res);
		return last;
	}
}
void Rever(stack<int> &s)
{
	if (s.empty())
	{
		return;
	}
	int i = GetAndRemove(s);
	Rever(s);
	s.push(i);
}
int main()
{
	int n;
	cin >> n;
	stack<int> s;
	for (int i = 0; i<n; ++i)
	{
		int tmp;
		cin >> tmp;
		s.push(tmp);
	}
	Rever(s);
	vector<int> res;
	while (!s.empty())
	{
		res.push_back(s.top());
		s.pop();
	}
	for (int i = res.size() - 1; i >= 0; --i)
	{
		cout << res[i] << " ";
	}
	return 0;
}