//已知有随机生成函数1~m,要得到随机生成函数1~n
class Solution
{
public:
	int rand1tom(int m)
	{
		int res = rand() % m + 1;
		return res;
	}
	int random(int m, int n)
	{
		//输入参数有误
		if (m < 1 || n < 1)return -1;
		//小于2则只能生成1
		if (n < 2)return 1;

		if (n == m)return rand1tom(m);

		int maxm = 0; //组成新n进制数当前位数下的最大数
		int k = 0;   //随机数
		while (maxm + 1 < n)
		{
			k = k * m + rand1tom(m) - 1;   //转换成0到n-1的n进制数。一位时0到n-1，两位时0到(n-1)*n+n-1。此时保证了生成0到最大数之间的各个数的概率是相等的 
			maxm = maxm * m + m - 1;  //求n进制数当前位数下的最大数。一位数时n-1,两位数时(n-1)*n+n-1,三位数时(n-1)*n*n+(n-1)*n+n-1
									  //随机数超出了范围则重新计算。除m再乘m是为了对生成的k进行分组
									  //如m=7，n=5时此处k的范围是0到24，那么25/7=3，3*7=21。
									  //因为21、22、23、24都需要重新计算，所以后面返回值k/((max+1)/m)+1就能保证最大值为7了，即20、19、18除3加1都等于7
									  //此处也可以不进行分组，直接限定k+1<=m后面返回k即可，这样得到k的概率也是一样的，只不过更不容易得到k，因为大量的k将大于m
			if (maxm + 1 >= n && k >= (maxm + 1) / n * n)
			{
				k = 0, maxm = 0;
			}
		}
		return k / ((maxm + 1) / n) + 1;
	}
};
const int MAXNUM = 10000;
int main()
{

	vector<int> cnt(10, 0);
	Solution s;
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXNUM; ++i)
	{
		int num = s.random(7, 9);
		++cnt[num];
	}
	int cntall = 0;
	for (int i = 0; i < cnt.size(); ++i)
	{
		cntall += cnt[i];
		cout << cnt[i] << endl;
	}
	if (cntall != MAXNUM)
	{
		cout << "false";
	}
	else
	{
		cout << "true";
	}
	return 0;
}





















//按照书上的，暂时没写对
class Solution
{
public:
	int rand1toM(int m)
	{
		int res = rand() % m + 1;
		return res;
	}

	int rand1toN(int n, int m)
	{
		vector<int> nMSys = getMSysNum(n - 1, m);
		vector<int> randNum = getRanMSysNumlessN(nMSys, m);
		return getNumFromMSysNum(randNum, m) + 1;
	}

	//把value转成m进制数
	vector<int> getMSysNum(int value, int m)
	{
		vector<int> res(32, 0);
		int index = res.size() - 1;
		while (value != 0)
		{
			res[index--] = value%m;
			value = value / m;
		}
		return res;
	}

	//等概率随机产生一个0~nMsys范围的数，只不过使用m进制表达的
	vector<int> getRanMSysNumlessN(vector<int> nMSys, int m)
	{
		vector<int> res(nMSys.size(), 0);
		int start = 0;
		while (nMSys[start] == 0)
		{
			start++;
		}
		int index = start;
		bool lastEqual = true;
		while (index != nMSys.size())
		{
			res[index] = rand1toM(m) - 1;
			if (lastEqual)
			{
				if (res[index] > nMSys[index])
				{
					index = start;
					lastEqual = true;
					continue;
				}
				else
				{
					lastEqual = res[index] == nMSys[index];
				}
			}
			index++;
		}
		return res;
	}

	//把m进制数转成十进制数
	int getNumFromMSysNum(vector<int> mSysNum, int m)
	{
		int res = 0;
		for (int i = 0; i != mSysNum.size(); ++i)
		{
			res = res*m + mSysNum[i];
		}
		return res;
	}
};
const int MAXNUM = 10000;
int main()
{

	vector<int> cnt(7, 0);
	Solution s;
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXNUM; ++i)
	{
		int num = s.rand1toN(15, 10);
		++cnt[num];
	}
	int cntall = 0;
	for (int i = 0; i < cnt.size(); ++i)
	{
		cntall += cnt[i];
		cout << cnt[i] << endl;
	}
	if (cntall != MAXNUM)
	{
		cout << "false";
	}
	else
	{
		cout << "true";
	}
	return 0;
}