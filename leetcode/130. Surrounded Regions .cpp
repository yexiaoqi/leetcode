//自己做出
//DFS
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return;
		}
		int size = board.size();
		int size2 = board[0].size();
		vector<vector<int>> marker(size, vector<int>(size2, 0));
		for (int j = 0; j<size2; ++j)
		{
			if (board[0][j] == 'O')
			{
				DFS(board, marker, 0, j);
			}
			if (size>1 && board[size - 1][j] == 'O')
			{
				DFS(board, marker, size - 1, j);
			}

		}
		for (int i = 1; i<size - 1; ++i)
		{
			if (board[i][0] == 'O')
			{
				DFS(board, marker, i, 0);
			}
			if (size2>1 && board[i][size2 - 1] == 'O')
			{
				DFS(board, marker, i, size2 - 1);
			}
		}
		for (int i = 0; i<size; ++i)
		{
			for (int j = 0; j<size2; ++j)
			{
				if (board[i][j] == 'O'&&marker[i][j] == 0)
				{
					board[i][j] = 'X';
				}
			}
		}
	}
	void DFS(vector<vector<char>>& board, vector<vector<int>>& marker, int x, int y)
	{
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };
		marker[x][y] = 1;
		for (int i = 0; i<4; ++i)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx<0 || newx >= board.size() || newy<0 || newy >= board[0].size())
			{
				continue;
			}
			if (board[newx][newy] == 'O'&&marker[newx][newy] == 0)
			{
				DFS(board, marker, newx, newy);
			}
		}
	}
};

//自己做出，BFS
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return;
		}
		int size = board.size();
		int size2 = board[0].size();
		vector<vector<int>> marker(size, vector<int>(size2, 0));
		for (int j = 0; j<size2; ++j)
		{
			if (board[0][j] == 'O')
			{
				BFS(board, marker, 0, j);
			}
			if (size>1 && board[size - 1][j] == 'O')
			{
				BFS(board, marker, size - 1, j);
			}

		}
		for (int i = 1; i<size - 1; ++i)
		{
			if (board[i][0] == 'O')
			{
				BFS(board, marker, i, 0);
			}
			if (size2>1 && board[i][size2 - 1] == 'O')
			{
				BFS(board, marker, i, size2 - 1);
			}
		}
		for (int i = 0; i<size; ++i)
		{
			for (int j = 0; j<size2; ++j)
			{
				if (board[i][j] == 'O'&&marker[i][j] == 0)
				{
					board[i][j] = 'X';
				}
			}
		}
	}
	void BFS(vector<vector<char>>& board, vector<vector<int>>& marker, int x, int y)
	{
		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		while (!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			marker[x][y] = 1;
			q.pop();
			int dx[4] = { 1,-1,0,0 };
			int dy[4] = { 0,0,1,-1 };
			for (int i = 0; i<4; ++i)
			{
				int newx = x + dx[i];
				int newy = y + dy[i];
				if (newx<0 || newx >= board.size() || newy<0 || newy >= board[0].size())
				{
					continue;
				}
				if (board[newx][newy] == 'O'&&marker[newx][newy] == 0)
				{
					q.push(make_pair(newx, newy));
					marker[newx][newy] = 1;
				}
			}
		}
	}
};
