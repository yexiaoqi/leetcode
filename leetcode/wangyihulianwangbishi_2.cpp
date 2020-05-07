//我宝宝的解法
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void out(char str[], int n) {
	for (int i = 0; i<n; i++) {
		cout << str[i];
	}
	cout << endl;
}

int main()
{
	int n, k;
	int c[10][10];

	for (int i = 0; i<10; i++) {
		for (int j = 0; j<10; j++) {
			c[i][j] = 0;
		}
	}

	cin >> n >> k;

	int a, b;
	for (int i = 0; i<k; i++) {
		cin >> a >> b;
		c[a - 1][b - 1] = 1;
		c[b - 1][a - 1] = 1;
	}

	char str[] = "123456789";

	sort(str, str + n);

	bool flag = true;
	for (int i = 1; i<n; i++) {
		if (c[str[i] - '1'][str[i - 1] - '1'] == 1) {
			flag = false;
			break;
		}
	}
	if (flag) {
		out(str, n);
	}

	while (next_permutation(str, str + n)) {
		flag = true;
		for (int i = 1; i<n; i++) {
			if (c[str[i] - '1'][str[i - 1] - '1'] == 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			out(str, n);
		}
	}
	return 0;
}








//我的解法
void Findsit(vector<int> &path, vector<vector<int>> &res, int n, vector<int> &marker, unordered_map<int, vector<int>> &notwith)
{
	if (path.size() == n)
	{
		res.push_back(path);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (marker[i] == 0)
		{
			if (path.size() != 0 && notwith.find(path.back()) != notwith.end())
			{
				bool flag = false;
				for (int j = 0; j < notwith[path.back()].size(); ++j)
				{
					if (notwith[path.back()][j] == i)
					{
						flag = true;
					}
				}
				if (flag == true)
				{
					continue;
				}
			}
			marker[i] = 1;
			path.push_back(i);
			Findsit(path, res, n, marker, notwith);
			path.pop_back();
			marker[i] = 0;
		}

	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	unordered_map<int, vector<int>> notwith;
	for (int i = 0; i < k; ++i)
	{
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		notwith[tmp.first].push_back(tmp.second);
		notwith[tmp.second].push_back(tmp.first);
	}
	vector<vector<int>> res;
	vector<int> path;
	vector<int> marker(n, 0);
	Findsit(path, res, n, marker, notwith);
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}




