//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.
//
//Note:
//Have you consider that the string might be empty ? This is a good question to ask during an interview.
//
//For the purpose of this problem, we define empty string as valid palindrome.

class Solution
{
public:
	bool isPalindrome(string s)
	{
		for (int i = 0, j = s.size() - 1;i<j;++i, --j)
		{
			while (!isalnum(s[i]) && i<j)//是while不是if
			{
				++i;
			}
			while (!isalnum(s[j]) && i<j)
			{
				--j;
			}
			if (toupper(s[i]) != toupper(s[j]))//注意全部转换为大写或小写
			{
				return false;
			}
		}
		return true;
	}
};

//复习
//自己的方法，需要额外空间，不够好
class Solution {
public:
	bool isPalindrome(string s) {
		vector<int> res1;
		for (int i = 0; i<s.size(); ++i)
		{
			if ((s[i] >= '0'&&s[i] <= '9') || (s[i] >= 'a'&&s[i] <= 'z') ||
				(s[i] >= 'A'&&s[i] <= 'Z'))
			{
				if (s[i] >= 'A'&&s[i] <= 'Z')
				{
					res1.push_back(s[i] + 32);
				}
				else
				{
					res1.push_back(s[i]);
				}
			}
		}
		vector<int> res2(res1.rbegin(), res1.rend());
		for (int i = 0; i<res1.size(); ++i)
		{
			if (res1[i] != res2[i])
			{
				return false;
			}
		}
		return true;
	}
};

//
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty())
		{
			return true;
		}
		int begin = 0, end = s.size() - 1;
		while (begin<end)
		{
			if (!isalnum(s[begin]))
			{
				++begin;
			}
			else if (!isalnum(s[end]))
			{
				--end;
			}
			else if (toupper(s[begin]) != toupper(s[end]))
			{
				return false;
			}
			else
			{
				++begin;
				--end;
			}
		}
		return true;
	}
};


//复习
class Solution {
public:
	bool isPalindrome(string s) {
		string revs = s;
		reverse(revs.begin(), revs.end());
		int i = 0, j = 0;
		while (i<s.size())
		{
			while (i<s.size() && !isalnum(s[i]))
			{
				++i;
			}
			while (j<revs.size() && !isalnum(revs[j]))
			{
				++j;
			}
			if (toupper(s[i]) != toupper(revs[j]))
			{
				return false;
			}
			else
			{
				++i; ++j;
			}
		}
		return true;
	}
};

//复习
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty())
		{
			return true;
		}
		int begin = 0, end = s.size() - 1;
		while (begin<end)
		{
			while (begin<end && !isalnum(s[begin]))
			{
				++begin;
			}
			while (begin<end && !isalnum(s[end]))
			{
				--end;
			}
			if (toupper(s[begin]) != toupper(s[end]))
			{
				return false;
			}
			else
			{
				++begin;
				--end;
			}
		}
		return true;
	}
};