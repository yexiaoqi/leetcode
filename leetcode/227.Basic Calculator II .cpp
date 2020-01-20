//����д���ԣ�����3+2*2��st����3����3*2�ˣ�Ӧ��������һ��'+'
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


//��ȷ�ⷨ
//����д���ԣ�����3+2*2��st����3����3*2�ˣ�Ӧ��������һ��'+'
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
					num = num * 10 + (s[i] - '0');//ע��s[i]-'0'Ҫ�ӣ�������������
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