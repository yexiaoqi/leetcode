//下面不对
int main()
{
	string str;
	cin >> str;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	for (int i = 0; i<str.size(); ++i)
	{
		if (str[i] == '(')
		{
			++cnt1;
		}
		else if (str[i] == ')')
		{
			if (cnt1 == 0)
			{
				++cnt2;
			}
			else
			{
				--cnt1;
			}
		}
		else if (str[i] == '[')
		{
			++cnt3;
		}
		else
		{
			if (cnt3 == 0)
			{
				++cnt4;
			}
			else
			{
				--cnt3;
			}
		}
	}
	int sum = cnt1 + cnt2 + cnt3 + cnt4;
	cout << sum;
	return 0;
}