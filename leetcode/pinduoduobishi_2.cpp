int Cm2(int m) {
	if (m < 2) {
		return 0;
	}
	return m*(m - 1) / 2;
}

int main()
{
	int n, m;
	cin >> n >> m;

	//int counter[m];
	vector<int> counter(m, 0);
	/*for (int i = 0; i<m; i++) {
	counter[i] = 0;
	}*/

	long sum = 0;

	int num;

	long res = 0;

	for (int i = 0; i<n; i++) {
		cin >> num;
		//scanf("%d", &num);
		sum = (sum + num) % m;
		counter[sum]++;
	}


	for (int i = 0; i<m; i++) {
		res += Cm2(counter[i]);
	}
	res += counter[0];
	cout << res << endl;
	return 0;
}
