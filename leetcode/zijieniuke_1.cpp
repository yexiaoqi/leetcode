//10��С������ֵ�12���������ǡ��5�����Ӷ�Ϊ�յĸ��ʣ�Ҫ���ô������10���ģ��ó�����
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

