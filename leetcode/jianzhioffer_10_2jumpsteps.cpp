class Solution {
public:
	int jumpFloor(int n) {
		if (n == 1)
		{
			return 1;
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