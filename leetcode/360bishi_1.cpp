//1.DNAƥ��
//��һ�������DNA�������ɺ���A��T��ɣ�����Ϊn��˳������
//��ѧ����һ���µ��ֶΣ����Ըı�����DNA��ÿһ�Σ���ѧ�ҿ��Խ�����DNA�����������λ�ã�Ҳ���Խ�ĳ���ض�λ�õĺ����޸�Ϊ��һ�ֺ��ᡣ
//������һ��DNA����ѧ��ϣ������������һ��DNA��ϣ����������ٵĲ���������



#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
class Solution
{
public:
	int Minstep(string str1, string str2)
	{
		unordered_map<char, int> m1;
		unordered_map<char, int> m2;
		int step = 0;
		int n = str1.size();
		for (int i = 0; i<n; ++i)
		{
			if (str1[i] != str2[i])
			{
				++m1[str1[i]];
				++m2[str2[i]];
			}
		}
		//step=abs(m1['A']-m2['A']);
		step = max(m1['A'], m1['T']);
		return step;
	}
};
int main()
{
	Solution s;
	string str1, str2;
	cin >> str1 >> str2;
	cout << s.Minstep(str1, str2);
	return 0;
}