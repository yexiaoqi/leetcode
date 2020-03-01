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

//O(mn)时间复杂度方法
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

//O(m+n）时间复杂度方法，KMP算法
//https://www.cnblogs.com/grandyang/p/6992403.html
class Solution {
public:
	vector<int> getNext(string p) {
		int n = p.size(), k = -1, j = 0;
		vector<int> next(n, -1);
		while (j < n - 1) {
			if (k == -1 || p[j] == p[k]) {
				++k; ++j;
				next[j] = (p[j] != p[k]) ? k : next[k];
			}
			else {
				k = next[k];
			}
		}
		return next;
	}
	int strStr(string s, string p) {
		int m = s.size(), n = p.size(), i = 0, j = 0;
		vector<int> next = getNext(p);
		while (i < m && j < n) {
			if (j == -1 || s[i] == p[j]) {
				++i; ++j;
			}
			else {
				j = next[j];
			}
		}
		return (j == n) ? i - j : -1;
	}
};



//复习
//自己写的方法
class Solution {
public:
	int strStr(string haystack, string needle) {
		int hsize = haystack.size();
		int nsize = needle.size();
		if (nsize == 0)
		{
			return 0;
		}
		if (hsize<nsize)
		{
			return -1;
		}//判断两个特殊情况
		int i = 0;
		int res = 0;
		while (i <= hsize - nsize)//注意只要遍历到hsize - nsize，而不是i<hsize;否则会超级无敌慢
		{
			int index = 0;
			if (needle[index] == haystack[i])
			{
				res = i;
				while (index<nsize - 1)
				{
					++index;
					++i;
					if (i>hsize || needle[index] != haystack[i])
					{
						break;
					}
				}
				if (index == nsize - 1 && needle[index] == haystack[i])
				{
					return res;
				}
				i = res + 1;
			}
			else
			{
				++i;
			}
		}
		return -1;
	}
};


//
class Solution {
public:
	int strStr(string haystack, string needle) {
		int hsize = haystack.size();
		int nsize = needle.size();
		if (nsize == 0)
		{
			return 0;
		}
		if (hsize<nsize)
		{
			return -1;
		}//判断两个特殊情况
		 // int i=0;
		 // int res=0;
		for (int i = 0; i <= hsize - nsize; ++i)
		{
			int index = 0;
			for (index = 0; index<nsize; ++index)
			{
				if (haystack[i + index] != needle[index])
				{
					break;
				}
			}
			if (index == nsize)
			{
				return i;
			}
		}
		return -1;
		// while(i<=hsize-nsize)
		// {
		//     int index=0;
		//     if(needle[index]==haystack[i])
		//     {
		//         res=i;
		//         while(index<nsize-1)
		//         {
		//             ++index;
		//             ++i;
		//             if(i>hsize||needle[index]!=haystack[i])
		//             {
		//                 break;
		//             }
		//         }
		//         if(index==nsize-1&&needle[index] == haystack[i])
		//         {
		//             return res;
		//         }
		//         i=res+1;
		//     }
		//     else
		//     {
		//         ++i;
		//     }
		// }
		// return -1;
	}
};


//复习
class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.size(), n = needle.size();
		if (!n)
		{
			return 0;
		}
		if (m<n)
		{
			return -1;
		}
		for (int i = 0; i <= m - n; ++i)
		{
			int j = 0;
			for (j = 0; j<n; ++j)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
			}
			if (j == n)
			{
				return i;
			}
		}
		return -1;
	}
};