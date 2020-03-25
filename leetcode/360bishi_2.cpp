//2.A��B�������ڳ齱��������һ���齱�䣬������n���н�Ʊ��m�Ų��н�Ʊ��A��B�������г�һ�Ž�Ʊ������������˳鵽�н�Ʊ�ͽ������鵽�н�Ʊ����ʤ��������Ľ�Ʊ�ᱻ������
//����ģ�Bÿ�γ�󣬻��ٴγ�ȡһ��Ʊ��������������Ʊ�н�����Bʤ������
//���ڣ�A�ȳ飬����A��ʤ�ʣ�����4λС���������
//������˵����Ҳû�г鵽�н�Ʊ����Bʤ����




//A��һ���н���������n/(m+n),���������ǰ����������f(n,m)
//A��һ��û�н�������£�B�н��ĸ�����n/(m+n-1),����
//A��һ��û�н�������£�B��һ��û�н��ĸ����ǣ�m-1��/(m+n-1)
//A��һ��û�н���B��һ��û�н�������£�B�ӵ�һ���н�ȯ�ĸ�����n/(m+n-2)����ʱ��һ��A�н��ĸ����ǣ�n-1��/(m+n-3)�����Ƿ�������Ǻ���f(n-1,m-2)
//A��һ��û�н���B��һ��û�н�������£�B�ӵ�һ�Ų��н�ȯ�ĸ�����n/(m+n-2)����ʱ��һ��A�н��ĸ�����n/(m+n-3)�����Ƿ�������Ǻ���f(n,m-3)
//�������ǿ��Է���f(n,m)=first +tmp1*f(n-1,m-2)+ tmp2*f(n,m-3) ��first��A��һ���н����ʣ�tmp1��A��һ��û�н��ĸ���*B��һ��û�н��ĸ���*B�ӵ�һ���н�ȯ�ĸ��ʣ�tmp2��A��һ��û�н��ĸ���*B��һ��û�н��ĸ���*B�ӵ�һ��û�н�ȯ�ĸ���
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