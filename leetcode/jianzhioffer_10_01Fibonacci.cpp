class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 1)
		{
			return n;
		}
		int a = 0, b = 1;
		for (int i = 2; i<n + 1; ++i)
		{
			b = a + b;
			a = b - a;
		}
		return b;
	}
};

//¸´Ï°£¬Ò»±éac
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
		{
			return 0;
		}
		int a = 0, b = 1;
		for (int i = 2; i <= n; ++i)
		{
			b = a + b;
			a = b - a;
		}
		return b;
	}
};