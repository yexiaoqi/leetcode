class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (*str == '\0'&&*pattern == '\0')
		{
			return true;
		}//字符串结尾是'\0'不是NULL,'\0'是,NULL是指针无法*NULL
		if (*str != '\0'&&*pattern == '\0')
		{
			return false;
		}
		if (*(pattern + 1) != '*')
		{
			if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
			{
				return match(str + 1, pattern + 1);
			}
			else
			{
				return false;
			}

		}
		else
		{
			if (*(pattern) == *str || (*pattern == '.'&&*str != '\0'))
			{
				return match(str, pattern + 2) || match(str + 1, pattern);
			}
			else {
				return match(str, pattern + 2);
			}
		}
	}
};