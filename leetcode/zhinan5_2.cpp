
int FindSumofnum(string str)
{
	int res = 0;
	int flag = 1;
	int i = 0;
	while (i < str.size())
	{
		if (!(str[i] >= '0'&&str[i] <= '9' || (str[i] == '-')))
		{
			++i;
			continue;
		}
		int tmp = 0;
		while (i < str.size() && str[i] == '-')
		{
			flag = -flag;
			++i;
		}
		while (i < str.size() && (str[i] >= '0'&&str[i] <= '9'))
		{
			tmp = tmp * 10 + str[i] - '0';
			++i;
		}
		if (tmp != 0)
		{
			res = res + flag*tmp;
			flag = 1;
		}
	}
	return res;
}

int main()
{
	cout << FindSumofnum("A-1B--2C-D6E");
	return 0;
}
