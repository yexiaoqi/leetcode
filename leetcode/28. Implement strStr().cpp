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