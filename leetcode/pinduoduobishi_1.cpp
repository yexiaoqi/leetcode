//1.ƴ�����Ʒ������һ����������Ʒ�����м۸���͵�һ����Ʒ��
//�����һ������Ʒ�������ڶ�����ÿ����Ʒ�ļ۸���Ҫ��������Ʒ����������Ҫ����С�۸�


int main()
{
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	long allsum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
		allsum += nums[i];
	}
	sort(nums.rbegin(), nums.rend());
	for (int i = 0; i < n; ++i)
	{
		if (i % 3 == 2)
		{
			allsum -= nums[i];
		}
	}
	cout << allsum << endl;
	return 0;
}