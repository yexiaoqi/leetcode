class Solution {
public:
	void print1ton(int n)
	{
		string str = "";
		print1tonrecur(str, n, 0);
	}
	void print1tonrecur(string &str, int n, int index)
	{
		if (index == n)
		{
			print(str);
			return;
		}
		for (int i = 0; i < 10; ++i)
		{
			//str[index]= i + '0';
			str += to_string(i);
			print1tonrecur(str, n, index + 1);
			str.pop_back();
		}
	}
	void print(string &str)
	{
		bool isbegin0 = true;
		for (int i = 0; i < str.size(); ++i)
		{
			if (isbegin0&&str[i] != '0')
			{
				isbegin0 = false;
			}
			if (!isbegin0)
			{
				cout << str[i];
			}
		}
		cout << endl;
	}
};