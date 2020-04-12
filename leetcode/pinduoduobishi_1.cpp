//1.拼多多物品买三送一，买三件物品送其中价格最低的一件物品。
//输入第一行数物品数量，第二行是每个物品的价格。求要把所有物品买下来所需要的最小价格。


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