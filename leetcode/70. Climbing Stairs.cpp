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
	//�൱��һ��쳲��������У���Ϊ�����n���������ɡ�n-1����[n-2]��ӵõ�����Ϊ[n-1]����1 step�õ���n������n-2������һ��2 step���Եõ�
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
		for (int i = 0;i<n - 2;++i)//ִ��n-2�Σ�����n=3����ֻҪִ��һ��
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

//��ϰ���Լ�������һ��ac
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