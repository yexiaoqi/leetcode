//²»»á
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
void FindAll(vector<vector<char>> &num, vector<vector<int>> &visit, vector<vector<int>> &some, int &cnt, int x, int y)
{
	visit[x][y] = 1;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	for (int i = 0; i<4; ++i)
	{
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (newx<0 || newx >= 6 || newy<0 || newy >= 6)
		{
			continue;
		}
		if (num[newx][newy] != '*'&&visit[newx][newy] == 0)
		{
			for (int j = 0; j<6; ++j)
			{
				if ()
					some[newx][newy] = j;
				visit[newx][newy] = 1;
				FindAll(num, visit, )
			}

		}
	}
}
int main()
{
	vector<vector<char>> num(6, vector<char>(6, '*'));
	for (int i = 0; i<6; ++i)
	{
		for (int j = 0; j<6; ++j)
		{
			cin >> num[i][j];
		}
	}
	vector<vector<int>> visit(6, vector<int>(6, 0));
	vector<vector<int>> some(6, vector<int>(6, 0));
}