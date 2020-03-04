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


//复习
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
		{
			return 0;
		}
		vector<vector<int>> marker(grid.size(), vector<int>(grid[0].size(), 0));
		int res = 0;
		for (int i = 0; i<grid.size(); ++i)
		{
			for (int j = 0; j<grid[0].size(); ++j)
			{
				if (grid[i][j] == '1'&&marker[i][j] == 0)
				{
					DFS(grid, marker, i, j);
					++res;//每一次DFS都把一块独立岛屿的地遍历一遍
				}
			}
		}
		return res;
	}
	//这个DFS不需要返回值，只要把marker传到就行
	void DFS(vector<vector<char>>& grid, vector<vector<int>>& marker, int x, int y)
	{
		marker[x][y] = 1;
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };
		for (int i = 0; i<4; ++i)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx<0 || newx >= grid.size() || newy<0 || newy >= grid[0].size())
			{
				continue;
			}
			if (grid[newx][newy] == '1'&&marker[newx][newy] == 0)
			{
				DFS(grid, marker, newx, newy);
			}
		}
	}
};


class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
		{
			return 0;
		}
		vector<vector<int>> marker(grid.size(), vector<int>(grid[0].size(), 0));
		int res = 0;
		for (int i = 0; i<grid.size(); ++i)
		{
			for (int j = 0; j<grid[0].size(); ++j)
			{
				if (grid[i][j] == '1'&&marker[i][j] == 0)
				{
					BFS(grid, marker, i, j);
					++res;//每一次DFS都把一块独立岛屿的地遍历一遍
				}
			}
		}
		return res;
	}
	void BFS(vector<vector<char>>& grid, vector<vector<int>> &marker, int x, int y)
	{
		//queue<char> q;
		queue<pair<int, int>> q;
		//q.push(grid[x][y]);
		q.push(make_pair(x, y));
		marker[x][y] = 1;
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };
		while (!q.empty())
		{
			x = q.front().first;
			y = q.front().second;//更新x和y，如果q里面不是存x和y就无法更新了
								 //char ch=q.front();
			q.pop();
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
					//q.push(grid[newx][newy]);
					q.push(make_pair(newx, newy));
					marker[newx][newy] = 1;//要有这一行，它不像dfs会递归到上面marker[x][y]=1;
				}
			}
		}
	}
};

//复习
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
		{
			return 0;
		}
		vector<vector<int>> marker(grid.size(), vector<int>(grid[0].size(), 0));
		int res = 0;
		for (int i = 0; i<grid.size(); ++i)
		{
			for (int j = 0; j<grid[0].size(); ++j)
			{
				if (grid[i][j] == '1'&&marker[i][j] == 0)
				{
					FindIslands(grid, marker, i, j);
					++res;
				}
			}
		}
		return res;
	}
	void FindIslands(vector<vector<char>> &grid, vector<vector<int>> &marker, int x, int y)
	{
		marker[x][y] = 1;
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };
		for (int i = 0; i<4; ++i)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx<0 || newy<0 || newx >= grid.size() || newy >= grid[0].size())
			{
				continue;
			}
			if (grid[newx][newy] == '1'&&marker[newx][newy] == 0)
			{
				FindIslands(grid, marker, newx, newy);
			}
		}
		//marker[x][y]=0;//它不要遍历路径，不能再赋值为0，否则有几个1，res就是及了
	}
};

//复习
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
		{
			return 0;
		}
		vector<vector<int>> marker(grid.size(), vector<int>(grid[0].size(), 0));
		int res = 0;
		for (int i = 0; i<grid.size(); ++i)
		{
			for (int j = 0; j<grid[0].size(); ++j)
			{
				if (grid[i][j] == '1'&&marker[i][j] == 0)
				{
					FindIslands(grid, marker, i, j);
					++res;
				}
			}
		}
		return res;
	}
	void FindIslands(vector<vector<char>> &grid, vector<vector<int>> &marker, int x, int y)
	{
		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		marker[x][y] = 1;
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int dx[4] = { 1,-1,0,0 };
			int dy[4] = { 0,0,1,-1 };
			for (int i = 0; i<4; ++i)
			{
				int newx = x + dx[i];
				int newy = y + dy[i];
				if (newx<0 || newx >= grid.size() || newy<0 || newy >= grid[0].size())
				{
					continue;
				}
				if (grid[newx][newy] == '1'&&marker[newx][newy] == 0)
				{
					q.push(make_pair(newx, newy));
					marker[newx][newy] = 1;
				}
			}
		}
	}
};