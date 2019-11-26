//自己的方法
class Solution {
public:
	string removeKdigits(string num, int k) {
		stack<char> s;
		s.push(num[0]);
		for (int i = 0; i<int(num.length() - 1); ++i)
		{
			while (!s.empty() && ((num[i + 1] - '0')<s.top() - '0') && k>0)//注意!s.empty()，否则如果为空那么调用s.top()会出错，而且!s.empty()必须第一个判断
				//if(((num[i+1]-'0')<(num[i]-'0'))&&k>0)
			{
				s.pop();
				//s.push(num[i + 1]);
				//++i;
				--k;
			}
			//else

			{
				s.push(num[i + 1]);
			}
		}
		while (k>0)
		{
			s.pop();
			--k;
		}
		stack<char> revers;
		while (!s.empty())
		{
			revers.push(s.top());
			s.pop();
		}
		string res;
		if (revers.empty())
		{
			return "0";
		}
		while (!revers.empty() && revers.top() == '0')
		{

			revers.pop();
		}
		if (revers.empty())
		{
			return "0";
		}

		while (!revers.empty())
		{
			// res=revers.top()+res;
			res.append(1, revers.top());//添加几个相同的字符:如str1.append(5, '.');注意,个数在前字符在后.上面的代码意思为在str1后面添加5个".".
			revers.pop();
		}
		return res;
	}
};

//用vector实现栈，由于vector可以遍历，不用像上面那样倒过来一次
class Solution {
public:
	string removeKdigits(string num, int k) {
		vector<char> s;
		for (int i = 0; i<int(num.length()); ++i)
		{
			while (!s.empty() && ((num[i] - '0')<s[s.size() - 1] - '0') && k>0)
			{
				s.pop_back();
				--k;
			}
			if (s.size() != 0 || num[i] != '0')
			{
				s.push_back(num[i]);
			}
		}
		while (s.size() != 0 && k>0)
		{
			s.pop_back();
			--k;
		}
		string res;
		for (int i = 0; i<s.size(); ++i)
		{
			res.append(1, s[i]);//添加几个相同的字符:如str1.append(5, '.');注意,个数在前字符在后.上面的代码意思为在str1后面添加5个".".
		}
		if (res == "")
		{
			return "0";//注意特殊情况
		}
		return res;
	}
};