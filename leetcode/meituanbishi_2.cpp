//同心圆，注意π取值，取7位和取很多位不一样结果
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	//double pi = 3.1415926;
	double pi2 = acos(-1);//arccos(−1)=π
	double res = 0;
	int flag = 1;
	//double res2 = 0;
	for (int i = 996; i >0; --i)
	{
		//res2 += flag*pow(i, 2);
		res += flag*pi2*pow(i, 2);
		flag = -flag;
	}
	//res2 *= pi;
	cout << fixed << setprecision(5) << res << endl;
	//cout << fixed << setprecision(5) << res2 << endl;
	/*cout << res << endl;
	cout << res2 << endl;*/
}