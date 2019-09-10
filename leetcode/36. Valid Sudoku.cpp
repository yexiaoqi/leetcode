//Determine if a Sudoku is valid, according to : Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//A partially filled sudoku which is valid.
//
//Note :
//	A valid Sudoku board(partially filled) is not necessarily solvable.Only the filled cells need to be validated.

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		bool row[9][9] = { false }, col[9][9] = { false }, box[9][9] = { false };
		for (int i = 0;i<9;++i)
		{
			for (int j = 0;j<9;++j)
			{
				if (board[i][j] != '.')
				{
					int num = board[i][j] - '0' - 1;//因为数独是1~9，而row，col，box是从0开始，所以再减去1，就是说数独的1映射0，数独的9映射8
					int k = i / 3 * 3 + j / 3;
					if (row[i][num] || col[j][num] || box[k][num])
					{
						return false;
					}
					else
					{
						row[i][num] = col[j][num] = box[k][num] = true;
					}
				}
			}
		}
		return true;
	}
};

//https://www.cnblogs.com/grandyang/p/4421217.html
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> row(9, vector<bool>(9));
		vector<vector<bool>> col(9, vector<bool>(9));
		vector<vector<bool>> box(9, vector<bool>(9));
		for (int i = 0; i<9; ++i)
		{
			for (int j = 0; j<9; ++j)
			{
				if (board[i][j] == '.')
				{
					continue;
				}
				int c = board[i][j] - '1';
				if (row[i][c] || col[c][j] || box[3 * (i / 3) + j / 3][c])
				{
					return false;
				}
				row[i][c] = true;
				col[c][j] = true;
				box[3 * (i / 3) + j / 3][c] = true;
			}
		}
		return true;
	}
};