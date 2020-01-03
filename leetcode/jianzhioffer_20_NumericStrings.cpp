class Solution {
public:
	bool isNumeric(char* string)
	{
		int dot = 0, num = 0, nume = 0;
		if (string == NULL)
		{
			return false;
		}
		if (*string == '+' || *string == '-' || *string == '.')
		{
			if (*string == '.')
			{
				dot = 1;
			}
			++string;
		}
		if (*string == '\0')
		{
			return false;
		}
		while (*string != '\0')
		{
			if (*string <= '9'&&*string >= '0')
			{
				++string;
				num = 1;
			}
			else if (*string == '.')
			{
				char *strbefore = string - 1;//不能用--string和++string，这样string也被改变了
				char *strafter = string + 1;
				bool judge = (*strbefore>'9' || *strbefore<'0') && (*strafter>'9' || *strafter<'0');
				if (dot == 1 || nume == 1 || judge)
				{
					return false;
				}
				dot = 1;
				++string;
			}
			else if (*string == 'e' || *string == 'E')
			{
				if (nume == 1 || num == 0)
				{
					return false;
				}
				++string;
				nume = 1;
				if (*string == '+' || *string == '-')
				{
					++string;
				}
				if (*string>'9' || *string<'0')
				{
					return false;
				}
			}
			else {
				return false;
			}
		}
		return true;
	}

};