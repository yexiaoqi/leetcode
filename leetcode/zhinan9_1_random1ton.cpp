//��֪��������ɺ���1~m,Ҫ�õ�������ɺ���1~n
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
		//�����������
		if (m < 1 || n < 1)return -1;
		//С��2��ֻ������1
		if (n < 2)return 1;

		if (n == m)return rand1tom(m);

		int maxm = 0; //�����n��������ǰλ���µ������
		int k = 0;   //�����
		while (maxm + 1 < n)
		{
			k = k * m + rand1tom(m) - 1;   //ת����0��n-1��n��������һλʱ0��n-1����λʱ0��(n-1)*n+n-1����ʱ��֤������0�������֮��ĸ������ĸ�������ȵ� 
			maxm = maxm * m + m - 1;  //��n��������ǰλ���µ��������һλ��ʱn-1,��λ��ʱ(n-1)*n+n-1,��λ��ʱ(n-1)*n*n+(n-1)*n+n-1
									  //����������˷�Χ�����¼��㡣��m�ٳ�m��Ϊ�˶����ɵ�k���з���
									  //��m=7��n=5ʱ�˴�k�ķ�Χ��0��24����ô25/7=3��3*7=21��
									  //��Ϊ21��22��23��24����Ҫ���¼��㣬���Ժ��淵��ֵk/((max+1)/m)+1���ܱ�֤���ֵΪ7�ˣ���20��19��18��3��1������7
									  //�˴�Ҳ���Բ����з��飬ֱ���޶�k+1<=m���淵��k���ɣ������õ�k�ĸ���Ҳ��һ���ģ�ֻ�����������׵õ�k����Ϊ������k������m
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





















//�������ϵģ���ʱûд��
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

	//��valueת��m������
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

	//�ȸ����������һ��0~nMsys��Χ������ֻ����ʹ��m���Ʊ���
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

	//��m������ת��ʮ������
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