//Í¨¹ý45%
int main()
{
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	unordered_map<char, int> m;
	for (int i = 0; i <= 9; ++i)
	{
		m[i + '0'] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		++m[str[i]];
	}
	for (auto a = m.begin(); a != m.end(); ++a)
	{
		if ((*a).second >= k)
		{
			cout << 0 << endl;
			cout << str << endl;
		}
	}
	int minloss = INT_MAX;
	string res = str;
	string minres = str;
	for (int i = 0; i <= 9; ++i)
	{
		int cnt = m[i + '0'];
		int loss = 0;
		int j = 1;
		res = str;
		while (j <= 9)
		{
			if (i - j >= 0)
			{
				if (cnt + m[(i - j) + '0'] >= k)
				{
					loss += (k - cnt)*j;
					if (minloss > loss)
					{
						minloss = loss;
						//res = str;
						int tmpcnt = 0;
						//for (int l = 0; l < n&&tmpcnt<(k - cnt); ++l)
						for (int l = n - 1; l >= 0 && tmpcnt<(k - cnt); --l)
						{
							if (res[l] == (i - j) + '0')
							{
								res[l] = i + '0';
								tmpcnt++;
							}
						}
						minres = res;
					}
					//++j;
					//continue;
					break;
				}
				else
				{
					loss += m[(i - j) + '0'] * j;
					cnt += m[(i - j) + '0'];
					for (int l = 0; l < n; ++l)
					{
						if (str[l] == (i - j) + '0')
						{
							res[l] = i + '0';
						}
					}
				}
			}
			if (i + j <= 9)
			{
				if (cnt + m[(i + j) + '0'] >= k)
				{
					loss += (k - cnt)*j;
					if (minloss > loss)
					{
						minloss = loss;
						//res = str;
						int tmpcnt = 0;
						for (int l = 0; l < n&&tmpcnt<(k - cnt); ++l)
						{
							if (res[l] == (i + j) + '0')
							{
								res[l] = i + '0';
								tmpcnt++;
							}
						}
					}
					minres = res;
					//++j;
					//continue;
					break;
				}
				else
				{
					loss += m[(i + j) + '0'] * j;
					cnt += m[(i + j) + '0'];
					for (int l = 0; l < n; ++l)
					{
						if (str[l] == (i + j) + '0')
						{
							res[l] = i + '0';
						}
					}
				}
			}
			++j;
		}

	}
	cout << minloss << endl;
	cout << minres << endl;
	return 0;
}
