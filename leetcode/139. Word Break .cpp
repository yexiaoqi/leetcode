//这样写会超时
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.empty())
		{
			return s.empty() ? true : false;
		}
		set<string> wordset(wordDict.begin(), wordDict.end());
		return wobreak(s, wordset, 0);
	}
	bool wobreak(string s, set<string>& worddict, int start)
	{
		if (start == s.size())
		{
			return true;
		}
		for (int i = start; i<s.size(); ++i)
		{
			string word = s.substr(start, i - start + 1);
			if (worddict.count(word))
			{
				if (wobreak(s, worddict, i + 1))//从最后一层倒推上来，如果最后又true就是true
				{
					return true;
				}
			}
		}
		return false;
	}
};

//正确方法一
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.empty())
		{
			return s.empty() ? true : false;
		}
		set<string> wordset(wordDict.begin(), wordDict.end());
		vector<int> memo(s.size(), -1);
//记忆数组 memo[i] 定义为范围为 [i, n] 的子字符串是否可以拆分，初始化为 -1，表示没有计算过，如果可以拆分，则赋值为1，反之为0。
 //重复计算：比如s = "leetcode", wordDict = ["leet", "c"，“leetc”],查到leet和c后，查o没有，查od没有等等，而在找到leetc后，又来查o和od造成重复
		return wobreak(s, wordset, 0, memo);
	}
	bool wobreak(string s, set<string>& worddict, int start, vector<int> &memo)
	{
		if (start == s.size())
		{
			return true;
		}
		if (memo[start] != -1)
		{
			return memo[start];
		}
		for (int i = start; i<s.size(); ++i)
		{
			string word = s.substr(start, i - start + 1);
			if (worddict.count(word))
			{
				if (wobreak(s, worddict, i + 1, memo))//从最后一层倒推上来，如果最后又true就是true
				{
					memo[start] = 1;
					return true;
					//return memo[start] = 1;//等同于memo[start] = 1，然后return 1
				}
			}
		}
		//return memo[start] = 0;//等同于下面两句
		memo[start] = 0;
		return false;
	}
};

//方法二
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		set<string> wordset(wordDict.begin(), wordDict.end());
		vector<int> dp(s.size() + 1, 0);
		dp[0] = 1;
		for (int i = 0; i<dp.size(); ++i)
		{
			for (int j = 0; j<i; ++j)
			{
				if (dp[j] && wordset.count(s.substr(j, i - j)))
				{
					dp[i] = 1;
				}
			}
		}
		return dp.back();
	}
};


//复习
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.size() == 0)
		{
			return s.size() == 0;
		}
		unordered_set<string> wordset(wordDict.begin(), wordDict.end());
		vector<int> memo(s.size(), -1);
		return WordBr(s, wordset, 0, memo);
	}
	bool WordBr(string s, unordered_set<string> &wordset, int start, vector<int> &memo)
	{
		if (start == s.size())
		{
			return true;
		}
		if (memo[start] != -1)
		{
			return memo[start];
		}
		for (int i = start; i<s.size(); ++i)
		{
			if (wordset.count(s.substr(start, i - start + 1)))
			{
				if (WordBr(s, wordset, i + 1, memo))
				{
					memo[start] = true;
					return true;
				}
			}
		}
		memo[start] = false;
		return false;
	}
};

//
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> us(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.size() + 1);
		dp[0] = true;
		for (int i = 0; i<dp.size(); ++i)
		{
			for (int j = 0; j<i; ++j)
			{
				if (dp[j] && us.count(s.substr(j, i - j)))
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp.back();
	}
};