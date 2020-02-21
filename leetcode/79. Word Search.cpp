//同剑指offer 12
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return word == "" ? true : false;
		}
		bool res = false;
		vector<vector<int>> marker(board.size(), vector<int>(board[0].size(), 0));
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				if (find(board, word, marker, 0, i, j, res))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool find(vector<vector<char>>& board, string word, vector<vector<int>> &marker, int pos,
		int x, int y, bool &res)
	{
		if (pos == word.size())
		{
			return true;
		}
		//bool res=false;
		if (x<0 || x >= board.size() || y<0 || y >= board[0].size())
		{
			return false;
		}
		if (board[x][y] == word[pos] && marker[x][y] == 0)
		{
			marker[x][y] = 1;
			++pos;
			res = find(board, word, marker, pos, x + 1, y, res)
				|| find(board, word, marker, pos, x - 1, y, res)
				|| find(board, word, marker, pos, x, y + 1, res)
				|| find(board, word, marker, pos, x, y - 1, res);
			if (!res)
			{
				marker[x][y] = 0;
				--pos;
			}
		}
		return res;


		// marker[x][y]=1;
		// int dx[4]={1,-1,0,0};
		// int dy[4]={0,0,1,-1};
		// for(int i=0;i<4;++i)
		// {
		//     int newx=x+dx[i];
		//     int newy=y+dy[i];
		//     if(newx<0||newx>=board.size()||newy<0||newy>=board[0].size())
		//     {
		//         continue;
		//     }
		//     if(marker[newx][newy]==0)
		//     {
		//         find(board,word,marker,one,newx,newy);
		//     }
		// }
	}
};



//复习
//这样写超出内存限制了
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return word.size() == 0;
		}
		if (word.size() == 0)
		{
			return true;
		}

		bool judge = false;
		int index = 0;
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				vector<vector<int>> marker(board.size(), vector<int>(board[0].size(), 0));
				if (ExistWord(board, word, marker, i, j, judge, index))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool ExistWord(vector<vector<char>> &board, string word, vector<vector<int>> &marker, int i, int j, bool &judge, int index)//vector<vector<int>> &marker如果不加&，虽然就不用再后面变回marker[i][j] = 0;，但是内存超了
	{
		// if(index==word.size())
		// {
		//     return true;
		// }
		// if (i<0 || i >= board.size() || j<0 || j >= board[0].size())
		// {
		//     return false;
		// }
		// if (board[i][j] == word[index] && marker[i][j] == 0)
		// {
		// 	marker[i][j] = 1;
		// 	++index;
		// 	judge = ExistWord(board, word, marker,  i + 1, j, judge,index)
		// 		|| ExistWord(board, word, marker,  i - 1, j, judge,index)
		// 		|| ExistWord(board, word, marker,  i, j + 1, judge,index)
		// 		|| ExistWord(board, word, marker,  i, j - 1, judge,index);
		// 	if (!judge)
		// 	{
		// 		marker[i][j] = 0;
		// 		--index;
		// 	}
		// }
		// return judge;
		marker[i][j] = 1;
		int dx[4] = { 0,0,1,-1 };
		int dy[4] = { 1,-1,0,0 };

		if (board[i][j] != word[index])
		{
			if (!judge)
			{
				marker[i][j] = 0;
			}
			return false;
		}
		++index;
		if (index == word.size())
		{
			return true;
		}
		for (int k = 0; k<4; ++k)
		{
			int newx = i + dx[k];
			int newy = j + dy[k];
			if (newx<0 || newx >= board.size() || newy<0 || newy >= board[0].size())
			{
				continue;
			}
			if (marker[newx][newy])
			{
				continue;
			}

			judge = ExistWord(board, word, marker, newx, newy, judge, index);
			if (!judge)
			{
				marker[newx][newy] = 0;
			}
			if (judge)
			{
				return true;
			}
		}

		return judge;
	}
};


//正确
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return word.size() == 0;
		}
		if (word.size() == 0)
		{
			return true;
		}
		vector<vector<int>> marker(board.size(), vector<int>(board[0].size(), 0));
		bool judge = false;
		int index = 0;
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				if (ExistWord(board, word, marker, i, j, judge, index))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool ExistWord(vector<vector<char>> &board, string word, vector<vector<int>> &marker, int i, int j, bool &judge, int index)
	{
		if (index == word.size())
		{
			return true;
		}
		if (i<0 || i >= board.size() || j<0 || j >= board[0].size())
		{
			return false;
		}
		if (board[i][j] == word[index] && marker[i][j] == 0)
		{
			marker[i][j] = 1;
			++index;
			judge = ExistWord(board, word, marker, i + 1, j, judge, index) ||
				ExistWord(board, word, marker, i - 1, j, judge, index) ||
				ExistWord(board, word, marker, i, j + 1, judge, index) ||
				ExistWord(board, word, marker, i, j - 1, judge, index);/*比如[
																	   ['A','B','C','E'],
																	   ['S','C','C','S'],
																	   ['A','D','E','E']
																	   ]找ABCD，然后AB横向的C遍历周围BCE发现没有对的juege为false，就应该把横向这个C的marker赋成0，index--*/
			if (!judge)
			{
				marker[i][j] = 0;
				--index;
			}
		}
		return judge;
	}
};