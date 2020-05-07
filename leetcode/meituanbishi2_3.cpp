//补漏洞
//时间限制：C / C++语言 1000MS；其他语言 3000MS
//内存限制：C / C++语言 65536KB；其他语言 589824KB
//题目描述：
//作为一个程序员，修bug（补漏洞）是一项基本的工作。当你刚刚完成一个工作的时候，甲方说你的程序里面有n个bug。
//
//但是你已经很累了，你希望第一天修x个bug, 第二天修[x / k]个bug，第三天修[x / k2]个bug，以此类推，第n天修⌊x / k ^ (n - 1) ⌋个bug，
//直到修不了bug为止。
//
//[x]的意思是x向下取整。在k大于1的时候，总有一天会修不了一个bug的。所以，你希望在这一天来临之前，修完所有的bug。
//你要计算，你第一次至少要修多少个bug，即x的最小值为多少。
//
//输入
//输入包含一行两个整数n, k 分别代表漏洞总数和题目中的参数k
//
//输出
//输出包含一个数，即x的最小值
//
//
//样例输入
//10 3
//样例输出
//8
//
//提示
//范围
//1 <= n <= 10 ^ 9, 2 <= k <= 10
//
//样例解释：
//第一天修8个bug，第二天修2个bug，从第三天开始修不了bug，总共修了10个，修完了所有的bug。
//如果第一天只修7个bug，那么第二天只能修2个bug，从第三天修不了bug，总共修了9个bug，不能完成目标，所以第一天至少修8个bug。
//




#include <iostream>

using namespace std;

int cal(int k, int x) {
	int t = 1;
	int sum = 0;
	while (x / t>0) {
		//cout<<(x/t)<<" ";
		sum += x / t;
		t *= k;
	}
	//cout<<"-->"<<sum<<endl;
	return sum;
}

int main()
{
	int n, k;
	cin >> n >> k;

	int l = 1;
	int r = n + 1;

	while (l < r) {
		//cout<<l<<"<-->"<<r<<endl;

		int mid = (l + r) / 2;

		int res = cal(k, mid);

		if (res < n) {
			l = mid + 1;
		}
		else if (res > n) {
			r = mid - 1;
		}
		else {
			l = mid;
			break;
		}
	}

	int res = cal(k, l);
	if (res == n) {
		//
	}
	else if (res > n) {
		while (cal(k, l) >= n) {
			l--;
		}
		l += 1;
	}
	else {
		while (cal(k, l) <= n) {
			l++;
		}
	}

	cout << l << endl;
	//cout<<cal(k, l)<<endl;

	return 0;
}
