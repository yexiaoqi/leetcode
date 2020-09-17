//����д�ᳬʱ
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
				if (wobreak(s, worddict, i + 1))//�����һ�㵹����������������true����true
				{
					return true;
				}
			}
		}
		return false;
	}
};

//��ȷ����һ
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.empty())
		{
			return s.empty() ? true : false;
		}
		set<string> wordset(wordDict.begin(), wordDict.end());
		vector<int> memo(s.size(), -1);
//�������� memo[i] ����Ϊ��ΧΪ [i, n] �����ַ����Ƿ���Բ�֣���ʼ��Ϊ -1����ʾû�м������������Բ�֣���ֵΪ1����֮Ϊ0��
 //�ظ����㣺����s = "leetcode", wordDict = ["leet", "c"����leetc��],�鵽leet��c�󣬲�oû�У���odû�еȵȣ������ҵ�leetc��������o��od����ظ�
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
				if (wobreak(s, worddict, i + 1, memo))//�����һ�㵹����������������true����true
				{
					memo[start] = 1;
					return true;
					//return memo[start] = 1;//��ͬ��memo[start] = 1��Ȼ��return 1
				}
			}
		}
		//return memo[start] = 0;//��ͬ����������
		memo[start] = 0;
		return false;
	}
};

//������
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


//��ϰ
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