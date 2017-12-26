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
					int num = board[i][j] - '0' - 1;//��Ϊ������1~9����row��col��box�Ǵ�0��ʼ�������ټ�ȥ1������˵������1ӳ��0��������9ӳ��8
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