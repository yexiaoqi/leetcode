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