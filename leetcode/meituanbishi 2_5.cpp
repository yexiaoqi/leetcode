
//动态匹配问题
//时间限制：C / C++语言 2000MS；其他语言 4000MS
//内存限制：C / C++语言 131072KB；其他语言 655360KB
//题目描述：
//
//字符串匹配是一类经典问题。子串在母串中出现的次数称为匹配次数。
//例如，子串aa在母串aaaba中出现了两次（子串[1, 2][2, 3])
//
//现在，有一个字符串多重集合（即集合中可以有相同的元素），以及k个字符串，
//这k个字符串构成了初始集合。
//
//现在你需要维护这么一个动态匹配问题：
//
//1、集合中删除原本k个字符串中的编号为x的字符串。如果编号为x的字符串不在该集合中，保持原样。
//
//2、集合中加入原本k个字符串中的编号为x的字符串。如果编号为x的字符串在该集合中，保持原样。
//
//3、给出一个母串，询问所有还在集合中的字符串作为子串的匹配次数之和。
//
//输入
//输入第一行包括两个整数n, k，描述操作次数和初始字符串的个数。
//
//接下来k行，每行描述一个字符串。
//
//接下来n行，每行一个字符串描述一个操作
//
//如果该字符串第一个字符为'+'，接下来为一个数字x，代表将原本k个字符串中的第x个字符串加入集合
//
//如果该字符串第一个字符为'-'，接下来为一个数字x，代表将原本k个字符串中的第x个字符串删除出集合
//
//如果该字符串第一个字符为'?'，接下来为一个字符串S，代表询问S作为母串，
//所有现在在集合中的字符串作为子串的匹配次数之和。
//
//注意，字符串从1开始编号。
//
//输出
//对于每一个'?'操作，输出答案。
//
//
//样例输入
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
//样例输出
//7
//7
//5
//3
//5
//
//提示
//范围
//1 <= x <= k题目中出现的字符串长度和不超过200000，所有的字符串均由小写字母组成。
//
//样例解释：
//a在ababa中出现3次
//ab在ababa中出现2次
//ba在ababa中出现2次
//对于操作1, 字符串1, 2, 3都在集合中，故答案为3 + 2 + 2 = 7
//对于操作2, 由于字符串1在集合中，故没有影响。
//对于操作5, 字符串1, 3在集合中，故答案为3 + 2 = 5
//对于操作7, 字符串1在集合中，故答案为3
//对于操作9, 字符串1, 2在集合中，故答案为3 + 2 = 5




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

//match2用库函数代替match的功能，提高效率
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



