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
				//3 * (i / 3) + j / 3要得到它是代表第几个3*3宫格，计数从0开始
//（i / 3，j / 3）代表在9*9宫格内的位置，比如i=7,j=8,是3*3宫格内（2,2）位置（从（0,0）开始，那么2*3+2就是位置数，也就是第八个3*3宫格
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
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_map<string, int> m;
		for (int i = 0; i<9; ++i)
		{
			for (int j = 0; j<9; ++j)
			{
				if (board[i][j] == '.')
				{
					continue;
				}
				string t = "(" + to_string(board[i][j]) + ")";//注意board[i][j]要从char转化为string
				string row = to_string(i) + t, col = t + to_string(j), squ = to_string(i / 3) + t + to_string(j / 3);
				if (m.count(row) || m.count(col) || m.count(squ))
				{
					return false;
				}
				++m[row];
				++m[col];
				++m[squ];
			}
		}
		return true;
	}
};



//复习
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> row(9, vector<bool>(9, 0));
		vector<vector<bool>> col(9, vector<bool>(9, 0));
		vector<vector<bool>> squ(9, vector<bool>(9, 0));
		for (int i = 0; i<9; ++i)
		{
			for (int j = 0; j<9; ++j)
			{
				if (board[i][j] == '.')
				{
					continue;
				}
				int num = board[i][j] - '1';
				if (row[i][num] || col[num][j] || squ[3 * (i / 3) + j / 3][num])
				{
					return false;
				}
				row[i][num] = true;
				col[num][j] = true;
				squ[3 * (i / 3) + j / 3][num] = true;
			}
		}
		return true;
	}
};

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_map<string, int> m;
		for (int i = 0; i<9; ++i)
		{
			for (int j = 0; j<9; ++j)
			{
				if (board[i][j] == '.')
				{
					continue;
				}
				string t = "(" + to_string(board[i][j]) + ")";//注意board[i][j]要从char转化为string
				string row = to_string(i) + t, col = t + to_string(j), squ = to_string(i / 3) + t + to_string(j / 3);
				if (m.count(row) || m.count(col) || m.count(squ))
				{
					return false;
				}
				++m[row];
				++m[col];
				++m[squ];
			}
		}
		return true;
	}
};

//复习
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> row(9, vector<bool>(9, false));
		vector<vector<bool>> col(9, vector<bool>(9, false));
		vector<vector<bool>> squ(9, vector<bool>(9, false));
		for (int i = 0; i<9; ++i)
		{
			for (int j = 0; j<9; ++j)
			{
				if (board[i][j] != '.')
				{
					int num = board[i][j] - '1';
					if (row[i][num] || col[j][num] || squ[i / 3 * 3 + j / 3][num])
					{
						return false;
					}
					row[i][num] = true;
					col[j][num] = true;
					squ[i / 3 * 3 + j / 3][num] = true;
				}

			}
		}
		return true;
	}
};

//复习
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_set<string> us;
		for (int i = 0; i<9; ++i)
		{
			for (int j = 0; j<9; ++j)
			{
				if (board[i][j] != '.')
				{
					string t = '(' + to_string(board[i][j]) + ')';
					string row = to_string(i) + t, col = t + to_string(j), squ = to_string(i / 3) + t + to_string(j / 3);
					if (us.count(row) || us.count(col) || us.count(squ))
					{
						return false;
					}
					us.insert(row);
					us.insert(col);
					us.insert(squ);
				}
			}
		}
		return true;
	}
};