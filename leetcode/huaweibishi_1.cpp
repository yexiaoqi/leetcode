//评选明日之星，规则如下：1.票数多当选2.如果票数一致，则按照姓名字典序排序，字典序小的当选
//每个人的姓名首字母大写，其他字母小写，如果有不符合条件的输入直接输出error.0001返回
//输入是一个字符串，以，进行分割，比如Lucy,Tom,Lucy,Tim





bool compare(pair<string, int> str1, pair<string, int> str2)
{
	if (str1.second == str2.second)
	{
		return str1.first < str2.first;
	}
	return str1.second > str2.second;
}
int main()
{
	string inname;
	cin >> inname;
	vector<string> names;
	string tmp = "";
	if (inname[0] == ',')
	{
		cout << "error.0001" << endl;
		return 0;
	}
	for (int i = 0; i < inname.size(); ++i)
	{
		if (inname[i] == ',')
		{
			names.push_back(tmp);
			tmp = "";
			continue;
		}
		if (tmp == "")
		{
			if (!(inname[i] >= 'A'&&inname[i] <= 'Z'))
			{
				cout << "error.0001" << endl;
				return 0;
			}
			else
			{
				tmp += inname[i];
			}
		}
		else
		{
			if (!(inname[i] >= 'a'&&inname[i] <= 'z'))
			{
				cout << "error.0001" << endl;
				return 0;
			}
			else
			{
				tmp += inname[i];
			}
		}
	}
	names.push_back(tmp);
	unordered_map<string, int> m;
	for (int i = 0; i < names.size(); ++i)
	{
		
		++m[names[i]];
	}
	vector<pair<string, int>> allnameforsort;
	for (auto a = m.begin(); a != m.end(); ++a)
	{
		allnameforsort.push_back((*a));
	}
	sort(allnameforsort.begin(), allnameforsort.end(), compare);
	cout << allnameforsort[0].first << endl;
	return 0;
}