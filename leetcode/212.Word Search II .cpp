//这样会超出时间限制
class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return vector<string>();
		}
		vector<string> res;

		for (int k = 0; k<words.size(); ++k)
		{
			vector<vector<int>> marker(board.size(), vector<int>(board[0].size(), 0));
			bool judge = false;
			for (int i = 0; i<board.size(); ++i)
			{
				for (int j = 0; j<board[0].size(); ++j)
				{
					if (Find(board, marker, 0, words[k], i, j))
					{
						judge = true;
						res.push_back(words[k]);
						break;//防止重复
					}
				}
				if (judge)
				{
					break;//防止重复
				}
			}
		}
		return res;
	}
	bool Find(vector<vector<char>> &board, vector<vector<int>> &marker, int pos, string word, int x, int y)
	{
		if (pos == word.size())
		{
			return true;
		}
		if (x<0 || x >= board.size() || y<0 || y >= board[0].size())
		{
			//continue;
			return false;
		}
		bool judge = false;
		if (board[x][y] == word[pos] && marker[x][y] == 0)
		{
			marker[x][y] = 1;
			judge = Find(board, marker, pos + 1, word, x + 1, y) ||
				Find(board, marker, pos + 1, word, x - 1, y) ||
				Find(board, marker, pos + 1, word, x, y + 1) ||
				Find(board, marker, pos + 1, word, x, y - 1);
			marker[x][y] = 0;
		}
		return judge;
	}
};


//正确方法，用字典树
class TrieNode
{
public:
	string str;
	TrieNode *child[26];
	TrieNode() :str("")
	{
		for (int i = 0; i<26; ++i)
		{
			child[i] = NULL;
		}
	}
};
class Trie {
public:
	TrieNode *root;
	Trie()
	{
		root = new TrieNode();
	}
	void insert(string word) {
		TrieNode *p = root;
		for (int i = 0; i<word.size(); ++i)
		{
			int j = word[i] - 'a';
			if (!p->child[j])
			{
				p->child[j] = new TrieNode();
			}
			p = p->child[j];
		}
		p->str = word;
	}
};
class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return vector<string>();
		}
		vector<string> res;
		vector<vector<int>> marker(board.size(), vector<int>(board[0].size(), 0));
		Trie* T = new Trie();
		for (int i = 0; i<words.size(); ++i)
		{
			T->insert(words[i]);
		}
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[i].size(); ++j)
			{
				if (T->root->child[board[i][j] - 'a'])
				{
					Find(board, marker, T->root->child[board[i][j] - 'a'], res, i, j);
				}
			}
		}
		return res;
	}
	void Find(vector<vector<char>> &board, vector<vector<int>> &marker, TrieNode* p, vector<string> &res, int x, int y)
	{
		if (!p->str.empty())
		{
			res.push_back(p->str);
			p->str.clear();
			//return;//这里不能加return，不是找到一个就完事了
		}
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
			if (p->child[board[newx][newy] - 'a'] && marker[newx][newy] == 0)
			{
				Find(board, marker, p->child[board[newx][newy] - 'a'], res, newx, newy);
			}
		}
		marker[x][y] = 0;
	}
};