string deletek0(string str, int k)
{
	int cnt = 0;
	string res = "";
	int i = 0;
	while (i < str.size())
	{
		while (i < str.size() && str[i] != '0')
		{
			res += str[i];
			cnt = 0;
			++i;
		}
		while (i < str.size() && str[i] == '0')
		{
			++cnt;
			++i;
		}
		if (cnt == k)
		{
			continue;
		}
		else
		{
			res += str.substr(i - cnt, cnt);//´úÌæÏÂÃæ
			/*for (int j = 0; j < cnt; ++j)
			{
				res += '0';
			}*/
		}
	}
	return res;
}
int main()
{
	cout << deletek0("A0000B000", 3);
	return 0;
}
