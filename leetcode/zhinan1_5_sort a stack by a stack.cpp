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
	int N;
	cin >> N;
	stack<int> s;
	for (int i = 0; i<N; ++i)
	{
		int tmp;
		cin >> tmp;
		s.push(tmp);
	}
	stack<int> help;
	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		while (!help.empty() && cur>help.top())
		{
			int tmp = help.top();
			help.pop();
			s.push(tmp);
		}
		help.push(cur);
	}
	while (!help.empty())
	{
		s.push(help.top());
		help.pop();
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}