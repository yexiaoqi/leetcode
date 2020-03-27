//×¢Òâlong
int main()
{
	long K, N;
	cin >> K >> N;
	long res = 0;
	long best = N / K;
	long last = N - best*K;
	res = pow(best + 1, last)*pow(best, K - last);
	cout<<res;
	return 0;
}
