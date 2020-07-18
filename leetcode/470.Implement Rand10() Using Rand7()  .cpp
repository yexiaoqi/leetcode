// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
	int rand10() {
		int k = 0, maxm = 0;
		int m = 7, n = 10;
		while (maxm + 1<n)
		{
			k = k*m + rand7() - 1;
			maxm = maxm*m + m - 1;
			if (maxm + 1 >= n&&k >= ((maxm + 1) / n*n))
			{
				k = 0;
				maxm = 0;
			}
		}
		return k / ((maxm + 1) / n) + 1;
	}
};


// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
	int rand10() {
		while (true)
		{
			int num = (rand7() - 1) * 7 + rand7() - 1;
			if (num<40)
			{
				return num % 10 + 1;
			}
		}
	}
};