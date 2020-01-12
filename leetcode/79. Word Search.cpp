//Í¬½£Ö¸offer 12
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