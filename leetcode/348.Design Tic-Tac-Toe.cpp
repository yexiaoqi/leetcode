class TicTacToe {
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) :grid(n, vector<int>(n, 0))
	{

	}

	/** Player {player} makes a move at ({row}, {col}).
	@param row The row of the board.
	@param col The column of the board.
	@param player The player, can be either 1 or 2.
	@return The current winning condition, can be either:
	0: No one wins.
	1: Player 1 wins.
	2: Player 2 wins. */
	int move(int row, int col, int player) {
		int i = 0, j = 0, n = grid.size();
		grid[row][col] = player;
		for (; i<n; ++i)
		{
			if (grid[i][col] != player)
			{
				break;
			}
		}
		if (i == n)
		{
			return player;
		}
		for (; j<n; ++j)
		{
			if (grid[row][j] != player)
			{
				break;
			}
		}
		if (j == n)
		{
			return player;
		}
		if (row == col)
		{
			for (i = 0; i<n; ++i)
			{
				if (grid[i][i] != player)
				{
					break;
				}
			}
		}
		if (i == n)
		{
			return player;
		}
		if (row + col == n - 1)
		{
			for (i = 0; i<n; ++i)
			{
				if (grid[i][n - 1 - i] != player)
				{
					break;
				}
			}
		}
		if (i == n)
		{
			return player;
		}
		return 0;
	}
private:
	vector<vector<int>> grid;
};

/**
* Your TicTacToe object will be instantiated and called as such:
* TicTacToe* obj = new TicTacToe(n);
* int param_1 = obj->move(row,col,player);
*/


//���õķ���
//���ǽ���һ����СΪn��һά����rows��cols�����б����Խ���diag����Խ���rev_diag��
//���ַ�����˼·�ǣ�������1�ڵ�һ��ĳһ�з���һ���ӣ���ôrows[0]����1��
//������2�ڵ�һ��ĳһ�з���һ���ӣ���rows[0]�Լ�1����ôֻ�е�rows[0]����n���� - n��ʱ��
//��ʾ��һ�е��Ӷ���һ����ҷŵģ�����Ϸ�������ظ���Ҽ��ɣ��������и��У��Խ��ߺ���Խ��߶�������˼·
class TicTacToe {
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) :rows(n, 0), cols(n, 0), diag(0), rediag(0)
	{

	}

	/** Player {player} makes a move at ({row}, {col}).
	@param row The row of the board.
	@param col The column of the board.
	@param player The player, can be either 1 or 2.
	@return The current winning condition, can be either:
	0: No one wins.
	1: Player 1 wins.
	2: Player 2 wins. */
	int move(int row, int col, int player) {
		int add = player == 1 ? 1 : -1;
		int n = rows.size();
		rows[row] += add;
		cols[col] += add;
		diag += (row == col ? add : 0);
		rediag += (row + col == n - 1 ? add : 0);
		if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diag) == n || abs(rediag) == n)
		{
			return player;
		}
		return 0;
	}
private:
	vector<int> rows;
	vector<int> cols;
	int diag, rediag;
};

/**