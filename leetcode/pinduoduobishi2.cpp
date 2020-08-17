#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int, int> types;

int get_type(int k) {
	auto itr = types.find(k);
	if (k == itr->second) {
		return k;
	}
	return get_type(itr->second);
}

int main()
{

	int arr[] = { 1,2,3,4,5,6 };
	do
	{
		int value = arr[0] * 100000 + arr[1] * 10000;
		value += arr[2] * 1000 + arr[3] * 100;
		value += arr[4] * 10 + arr[5];
		types.insert(pair<int, int>(value, value));
	} while (next_permutation(arr, arr + 6));

	map<int, int>::iterator itr, itr2;
	for (itr = types.begin(); itr != types.end(); ++itr) {
		int k = itr->first;
		int v = itr->second;
		int nextK, nextV;

		int up = k / 100000 % 10;
		int down = k / 10000 % 10;
		int left = k / 1000 % 10;
		int right = k / 100 % 10;
		int front = k / 10 % 10;
		int back = k % 10;

		// up
		nextK = front * 100000 + back * 10000;
		nextK += left * 1000 + right * 100;
		nextK += down * 10 + up;

		itr2 = types.find(nextK);
		if (itr2 != types.end()) {
			//cout << itr2->first << '\t' << itr2->second << '\n'; 
			nextV = min(itr2->second, v);
			//cout<<nextK<<"->"<<nextV<<endl;
			//cout<<k<<"->"<<nextV<<endl;
			itr->second = nextV;
			itr2->second = nextV;
		}

		// down
		nextK = back * 100000 + front * 10000;
		nextK += left * 1000 + right * 100;
		nextK += up * 10 + down;
		itr2 = types.find(nextK);
		if (itr2 != types.end()) {
			//cout << itr2->first << '\t' << itr2->second << '\n'; 
			nextV = min(itr2->second, v);
			//cout<<nextK<<"->"<<nextV<<endl;
			//cout<<k<<"->"<<nextV<<endl;
			itr->second = nextV;
			itr2->second = nextV;
		}

		// lef
		nextK = up * 100000 + down * 10000;
		nextK += front * 1000 + back * 100;
		nextK += right * 10 + left;
		itr2 = types.find(nextK);
		if (itr2 != types.end()) {
			//cout << itr2->first << '\t' << itr2->second << '\n'; 
			nextV = min(itr2->second, v);
			//cout<<nextK<<"->"<<nextV<<endl;
			//cout<<k<<"->"<<nextV<<endl;
			itr->second = nextV;
			itr2->second = nextV;
		}

		// right
		nextK = up * 100000 + down * 10000;
		nextK += back * 1000 + front * 100;
		nextK += left * 10 + right;
		itr2 = types.find(nextK);
		if (itr2 != types.end()) {
			//cout << itr2->first << '\t' << itr2->second << '\n'; 
			nextV = min(itr2->second, v);
			//cout<<nextK<<"->"<<nextV<<endl;
			//cout<<k<<"->"<<nextV<<endl;
			itr->second = nextV;
			itr2->second = nextV;
		}

		// front
		nextK = right * 100000 + left * 10000;
		nextK += up * 1000 + down * 100;
		nextK += front * 10 + back;
		itr2 = types.find(nextK);
		if (itr2 != types.end()) {
			//cout << itr2->first << '\t' << itr2->second << '\n'; 
			nextV = min(itr2->second, v);
			//cout<<nextK<<"->"<<nextV<<endl;
			//cout<<k<<"->"<<nextV<<endl;
			itr->second = nextV;
			itr2->second = nextV;
		}

		// back
		nextK = left * 100000 + right * 10000;
		nextK += down * 1000 + up * 100;
		nextK += front * 10 + back;
		itr2 = types.find(nextK);
		if (itr2 != types.end()) {
			//cout << itr2->first << '\t' << itr2->second << '\n'; 
			nextV = min(itr2->second, v);
			//cout<<nextK<<"->"<<nextV<<endl;
			//cout<<k<<"->"<<nextV<<endl;
			itr->second = nextV;
			itr2->second = nextV;
		}
	}

	int n;
	cin >> n;

	map<int, int> counts;

	while (n--) {
		int up, down, left, right, front, back;
		cin >> up >> down >> left >> right >> front >> back;

		int v = up * 100000 + down * 10000;
		v += left * 1000 + right * 100;
		v += front * 10 + back;
		int t = get_type(v);
		//cout<<t<<endl;

		auto itr = counts.find(t);
		if (itr == counts.end()) {
			counts.insert(pair<int, int>(t, 0));
		}
		itr = counts.find(t);
		itr->second = itr->second + 1;
	}

	vector<int> res;
	for (auto itr : counts)
		res.push_back(itr.second);

	sort(res.begin(), res.end(), greater<int>());

	bool flag = false;
	for (auto itr : res) {
		if (flag) {
			cout << " ";
		}
		cout << itr;
		flag = true;
	}
	cout << endl;


	return 0;
}



//自己写的，再加上去在map里看两个标签是否一样，就可以知道这两个是不是可以相互转化的骰子了
//一个骰子向六个方向旋转
vector<string> trans(string tmp)
{
	vector<string> res;
	stringstream tmp2;
	char str[7];
	sprintf_s(str, "%c%c%c%c%c%c", tmp[5], tmp[4], tmp[2], tmp[3], tmp[0], tmp[1]);
	res.push_back(string(str));
	sprintf_s(str, "%c%c%c%c%c%c", tmp[4], tmp[5], tmp[2], tmp[3], tmp[1], tmp[0]);
	res.push_back(string(str));
	sprintf_s(str, "%c%c%c%c%c%c", tmp[0], tmp[1], tmp[5], tmp[4], tmp[2], tmp[3]);
	res.push_back(string(str));
	sprintf_s(str, "%c%c%c%c%c%c", tmp[0], tmp[1], tmp[4], tmp[5], tmp[3], tmp[2]);
	res.push_back(string(str));
	sprintf_s(str, "%c%c%c%c%c%c", tmp[3], tmp[2], tmp[0], tmp[1], tmp[4], tmp[5]);
	res.push_back(string(str));
	sprintf_s(str, "%c%c%c%c%c%c", tmp[2], tmp[3], tmp[1], tmp[0], tmp[4], tmp[5]);
	res.push_back(string(str));
	return res;
}

//得到720种全排列
vector<string> permutation()
{
	vector<string> res;
	string tmp = "123456";
	res.push_back(tmp);
	while (next_permutation(tmp.begin(), tmp.end()))
	{
		res.push_back(tmp);
	}
	return res;
}

//合并标签和路径压缩
string get_tag(string str, unordered_map<string, string> &m)
{
	string tag = str;
	while (m[tag] != tag)
	{
		tag = m[tag];
	}
	m[str] = tag;
	return tag;
}

int main()
{
	vector<string> res = permutation();//720
	vector<string> transres;
	unordered_map<string, string> m;
	for (int i = 0; i < res.size(); ++i)
	{
		m[res[i]] = res[i];//初始标签就是自己
	}
	for (int i = 0; i < res.size(); ++i)
	{
		vector<string> tmp = trans(res[i]);
		string minstr = get_tag(res[i], m);
		for (int j = 0; j < 6; ++j)
		{
			if (minstr > get_tag(tmp[j], m))
			{
				minstr = get_tag(tmp[j], m);
			}
		}//6个变换加上它本身，选择其中最小的标签作为这 7个的标签
		for (int j = 0; j < 6; ++j)
		{
			m[tmp[j]] = minstr;
		}
	}
	int cnttag = 0;
	unordered_set<string> us;
	//计算一下一共有多少种
	for (int i = 0; i < res.size(); ++i)
	{
		if (!us.count(get_tag(res[i], m)))
		{
			us.insert(get_tag(res[i], m));
			++cnttag;
		}
		//cout << m[res[i]] << " ";
	}
	cout << cnttag;
	return 0;
}