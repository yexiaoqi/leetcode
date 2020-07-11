//ͬ��ָoffer 12

//�Ƽ���������д���������׳���
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return word.size() == 0 ? true : false;
		}
		vector<vector<int>> marker(board.size(), vector<int>(board[0].size(), 0));
		//vector<char> path;
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				if (exist2(board, marker, word, i, j, 0))
					//if (exist2(board, marker, word, path, i, j, 0))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool exist2(vector<vector<char>>& board, vector<vector<int>> &marker, string word, int i, int j, int pos)
		//bool exist2(vector<vector<char>>& board, vector<vector<int>> &marker, string word, vector<char> &path, int i, int j, int pos)
	{
		if (pos == word.size())
			//if (path.size() == word.size())
		{
			return true;
		}
		if (i<0 || i >= board.size() || j<0 || j >= board[0].size())
		{
			return false;//ע�����ﲻ��ѭ�����Բ���continue
		}
		bool judge = false;
		if (board[i][j] == word[pos] && marker[i][j] == 0)
		{
			marker[i][j] = 1;
			//path.push_back(board[i][j]);
			judge = exist2(board, marker, word, i + 1, j, pos + 1) ||
				exist2(board, marker, word, i - 1, j, pos + 1) ||
				exist2(board, marker, word, i, j + 1, pos + 1) ||
				exist2(board, marker, word, i, j - 1, pos + 1);
			// judge = exist2(board, marker, word, path, i + 1, j, pos + 1) ||
			// 	exist2(board, marker, word, path, i - 1, j, pos + 1) ||
			// 	exist2(board, marker, word, path, i, j + 1, pos + 1) ||
			// 	exist2(board, marker, word, path, i, j - 1, pos + 1);
			//path.pop_back();
			marker[i][j] = 0;
		}
		return judge;
	}
};





//�������path�����������ò�������������dfs���⾭����
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return word.size() == 0 ? true : false;
		}
		vector<vector<int>> marker(board.size(), vector<int>(board[0].size(), 0));
		vector<char> path;
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				if (exist2(board, marker, word, path, i, j, 0))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool exist2(vector<vector<char>>& board, vector<vector<int>> &marker, string word, vector<char> &path, int i, int j, int pos)
	{
		if (path.size() == word.size())
		{
			return true;
		}
		if (i<0 || i >= board.size() || j<0 || j >= board[0].size())
		{
			return false;
		}
		bool judge = false;
		if (board[i][j] == word[pos] && marker[i][j] == 0)
		{
			marker[i][j] = 1;
			path.push_back(board[i][j]);
			judge = exist2(board, marker, word, path, i + 1, j, pos + 1) ||
				exist2(board, marker, word, path, i - 1, j, pos + 1) ||
				exist2(board, marker, word, path, i, j + 1, pos + 1) ||
				exist2(board, marker, word, path, i, j - 1, pos + 1);
			path.pop_back();
			marker[i][j] = 0;
		}
		return judge;
	}
};





//ԭ����д����Ҳ��
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




//����д�����ڴ�������
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return word.size() == 0 ? true : false;
		}
		vector<vector<int>> marker(board.size(), vector<int>(board[0].size(), 0));
		vector<int> res;
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				if (board[i][j] == word[0])
				{
					//if (exist2(board, marker, word,  i, j, 0))
					exist2(board, marker, word, i, j, 0, res);
					if (res.size())
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	bool exist2(vector<vector<char>>& board, vector<vector<int>> &marker, string word, int x, int y, int pos, vector<int> &res)
	{
		if (pos == word.size() - 1)//ע����word.size()-1������ABCCED��pos�Ǵ�0��ʼ�ģ����һλ��5
		{
			res.push_back(1);
			return true;
		}
		bool judge = false;
		marker[x][y] = 1;
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
			if (board[newx][newy] == word[pos + 1] && marker[newx][newy] == 0)
			{
				judge = exist2(board, marker, word, newx, newy, pos + 1, res);
			}
		}
		marker[x][y] = 0;
		return judge;
	}
};

//��ϰ
//����д�����ڴ�������
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
	bool ExistWord(vector<vector<char>> &board, string word, vector<vector<int>> &marker, int i, int j, bool &judge, int index)//vector<vector<int>> &marker�������&����Ȼ�Ͳ����ٺ�����marker[i][j] = 0;�������ڴ泬��
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


//��ȷ
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
				ExistWord(board, word, marker, i, j - 1, judge, index);
			/*����[
				 ['A','B','C','E'],
				 ['S','C','C','S'],
				['A','D','E','E']
				]��ABCD��Ȼ��AB�����C������ΧBCE����û�жԵ�judgeΪfalse����Ӧ�ðѺ������C��marker����0��
				index--*/
			if (!judge)
			{
				marker[i][j] = 0;
				--index;
			}
		}
		return judge;
	}
};


//��ϰ������д����
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return word.size() == 0 ? true : false;
		}
		vector<vector<int>> marker(board.size(), vector<int>(board[0].size(), 0));
		vector<char> path;
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				if (exist2(board, marker, word, path, i, j, 0))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool exist2(vector<vector<char>>& board, vector<vector<int>> &marker, string word, vector<char> &path, int i, int j, int pos)
	{
		if (path.size() == word.size())
		{
			return true;
		}
		if (i<0 || i >= board.size() || j<0 || j >= board[0].size())
		{
			return false;
		}
		bool judge = false;
		if (board[i][j] == word[pos] && marker[i][j] == 0)
		{
			marker[i][j] = 1;
			path.push_back(board[i][j]);
			judge = exist2(board, marker, word, path, i + 1, j, pos + 1) ||
				exist2(board, marker, word, path, i - 1, j, pos + 1) ||
				exist2(board, marker, word, path, i, j + 1, pos + 1) ||
				exist2(board, marker, word, path, i, j - 1, pos + 1);
			path.pop_back();
			marker[i][j] = 0;
		}
		return judge;
	}
};


//���û�ķ���
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return word.size() == 0;
		}
		int m = board.size(), n = board[0].size();
		string path;
		bool judge = false;
		vector<vector<int>> visit(m, vector<int>(n, 0));
		for (int i = 0; i<m; ++i)
		{
			for (int j = 0; j<n; ++j)
			{
				if (visit[i][j] == 0 && board[i][j] == word[0])
				{
					DFS(board, visit, path, 0, i, j, judge, word);
					if (judge)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	void DFS(vector<vector<char>>& board, vector<vector<int>> &visit, string &path, int pos, int x, int y, bool &judge, string word)
	{
		if (path.size() == word.size() - 1)
		{
			if (board[x][y] == word[pos])
			{
				judge = true;
			}
			return;
		}
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };

		visit[x][y] = 1;
		path.push_back(word[pos]);
		for (int i = 0; i<4; ++i)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx<0 || newx >= board.size() || newy<0 || newy >= board[0].size())
			{
				continue;
			}
			if (visit[newx][newy] == 0 && board[newx][newy] == word[pos + 1])
			{
				DFS(board, visit, path, pos + 1, newx, newy, judge, word);
				if (judge)
				{
					break;
				}
			}
		}
		visit[x][y] = 0;
		path.pop_back();

	}
};