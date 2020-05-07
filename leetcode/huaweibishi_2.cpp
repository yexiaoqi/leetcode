/*
read read[addr=0x17,mask=0xff,val=0x7],read_his[addr=0xff,mask=0xff,val=0x1],read[addr=0xf0,mask=0xff,val=0x80]

read read[addr=0x17,mask=0xff,val=0x7],read_his[addr=0xff,mask=0xff,val=0x1],read[addr=0xf0,mask=0xff,val=0x80]

*/

#include <iostream>
#include<string>
#include<vector>

using namespace std;

bool isHex(string str) {
	if (str.size() <3) {
		return false;
	}
	if (str[0] != '0') {
		return false;
	}
	if (str[1] != 'x' && str[1] != 'X') {
		return false;
	}
	for (int i = 2; i<str.size(); i++) {
		if (!((str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F') || (str[i] >= '0' && str[i] <= '9'))) {
			return false;
		}
	}
	return true;
}

vector<string> split(string str, string delimiter) {
	vector<string> res;

	//cout<<str<<endl;

	size_t pre = 0;
	size_t pos = str.find(delimiter);
	while (pos != string::npos) {
		res.push_back(str.substr(pre, pos - pre));
		pre = pos + 1;
		pos = str.find(delimiter, pos + delimiter.size());
	}
	if (pre != str.size() - 1) {
		res.push_back(str.substr(pre));
	}

	for (auto & s : res) {
		//cout<<s<<endl;
	}

	return res;
}

int match(size_t pos, string opt, string txt) {
	size_t end = txt.find("]", pos);
	if (end == string::npos) {
		return 0;
	}

	vector<string> options = split(txt.substr(pos, end - pos), ",");
	if (options.size() != 3) {
		return 0;
	}

	string s[] = { "addr", "mask", "val" };
	vector<string> res;
	for (int i = 0; i<3; i++) {
		vector<string> kv = split(options[i], "=");
		if (kv.size() != 2) {
			return 0;
		}
		if (kv[0] != s[i]) {
			return 0;
		}
		if (!isHex(kv[1])) {
			return 0;
		}
		res.push_back(kv[1]);
	}
	cout << res[0] << " " << res[1] << " " << res[2] << endl;
	return 1;
}

int main()
{
	string opt, txt;

	cin >> opt >> txt;

	opt = opt + "[";

	//cout<<txt<<endl;

	size_t pos = txt.find(opt);

	int sum = 0;

	while (pos != std::string::npos)
	{
		//cout<<pos<<endl;

		sum += match(pos + opt.size(), opt, txt);

		pos = txt.find(opt, pos + opt.size());
	}

	if (sum == 0) {
		cout << "FAIL" << endl;
	}

	return 0;
}
