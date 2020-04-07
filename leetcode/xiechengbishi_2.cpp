//迭代着一年一年算
int main()
{
	int n, m, p;
	cin >> n >> m >> p;
	unordered_set<int> years;
	//vector<int> years;
	for (int i = 0; i < p; ++i)
	{
		//cin >> years[i];
		int y;
		cin >> y;
		years.insert(y);
	}
	int targetyear;
	cin >> targetyear;
	map<int, int> mp;
	for (int i = 0; i <= m; ++i)
	{
		mp[i] = 0;
	}
	mp[0] = n;
	for (int i = 1; i < targetyear; ++i)
	{
		mp[m] = 0;
		int newan = 0;
		auto a = mp.end();
		for (; a != mp.begin(); --a)
		{

			auto tmp = a;
			if (tmp != mp.end())
			{
				++tmp;
				if (tmp != mp.end())
				{
					(*tmp).second = (*a).second;
				}
			}
			if (years.count((*tmp).first) && (*tmp).second != 0)
			{
				newan += (*tmp).second;
			}
		}
		auto tmp = a;
		++tmp;
		(*tmp).second = (*a).second;
		if (years.count((*tmp).first) && (*tmp).second != 0)
		{
			newan += (*tmp).second;
		}
		mp[0] = newan;
	}
	long cnt = 0;
	for (auto a = mp.begin(); a != mp.end(); ++a)
	{
		cnt += (*a).second;
	}
	cout << cnt;
	return 0;
}