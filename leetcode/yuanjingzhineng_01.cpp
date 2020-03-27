//https://blog.csdn.net/thecentry/article/details/83042242
//���������ַ���s1��s2���ⶨ����֮������ƶȡ����ƶȵĶ������£�����s1 = "abcde", s2 = "abcd"��
//��ô���ǿ��Ծ���һ�α༭��ɾ��s1���ַ�e��������s2ĩβ�����ַ�e�������Ǳ�Ϊ��ͬ�ģ�����༭������Ϊ���룬
//�����ƶ�Ϊ1 / (���� + 1)��
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		string res = "1/";
		int n = (int)a.size(), m = (int)b.size();
		vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
		dp[0][0] = 0;//dp[x][y]����a�ַ���ǰx���ַ��޸ĳ�b�ַ���ǰy���ַ�
		for (int i = 1; i <= m; ++i)
			dp[0][i] = i;
		for (int i = 1; i <= n; ++i)
			dp[i][0] = i;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				int one = dp[i - 1][j] + 1, two = dp[i][j - 1] + 1, three = dp[i - 1][j - 1];
				if (a[i - 1] != b[j - 1])
					three += 1;
				dp[i][j] = min(min(one, two), three);
			}
		}
		res += to_string(1 + dp[n][m]);
		cout << res << endl;
	}
	return 0;
}