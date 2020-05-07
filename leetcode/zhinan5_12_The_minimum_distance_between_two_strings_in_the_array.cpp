//时间复杂度O（n），额外空间复杂度O（1）
//应该同leetcode243
//https://www.nowcoder.com/practice/2c6a0a8e1d20492f92941400036e0890?tpId=101&tqId=33190&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string str1, str2;
	cin >> str1 >> str2;
	vector<string> strs(n, "");//初始化！！！！
	for (int i = 0; i<n; ++i)
	{
		cin >> strs[i];
	}

	int exist1 = -1, exist2 = -1;
	int res = INT_MAX;
	for (int i = 0; i<n; ++i)
	{
		if (strs[i] == str1)
		{
			exist1 = i;
		}
		if (strs[i] == str2)
		{
			exist2 = i;
		}
		if (exist1 != -1 && exist2 != -1)
		{
			if (res>abs(exist1 - exist2))
			{
				res = abs(exist1 - exist2);
			}
		}
	}
	if (res == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << res;
	}
	return 0;
}


//进阶
class Record
{
public:
	Record(vector<string> strs)
	{
		unordered_map<string, int> indexMap;
		/*for (int i = 0; i < strArr.size(); ++i)
		{
			string curStr = strArr[i];
			update(indexMap, curStr, i);
			indexMap.insert(make_pair(curStr, i));
		}*/
		for (int i = 0; i < strs.size(); ++i)
		{
			update(indexMap, strs[i], i);
			indexMap[strs[i]] = i;
		}
	}
	void update(unordered_map<string, int> indexMap, string str, int i)//str是外层（索引是i），key是内层（索引是index）
	//和当前值的前面的值相比
	{
		for (auto &lastEntry : indexMap)
		{
			string key = lastEntry.first;
			int index = lastEntry.second;
		/*for (auto lastEntry = indexMap.begin(); lastEntry != indexMap.end(); ++lastEntry)
		{
			string key = (*lastEntry).first;
			int index = (*lastEntry).second;*/
			if (key != str)
			{
				int curMin = i - index;
				if (record[str].count(key))
				{
					int preMin = record[str][key];
					if (curMin < preMin)
					{
						record[str][key] = curMin;
						record[key][str] = curMin;
					}
				}
				else
				{
					record[str][key] = curMin;
					record[key][str] = curMin;
				}
			}
		}
	}
	int minDstance(string str1, string str2)
	{
		if (str1 == "" || str2 == "")
		{
			return -1;
		}
		if (str1 == str2)
		{
			return 0;
		}
		if (record.count(str1) && record[str1].count(str2))
		{
			return record[str1][str2];
		}
		return -1;
	}
private:
	unordered_map<string, unordered_map<string, int>> record;
};

int main()
{
	vector<string> strArr = { "1","3","3","3","2","3","1" };
	string str1 = "1", str2 = "2";
	Record record(strArr);
	int result = record.minDstance(str1, str2);
	cout << result;
	return 0;
}

//进阶。输入输出
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
using namespace std;
class Record
{
public:
	Record(vector<string> strArr)
	{
		unordered_map<string, int> indexMap;
		for (int i = 0; i < strArr.size(); ++i)
		{
			string curStr = strArr[i];
			update(indexMap, curStr, i);
			indexMap.insert(make_pair(curStr, i));
		}
	}
	void update(unordered_map<string, int> indexMap, string str, int i)//str是外层（索引是i），key是内层（索引是index）
	{
		for (auto lastEntry = indexMap.begin(); lastEntry != indexMap.end(); ++lastEntry)
		{
			string key = (*lastEntry).first;
			int index = (*lastEntry).second;
			if (key != str)
			{
				int curMin = i - index;
				if (record[str].count(key))
				{
					int preMin = record[str][key];
					if (curMin < preMin)
					{
						record[str][key] = curMin;
						record[key][str] = curMin;
					}
				}
				else
				{
					record[str][key] = curMin;
					record[key][str] = curMin;
				}
			}
		}
	}
	int minDstance(string str1, string str2)
	{
		if (str1 == "" || str2 == "")
		{
			return -1;
		}
		if (str1 == str2)
		{
			return 0;
		}
		if (record.count(str1) && record[str1].count(str2))
		{
			return record[str1][str2];
		}
		return -1;
	}
private:
	unordered_map<string, unordered_map<string, int>> record;
};

int main()
{
	int n;
	cin >> n;
	string str1, str2;
	cin >> str1 >> str2;
	vector<string> strs(n, "");//初始化！！！！
	for (int i = 0; i<n; ++i)
	{
		cin >> strs[i];
	}

	Record record(strs);
	int result = record.minDstance(str1, str2);
	cout << result;
	return 0;
}