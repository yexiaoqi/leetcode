class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return;
		}
		int dx[8] = { -1,0,1,-1,1,-1,0,1 };
		int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				int cnt = 0;
				for (int k = 0; k<8; ++k)
				{
					int newi = i + dx[k];
					int newj = j + dy[k];
					if (newi<0 || newi >= board.size() || newj<0 || newj >= board[0].size())
					{
						continue;
					}
					if (board[newi][newj] == 1 || board[newi][newj] == 2)
					{
						++cnt;;
					}
				}
				if (board[i][j] && (cnt<2 || cnt>3))
				{
					board[i][j] = 2;
				}
				else if (!board[i][j] && cnt == 3)
				{
					board[i][j] = 3;
				}
			}
		}
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				board[i][j] %= 2;
			}
		}
	}
};