//�����û�����Ŀ��ӡ��ʼ����ű���

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	unordered_map<char, char> m;
	//unordered_map<int, char> m;
	for (int i = 1; i <= 9; ++i)
	{
		cin >> m[i + '0'];
		//cin >> m[i];
	}
	string res;
	int i = 0;
	if (s[0] == '-')
	{
		res += '-';
		++i;
	}
	for (; i<s.size(); ++i)
	{
		res += m[s[i]];
	}
	cout << res;
	return 0;
}
