//Implement strStr().
//
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//Example 1:
//
//Input: haystack = "hello", needle = "ll"
//	Output : 2
//	Example 2 :
//
//	Input : haystack = "aaaaa", needle = "bba"
//	Output : -1

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		int m = haystack.size(), n = needle.size();
		if (!n)
		{
			return 0;
		}
		for (int i = 0;i <= m - n;++i)
		{
			int j = 0;
			for (;j<n;++j)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
			}
			if (j == n)//这个if要放在第二重for循环的外面，为此要提前定义j
			{
				return i;
			}
		}
		return -1;
	}
};