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


//复习，自己做出，仔细，这种写法更好
class Solution {
public:
	bool isNumeric(char* string)
	{
		if (*string == '\0')
		{
			return false;
		}
		bool existe = false, existpoint = false;
		if (string[0] == '+' || string[0] == '-')
		{
			if (string[1] == '\0')
			{
				return false;
			}
		}
		else if (string[0] == '.')
		{
			if (string[1] == '\0')
			{
				return false;
			}
		}
		else if (string[0]<'0' || string[0]>'9')
		{
			return false;
		}
		for (int i = 1; i<strlen(string); ++i)
		{
			if (string[i] == 'e' || string[i] == 'E')
			{
				if (existe)
				{
					return false;
				}
				existe = true;
				if (string[i - 1]<'0' || string[i - 1]>'9')
				{
					return false;
				}
				if (i == strlen(string) - 1)
				{
					return false;
				}
			}
			else if (string[i] == '.')
			{
				if (existe || existpoint)
				{
					return false;
				}
				existpoint = true;
				if ((string[i - 1]<'0' || string[i - 1]>'9') && (string[i + 1]<'0' || string[i + 1]>'9'))
				{
					return false;
				}
			}
			else if (string[i] == '+' || string[i] == '-')
			{
				if (string[i - 1] != 'e'&&string[i - 1] != 'E')
				{
					return false;
				}
				if (i == strlen(string) - 1 || (string[i + 1]<'0' || string[i + 1]>'9'))
				{
					return false;
				}
			}
			else if (string[i]<'0' || string[i]>'9')
			{
				return false;
			}
		}
		return true;
	}
};