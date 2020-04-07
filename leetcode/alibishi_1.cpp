

//下面这种不对，不会做
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

/*

f(n) = min{  f(n-1), f(n-2) }

*/

char  myreverse(char ch)
{
	if (ch == '1')
	{
		return '0';
	}
	else
	{
		return '1';
	}
}

int main()
{
	int T;
	cin >> T;
	//vector<string> strs(T,"");
	for (int j = 0; j<T; ++j)
	{
		//cin>>strs[i];
		string str;
		cin >> str;
		int i = 0;
		int step = 0;
		int n = str.size();
		string str2 = str;
		reverse(str2.begin(), str2.end());
		//cout<<str<<str2<<endl;
		bool flag = true;
		while (i<n)
		{
			if (str[i] == '1')
			{
				if (i + 1<str.size())
				{
					++step;
					str[i + 1] = myreverse(str[i + 1]);
					str[i] = myreverse(str[i]);
					if (i + 2<str.size())
					{
						str[i + 2] = myreverse(str[i + 2]);
					}
				}

			}
			//else
			//{
			i++;
			// }
			if (i == n - 1 && str[n - 1] == '1')
			{
				flag = false;
				break;
				//cout<<"NO"<<endl;

			}
		}

		int i2 = 0;
		int step2 = 0;
		bool flag2 = true;
		while (i2<n)
		{
			if (str[i2] == '1')
			{
				if (i2 + 1<str2.size())
				{
					++step2;
					str2[i2 + 1] = myreverse(str2[i + 1]);
					str2[i2] = myreverse(str2[i]);
					if (i2 + 2<str2.size())
					{
						str2[i2 + 2] = myreverse(str2[i2 + 2]);
					}
				}

			}
			//else
			//{
			i2++;
			// }
			if (i2 == n - 1 && str2[n - 1] == '1')
			{
				flag2 = false;
				break;
				//cout<<"NO"<<endl;
				//flag=false;
			}
		}
		if (!flag && !flag2)
		{
			cout << "NO" << endl;
		}
		else if (step == 0)
		{
			cout << step2 << endl;
		}
		else if (step2 == 0)
		{
			cout << step << endl;
		}
		else
		{
			cout << min(step, step2) << endl;
			//cout<<step<<endl;
		}
	}
	return 0;
}




