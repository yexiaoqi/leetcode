//You are climbing a stair case.It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
//
//Note : Given n will be a positive integer.
//
//
//	Example 1 :
//
//	Input : 2
//	Output : 2
//	Explanation : There are two ways to climb to the top.
//
//	1. 1 step + 1 step
//	2. 2 steps
//	Example 2 :
//
//	Input : 3
//	Output : 3
//	Explanation : There are three ways to climb to the top.
//
//	1. 1 step + 1 step + 1 step
//	2. 1 step + 2 steps
//	3. 2 steps + 1 step

class Solution
	//相当于一个斐波那契数列，因为考察第n步，可以由【n-1】和[n-2]相加得到，因为[n-1]再走1 step得到【n】，【n-2】再走一个2 step可以得到
{
public:
	int climbStairs(int n)
	{
		if (n <= 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}
		if (n == 2)
		{
			return 2;
		}
		int one_step = 1;
		int two_step = 2;
		int all_ways = 0;
		for (int i = 0;i<n - 2;++i)//执行n-2次，比如n=3，就只要执行一次
		{
			all_ways = one_step + two_step;
			one_step = two_step;
			two_step = all_ways;
		}
		return all_ways;
	}
};

class Solution {
public:
	int climbStairs(int n) {
		int a = 1, b = 1;
		while (--n)
		{
			b += a;
			a = b - a;
		}
		return b;
	}
};

//复习，自己做出，一遍ac
class Solution {
public:
	int climbStairs(int n) {
		if (n == 1)
		{
			return 1;
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