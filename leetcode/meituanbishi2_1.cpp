/*有一个很经典的问题是，当前时间是aa:bb, 请问若干分钟后是什么时间？我们今天的问题是一个相反的问题。

	已知现在的时刻是星期x的yy : zz时刻，请问n分钟前是周几，时间是多少。

	例如现在是周三，02 : 10, 则200分钟之前，应该是周二，22 : 50。

	输入
	输入包含三行

	第一行一个正整数x，表示今天是周x。(1 <= x <= 7)

	第二行是一个24小时制的时间表示，时和分均含前导0，例如，1时1分表示为01 : 01。保证时间格式是合法的。

	第三行是一个正整数n，表示要求的是n分钟之前的时间。(1 <= n <= 10 ^ 9)

	输出
	输出同样包含两行，第一行仅包含一个正整数，表示n分钟之前是周几。

	一个24小时制的时间表示，时和分均含前导0，例如，1时1分表示为01 : 01。表示n分钟之前的时刻。


	样例输入
	3
	02 : 10
	200
	样例输出
	2
	22 : 50

	提示
	本题中我们认为：
	周四 00 : 01的前1分钟为 周四 00 : 00
	周四 00 : 00的前1分钟为 周三 23 : 59*/


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

