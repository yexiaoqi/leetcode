/*��һ���ܾ���������ǣ���ǰʱ����aa:bb, �������ɷ��Ӻ���ʲôʱ�䣿���ǽ����������һ���෴�����⡣

	��֪���ڵ�ʱ��������x��yy : zzʱ�̣�����n����ǰ���ܼ���ʱ���Ƕ��١�

	����������������02 : 10, ��200����֮ǰ��Ӧ�����ܶ���22 : 50��

	����
	�����������

	��һ��һ��������x����ʾ��������x��(1 <= x <= 7)

	�ڶ�����һ��24Сʱ�Ƶ�ʱ���ʾ��ʱ�ͷ־���ǰ��0�����磬1ʱ1�ֱ�ʾΪ01 : 01����֤ʱ���ʽ�ǺϷ��ġ�

	��������һ��������n����ʾҪ�����n����֮ǰ��ʱ�䡣(1 <= n <= 10 ^ 9)

	���
	���ͬ���������У���һ�н�����һ������������ʾn����֮ǰ���ܼ���

	һ��24Сʱ�Ƶ�ʱ���ʾ��ʱ�ͷ־���ǰ��0�����磬1ʱ1�ֱ�ʾΪ01 : 01����ʾn����֮ǰ��ʱ�̡�


	��������
	3
	02 : 10
	200
	�������
	2
	22 : 50

	��ʾ
	������������Ϊ��
	���� 00 : 01��ǰ1����Ϊ ���� 00 : 00
	���� 00 : 00��ǰ1����Ϊ ���� 23 : 59*/


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


int main()
{
	int x, n;
	string nowtime;
	cin >> x;
	cin >> nowtime;
	cin >> n;
	string beforetime;

	int hours = n / 60;
	int minute = n % 60;
	int day = hours / 24 % 7;
	int hour = hours % 24;

	int nowhour = nowtime[0] == '0' ? nowtime[1] - '0' : stoi(nowtime.substr(0, 2));
	int beforeday = (x + 7 - day) % 7;

	int beforehour = (nowhour + 24 - hour) % 24;
	int nowminute = nowtime[3] == '0' ? nowtime[4] - '0' : stoi(nowtime.substr(3, 2));
	int beforeminute = (nowminute + 60 - minute) % 60;
	if (nowhour * 60 + nowminute< hour * 60 + minute)
	{
		--beforeday;
	}
	if (nowminute<  minute)
	{
		--beforehour;
	}
	while (beforeday <= 0)
	{
		beforeday += 7;
	}
	cout << beforeday << endl;
	/*if (beforeminute != 0)
	{
	--beforehour;
	}*/
	while (beforehour<0)
	{
		beforehour += 24;
	}
	//beforetime = nowhour < 10 ? ('0'+(nowhour+'0')):to_string(nowhour);
	if (beforehour < 10)
	{
		beforetime += '0';
		beforetime += (beforehour + '0');
		//beforetime = '0' + (nowhour + '0');
	}
	else
	{
		beforetime = to_string(beforehour);
	}
	beforetime += ':';
	if (beforeminute < 10)
	{
		beforetime += '0';
		beforetime += (beforeminute + '0');
		//beforetime += '0' + (beforeminute + '0');
	}
	else
	{
		beforetime += to_string(beforeminute);
	}
	cout << beforetime;
	return 0;
}

