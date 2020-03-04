//这样写要运行884ms
//图的方法
class Solution {
public:
	bool connect(string &word1, string &word2)//注意这边传引用，不传引用很慢
	{
		int count = 0;
		for (int i = 0; i<int(word1.length()); ++i)
		{
			if (word1[i] != word2[i])
			{
				++count;
			}
		}
		return count == 1;
	}
	void construct_graph(string &beginWord, vector<string>& wordList, map<string, vector<string>> &gra)
	{
		wordList.push_back(beginWord);
		for (int i = 0; i<int(wordList.size()); ++i)
		{
			gra[wordList[i]] = vector<string>();
		}
		for (int i = 0; i<int(wordList.size()); ++i)
		{
			for (int j = i + 1; j<int(wordList.size()); ++j)
			{
				if (connect(wordList[i], wordList[j]))
				{
					gra[wordList[i]].push_back(wordList[j]);
					gra[wordList[j]].push_back(wordList[i]);
				}
			}
		}

	}
	int BFS(string &beginWord, string &endWord, map<string, vector<string>> &gra)
	{
		set<string> visit;
		queue<pair<string, int>> q;
		q.push(make_pair(beginWord, 1));
		visit.insert(beginWord);
		while (!q.empty())
		{
			string node = q.front().first;
			int step = q.front().second;
			q.pop();
			if (node == endWord)
			{
				return step;
			}
			for (int i = 0; i<(gra[node].size()); ++i)
			{
				if (visit.find(gra[node][i]) == visit.end())
				{
					q.push(make_pair(gra[node][i], step + 1));
					visit.insert(gra[node][i]);
				}
			}
		}
		return 0;
	}
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		map<string, vector<string>> gra;
		construct_graph(beginWord, wordList, gra);
		return BFS(beginWord, endWord, gra);
	}
};



//BFS
//需要一个队列queue，把起始单词排入队列中，开始队列的循环，取出队首词，然后对其每个位置上的字符，
//用26个字母进行替换，如果此时和结尾单词相同了，就可以返回取出词在哈希表中的值加一。
//如果替换词在字典中存在但在哈希表中不存在，则将替换词排入队列中，并在哈希表中的值映射为之前取出词加一。
//如果循环完成则返回0
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordset(wordList.begin(), wordList.end());
		if (beginWord == endWord)
		{
			return 1;
		}//注意这种情况
		queue<pair<string, int>> q;
		unordered_set<string> marker;
		q.push(make_pair(beginWord, 1));
		marker.insert(beginWord);
		while (!q.empty())
		{
			string word = q.front().first;
			int step = q.front().second;
			q.pop();
			for (int i = 0; i<beginWord.size(); ++i)
			{
				string newword = word;
				for (char a = 'a'; a <= 'z'; ++a)
				{
					newword[i] = a;
					if (wordset.count(newword))
					{
						if (newword == endWord)
						{
							return step + 1;
						}
						if (!marker.count(newword))
						{
							q.push(make_pair(newword, step + 1));
							marker.insert(newword);
						}
					}
				}
			}

		}
		return 0;
	}
};




//下面这样写，由于leetcode测试用例不够能通过，但实际上如果endword和beginword相等，应该返回1，所以下面这样不对
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordset(wordList.begin(), wordList.end());//注意用unordered_set,比set快
		queue<pair<string, int>> q;
		q.push(make_pair(beginWord, 1));
		set<string> visit;
		visit.insert(beginWord);
		while (!q.empty())
		{
			string word = q.front().first;
			int step = q.front().second;
			q.pop();
			/*if (word == endWord)
			{
			return step;
			}*/
			for (int i = 0; i<int(word.length()); ++i)
			{
				string newword = word;
				for (char ch = 'a'; ch <= 'z'; ++ch)
				{
					newword[i] = ch;
					/*if (wordset.count(newword))
					{
					q.push(make_pair(newword, step + 1));
					}*/
					if (wordset.find(newword) != wordset.end())
					{
						if (newword == endWord)
						{
							return step + 1;
						}
						if (visit.find(newword) == visit.end())
						{
							q.push(make_pair(newword, step + 1));
							visit.insert(newword);
						}
					}
				}
			}
		}
		return 0;
	}
};

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordSet(wordList.begin(), wordList.end());
		if (!wordSet.count(endWord)) return 0;
		unordered_map<string, int> pathCnt{ { { beginWord, 1 } } };
		queue<string> q{ { beginWord } };
		while (!q.empty()) {
			string word = q.front(); q.pop();
			for (int i = 0; i < word.size(); ++i) {
				string newWord = word;
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					newWord[i] = ch;
					if (wordSet.count(newWord) && newWord == endWord) return pathCnt[word] + 1;
					if (wordSet.count(newWord) && !pathCnt.count(newWord)) {
						q.push(newWord);
						pathCnt[newWord] = pathCnt[word] + 1;
					}
				}
			}
		}
		return 0;
	}
};


//复习
struct GraphNode
{
	string word;
	string* next;
};
class Solution {
public:
	bool compare(string &word1, string &word2)
	{
		int count = 0;
		for (int i = 0; i<word1.size(); ++i)
		{
			if (word1[i] != word2[i])
			{
				++count;
			}
		}
		if (count == 1)
		{
			return true;
		}
		return false;
	}
	void buildgraph(string &beginWord, vector<string>& wordList, unordered_map<string, vector<string>> &gra)
	{
		wordList.push_back(beginWord);
		for (int i = 0; i<wordList.size(); ++i)
		{
			for (int j = i + 1; j<wordList.size(); ++j)
			{
				if (compare(wordList[i], wordList[j]))
				{
					gra[wordList[i]].push_back(wordList[j]);
					gra[wordList[j]].push_back(wordList[i]);
				}
			}
		}
	}
	int BFS(string &beginWord, string &endWord, map<string, vector<string>> &gra)
	{
		set<string> visit;
		queue<pair<string, int>> q;
		q.push(make_pair(beginWord, 1));
		visit.insert(beginWord);
		while (!q.empty())
		{
			string node = q.front().first;
			int step = q.front().second;
			q.pop();
			if (node == endWord)
			{
				return step;
			}
			for (int i = 0; i<(gra[node].size()); ++i)
			{
				if (visit.find(gra[node][i]) == visit.end())
				{
					q.push(make_pair(gra[node][i], step + 1));
					visit.insert(gra[node][i]);
				}
			}
		}
		return 0;
	}
	int BFS(string &beginWord, string &endWord, unordered_map<string, vector<string>> &gra)
	{
		set<string> visit;
		queue<pair<string, int>> q;
		q.push(make_pair(beginWord, 1));
		visit.insert(beginWord);
		while (!q.empty())
		{
			string node = q.front().first;//队列是front
			int step = q.front().second;
			q.pop();
			if (node == endWord)
			{
				return step;
			}
			for (int i = 0; i<gra[node].size(); ++i)
			{
				if (visit.find(gra[node][i]) == visit.end())
				{
					q.push(make_pair(gra[node][i], step + 1));
					visit.insert(gra[node][i]);
				}
			}
		}
		return 0;
	}
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_map<string, vector<string>> gra;
		buildgraph(beginWord, wordList, gra);
		return BFS(beginWord, endWord, gra);
	}
};