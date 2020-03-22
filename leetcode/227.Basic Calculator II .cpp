//这样写不对，导致3+2*2，st里是3，用3*2了，应该先设置一个'+'
class Solution {
public:
	int calculate(string s) {
		int res = 0, num = 0, n = s.size();
		stack<int> st;
		for (int i = 0; i<n; ++i)
		{
			if (s[i] >= '0'&&s[i] <= '9')
			{
				while (i<n&&s[i] >= '0'&&s[i] <= '9')
				{
					num = num * 10 + s[i] - '0';
					++i;
				}
				--i;
			}
			else
			{
				if (s[i] == '+')
				{
					st.push(num);
				}
				else if (s[i] == '-')
				{
					st.push(-num);
				}
				else if (s[i] == '*' || s[i] == '/')
				{
					int tmp = s[i] == '*' ? st.top()*num : st.top() / num;
					st.pop();
					st.push(tmp);
				}
				num = 0;
			}

		}
		while (!st.empty())
		{
			res += st.top();
			st.pop();
		}
		return res;
	}
};


//正确解法
//使用一个栈保存数字，如果该数字之前的符号是加或减，那么把当前数字压入栈中，注意如果是减号，
//则加入当前数字的相反数，因为减法相当于加上一个相反数。如果之前的符号是乘或除，
//那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中，那么完成一遍遍历后，
//所有的乘或除都运算完了，再把栈中所有的数字都加起来就是最终结果了
class Solution {
public:
	int calculate(string s) {
		int res = 0, num = 0, n = s.size();
		stack<int> st;
		char c = '+';
		for (int i = 0; i<n; ++i)
		{
			if (s[i] >= '0'&&s[i] <= '9')
			{
				while (i<n&&s[i] >= '0'&&s[i] <= '9')
				{
					num = num * 10 + (s[i] - '0');//注意s[i]-'0'要加（），否则会溢出
					++i;
				}
				--i;
			}
			if (s[i] == '-' || s[i] == '+' || s[i] == '/' || s[i] == '*' || i == n - 1)
			{
				if (c == '+')
				{
					st.push(num);
				}
				else if (c == '-')
				{
					st.push(-num);
				}
				else if (c == '*' || c == '/')
				{
					int tmp = c == '*' ? st.top()*num : st.top() / num;
					st.pop();
					st.push(tmp);
				}
				c = s[i];
				num = 0;
			}


		}
		while (!st.empty())
		{
			res += st.top();
			st.pop();
		}
		return res;
	}
};


//
class Solution{
public:
	int calculate(string s) {
		int res = 0, num = 0, n = s.size();
		stack<int> st;
		char c = '+';
		for (int i = 0; i<n; ++i)
		{
			// if (s[i] >= '0'&&s[i] <= '9')
			// {
			// 	while (i<n&&s[i] >= '0'&&s[i] <= '9')
			// 	{
			// 		num = num * 10 + (s[i] - '0');//注意s[i]-'0'要加（），否则会溢出
			// 		++i;
			// 	}
			// 	--i;
			// }
			if (s[i] >= '0'&&s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
			}
			if (s[i] == '-' || s[i] == '+' || s[i] == '/' || s[i] == '*' || i == n - 1)
			{
				if (c == '+')
				{
					st.push(num);
				}
				else if (c == '-')
				{
					st.push(-num);
				}
				else if (c == '*' || c == '/')
				{
					int tmp = c == '*' ? st.top()*num : st.top() / num;
					st.pop();
					st.push(tmp);
				}
				c = s[i];
				num = 0;
			}


		}
		while (!st.empty())
		{
			res += st.top();
			st.pop();
		}
		return res;
	}
};