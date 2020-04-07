//10个小球，随机分到12个盒子里，求恰好5个盒子都为空的概率，要求用代码进行10万次模拟得出概率
int main()
{
	srand((unsigned)time(NULL));
	int allcnt = 0;
	for (int i = 0; i < 1000000; ++i)
	{
		unordered_set<int> us;
		for (int j = 0; j < 10; ++j)
		{
			us.insert(rand() % 12);
		}
		int cnt = us.size();
		if (cnt == 2)
		{
			++allcnt;
		}
	}
	double res = allcnt / 1000000.0;
	cout << res;
	return 0;
}

