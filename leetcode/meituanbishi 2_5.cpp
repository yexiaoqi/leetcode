
//��̬ƥ������
//ʱ�����ƣ�C / C++���� 2000MS���������� 4000MS
//�ڴ����ƣ�C / C++���� 131072KB���������� 655360KB
//��Ŀ������
//
//�ַ���ƥ����һ�ྭ�����⡣�Ӵ���ĸ���г��ֵĴ�����Ϊƥ�������
//���磬�Ӵ�aa��ĸ��aaaba�г��������Σ��Ӵ�[1, 2][2, 3])
//
//���ڣ���һ���ַ������ؼ��ϣ��������п�������ͬ��Ԫ�أ����Լ�k���ַ�����
//��k���ַ��������˳�ʼ���ϡ�
//
//��������Ҫά����ôһ����̬ƥ�����⣺
//
//1��������ɾ��ԭ��k���ַ����еı��Ϊx���ַ�����������Ϊx���ַ������ڸü����У�����ԭ����
//
//2�������м���ԭ��k���ַ����еı��Ϊx���ַ�����������Ϊx���ַ����ڸü����У�����ԭ����
//
//3������һ��ĸ����ѯ�����л��ڼ����е��ַ�����Ϊ�Ӵ���ƥ�����֮�͡�
//
//����
//�����һ�а�����������n, k���������������ͳ�ʼ�ַ����ĸ�����
//
//������k�У�ÿ������һ���ַ�����
//
//������n�У�ÿ��һ���ַ�������һ������
//
//������ַ�����һ���ַ�Ϊ'+'��������Ϊһ������x������ԭ��k���ַ����еĵ�x���ַ������뼯��
//
//������ַ�����һ���ַ�Ϊ'-'��������Ϊһ������x������ԭ��k���ַ����еĵ�x���ַ���ɾ��������
//
//������ַ�����һ���ַ�Ϊ'?'��������Ϊһ���ַ���S������ѯ��S��Ϊĸ����
//���������ڼ����е��ַ�����Ϊ�Ӵ���ƥ�����֮�͡�
//
//ע�⣬�ַ�����1��ʼ��š�
//
//���
//����ÿһ��'?'����������𰸡�
//
//
//��������
//9 3
//a
//ba
//ab
//? ababa
//+ 1
//? ababa
//- 2
//? ababa
//- 3
//? ababa
//+ 2
//? ababa
//�������
//7
//7
//5
//3
//5
//
//��ʾ
//��Χ
//1 <= x <= k��Ŀ�г��ֵ��ַ������ȺͲ�����200000�����е��ַ�������Сд��ĸ��ɡ�
//
//�������ͣ�
//a��ababa�г���3��
//ab��ababa�г���2��
//ba��ababa�г���2��
//���ڲ���1, �ַ���1, 2, 3���ڼ����У��ʴ�Ϊ3 + 2 + 2 = 7
//���ڲ���2, �����ַ���1�ڼ����У���û��Ӱ�졣
//���ڲ���5, �ַ���1, 3�ڼ����У��ʴ�Ϊ3 + 2 = 5
//���ڲ���7, �ַ���1�ڼ����У��ʴ�Ϊ3
//���ڲ���9, �ַ���1, 2�ڼ����У��ʴ�Ϊ3 + 2 = 5




#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include <memory>
#include<time.h>
#include<queue>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;

int match(string motherstr, string sonstr)
{
	int cnt = 0;
	for (int i = 0; i<motherstr.size() - sonstr.size() + 1; ++i)
	{
		int j = 0;
		for (; j<sonstr.size(); ++j)
		{
			if (motherstr[i + j] != sonstr[j])
			{
				break;
			}
		}
		if (j == sonstr.size())
		{
			++cnt;
		}
	}
	return cnt;
}

//match2�ÿ⺯������match�Ĺ��ܣ����Ч��
int match2(string motherstr, string sonstr)
{
	int cnt = 0, fnd = 0;
	while ((fnd = motherstr.find(sonstr, fnd)) != string::npos)
	{
		++cnt;
		++fnd;
	}
	return cnt;
}
int main()
{
	int n, k;
	cin >> n >> k;
	vector<string> strs(k, "");
	unordered_set<string> us;
	for (int i = 0; i<k; ++i)
	{
		cin >> strs[i];
		us.insert(strs[i]);
	}
	for (int i = 0; i<n; ++i)
	{
		string tmp;
		cin >> tmp;
		if (tmp[0] == '+')
		{
			us.insert(strs[stoi(tmp.substr(1)) - 1]);
		}
		else if (tmp[0] == '-')
		{
			us.erase(strs[stoi(tmp.substr(1)) - 1]);
		}
		else if (tmp[0] == '?')
		{
			int cnt = 0;
			//for (int k = 0; k<us.size(); ++k)
			for (auto a = us.begin(); a != us.end(); ++a)
			{
				cnt += match2(tmp.substr(1), *(a));
			}
			cout << cnt << endl;
		}
	}
	return 0;
}



