//1.DNA匹配
//有一种特殊的DNA，仅仅由核酸A和T组成，长度为n，顺次连接
//科学家有一种新的手段，可以改变这种DNA。每一次，科学家可以交换该DNA上两个核酸的位置，也可以将某个特定位置的核酸修改为另一种核酸。
//现在有一个DNA，科学家希望将其改造成另一种DNA，希望你计算最少的操作次数。



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