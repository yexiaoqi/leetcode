class Solution {
public:
	int rectCover(int n) {
		if (n <= 1)
		{
			return n;
		}
		int a = 1, b = 2;
		for (int i = 2; i<n; ++i)
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
	int rectCover(int n) {
		if (n <= 2)
		{
			return n;
		}
		int a = 1, b = 2;
		for (int i = 3; i <= n; ++i)
		{
			b = a + b;
			a = b - a;
		}
		return b;
	}
};