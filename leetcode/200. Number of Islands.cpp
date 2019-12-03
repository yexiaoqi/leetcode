//DFS
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (int(grid.size()) == 0)
		{
			return 0;
		}//要加入这个，否则如果grid为空，则没有grid[0]，直接下面int(grid[0].size()会报错
		vector<vector<int>> marker(int(grid.size()), (vector<int>(int(grid[0].size()), 0)));
		int res = 0;
		for (int i = 0; i<int(grid.size()); ++i)
		{
			for (int j = 0; j<int(grid[i].size()); ++j)
			{
				if (grid[i][j] == '1'&&marker[i][j] == 0)
				{
					DFS(i, j, grid, marker);
					++res;
				}
			}
		}
		return res;
	}
	void DFS(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& marker)
	{
		int dx[4] = { 0,0,-1,1 };
		int dy[4] = { 1,-1,0,0 };
		marker[x][y] = 1;
		for (int i = 0; i<4; ++i)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx<0 || newx >= int(grid.size()) || newy<0 || newy >= int(grid[newx].size()))
			{
				continue;
			}
			if (grid[newx][newy] == '1'&&marker[newx][newy] == 0)
			{
				DFS(newx, newy, grid, marker);
			}
		}
	}
};

//BFS，使用队列
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (int(grid.size()) == 0)
		{
			return 0;
		}//要加入这个，否则如果grid为空，则没有grid[0]，直接下面int(grid[0].size()会报错
		vector<vector<int>> marker(int(grid.size()), (vector<int>(int(grid[0].size()), 0)));
		int res = 0;
		for (int i = 0; i<int(grid.size()); ++i)
		{
			for (int j = 0; j<int(grid[i].size()); ++j)
			{
				if (grid[i][j] == '1'&&marker[i][j] == 0)
				{
					BFS(i, j, grid, marker);
					++res;
				}
			}
		}
		return res;
	}
	void BFS(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& marker)
	{
		int dx[4] = { 0,0,-1,1 };
		int dy[4] = { 1,-1,0,0 };
		marker[x][y] = 1;
		queue<pair<int, int>> Q;//pair使用
		Q.push(make_pair(x, y));//pair使用
		while (!Q.empty())
		{
			x = Q.front().first;//pair使用
			y = Q.front().second;//pair使用
			Q.pop();
			for (int i = 0; i<4; ++i)
			{

				int newx = x + dx[i];
				int newy = y + dy[i];
				if (newx<0 || newx >= int(grid.size()) || newy<0 || newy >= int(grid[newx].size()))
				{
					continue;
				}
				if (grid[newx][newy] == '1'&&marker[newx][newy] == 0)
				{
					Q.push(make_pair(newx, newy));
					marker[newx][newy] = 1;
				}
			}
		}

	}
};