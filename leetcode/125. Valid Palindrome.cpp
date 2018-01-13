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