//没有刷题网站测试，只测试了书上的例子通过

string ChangeStr(string str, string from, string to)
{
	int i = 0;
	int n = from.size();
	string res = "";
	while (i < str.size())
	{
		if (str[i] != from[0])
		{
			res += str[i];
			++i;
		}
		else
		{
			if (str.substr(i, n) == from)
			{
				i += n;
				while (str.substr(i, n) == from)
				{
					i += n;
				}
				res += to;
			}
			else
			{
				res += str[i];
				++i;
			}
		}
	}
	cout << res;
	return res;
}

int main()
{
	string str = "123abcabc";
	string from = "abc";
	string to = "X";
	ChangeStr(str, from, to);
	return 0;
}