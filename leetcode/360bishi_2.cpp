//2.A和B两个人在抽奖。现在有一个抽奖箱，里面有n张中奖票，m张不中奖票。A和B轮流从中抽一张奖票出来。如果有人抽到中奖票就结束，抽到中奖票的人胜利。抽过的奖票会被丢弃。
//额外的，B每次抽后，会再次抽取一张票并丢弃掉（这张票中奖不算B胜利）。
//现在，A先抽，请问A的胜率，保留4位小数后输出。
//如果两人到最后也没有抽到中奖票算作B胜利。




//A第一次中奖，概率是n/(m+n),结束，我们把这个函数叫f(n,m)
//A第一次没中奖的情况下，B中奖的概率是n/(m+n-1),结束
//A第一次没中奖的情况下，B第一次没中奖的概率是（m-1）/(m+n-1)
//A第一次没中奖、B第一次没中奖的情况下，B扔掉一张中奖券的概率是n/(m+n-2)，此时下一次A中奖的概率是（n-1）/(m+n-3)，我们发现这就是函数f(n-1,m-2)
//A第一次没中奖、B第一次没中奖的情况下，B扔掉一张不中奖券的概率是n/(m+n-2)，此时下一次A中奖的概率是n/(m+n-3)，我们发现这就是函数f(n,m-3)
//至此我们可以发现f(n,m)=first +tmp1*f(n-1,m-2)+ tmp2*f(n,m-3) ，first是A第一次中奖概率，tmp1是A第一次没中奖的概率*B第一次没中奖的概率*B扔掉一张中奖券的概率，tmp2是A第一次没中奖的概率*B第一次没中奖的概率*B扔掉一张没中奖券的概率
class Solution
{
public:
	double Willwin(int n, int m)
	{
		if (n == 0)
		{
			return 0.0;
		}
		if (m == 0)
		{
			return 1.0;
		}
		double dm = m, dn = n;
		double first = dn / (dm + dn);
		double beforetmp = dm / (dm + dn) * (dm - 1) / (dm + dn - 1);
		double tmp1 = beforetmp* dn / (dm + dn - 2);
		double tmp2 = beforetmp* (dm - 2) / (dm + dn - 2);
		if (m == 1)
		{
			return first;
		}
		if (m == 2)
		{
			return first + tmp1*Willwin(n - 1, m - 2);
		}
		return first + tmp1*Willwin(n - 1, m - 2) + tmp2*Willwin(n, m - 3);
	}
	void testall()
	{
		test(1, 1);
		test(1, 2);
		test(1, 3);
		test(1, 4);
		test(2, 1);
		test(2, 2);
		test(2, 3);
		test(2, 4);
		test(3, 1);
		test(3, 2);
		test(3, 3);
		test(3, 4);
	}
	void test(int n, int m)
	{
		cout << Willwin(n, m) << endl;
	}
};
int main()
{
	Solution s;
	s.testall();
	return 0;
}