//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> par;
		for (char c : s)
		{
			switch (c)//ע��switch�е����ݼ�{}
			{
			case '(':
			case '[':
			case '{':par.push(c); break;//���ĸ�breakһ�������٣������������û��break���ͻ�ִ������һ��if�����ж�case ')'
			case ')':
				if (par.empty() || par.top() != '(')
				{
					return false;
				}
				else
				{
					par.pop();
				}
				break;
			case ']':
				if (par.empty() || par.top() != '[')
				{
					return false;
				}
				else
				{
					par.pop();
				}
				break;
			case '}':
				if (par.empty() || par.top() != '{')
				{
					return false;
				}
				else
				{
					par.pop();
				}
				break;
			}
		}
		return par.empty();
	}
};




class Solution {
public:
	bool isValid(string s) {
		stack<char> parentheses;
		/*if(s.size()==0)
		{
		return false;
		}*///���ַ�������Ч��
		for (int i = 0; i<s.size(); ++i)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				parentheses.push(s[i]);
			}
			else
			{
				if (parentheses.empty()) return false;//���û�������žͳ��������ŵ����
													  /* if (s[i] == ')' && parentheses.top() != '(') return false;
													  if (s[i] == ']' && parentheses.top() != '[') return false;
													  if (s[i] == '}' && parentheses.top() != '{') return false;
													  parentheses.pop();*/

				if ((s[i] == ')'&&parentheses.top() != '(') || (s[i] == '}'&&parentheses.top() != '{') || (s[i] == ']'&&parentheses.top() != '['))
				{
					return false;
				}
				parentheses.pop();
			}


		}
		return parentheses.empty();
	}
};


//��ϰ
//�Լ������ķ���
class Solution {
public:
	bool isValid(string s) {
		if (s.size() == 0)
		{
			return true;
		}
		stack<char> st;
		for (int i = 0; i<s.size(); ++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				st.push(s[i]);
			}
			else if (s[i] == ')')
			{
				if (st.empty() || st.top() != '(')//��Ҫ©��st.empty()��ֱ�����������ŵ������������top��Ӧ���뵽�ж��Ƿ���empty
				{
					return false;

				}
				else
				{
					st.pop();
				}
			}
			else if (s[i] == ']')
			{
				if (st.empty() || st.top() != '[')
				{
					return false;

				}
				else
				{
					st.pop();
				}
			}
			else
			{
				if (st.empty() || st.top() != '{')
				{
					return false;

				}
				else
				{
					st.pop();
				}
			}
		}
		return st.empty() ? true : false;
	}
};


//�򻯰�
class Solution {
public:
	bool isValid(string s) {
		if (s.size() == 0)
		{
			return true;
		}
		stack<char> st;
		for (int i = 0; i<s.size(); ++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				st.push(s[i]);
			}
			else
			{
				if (st.empty())
				{
					return false;
				}
				if (s[i] == ')'&&st.top() != '(')
				{
					return false;
				}
				if (s[i] == ']'&&st.top() != '[')
				{
					return false;
				}
				if (s[i] == '}'&&st.top() != '{')
				{
					return false;
				}
				st.pop();
			}
			// else if(s[i]==')')
			// {
			//     if(st.empty()||st.top()!='(')//��Ҫ©��st.empty()��ֱ�����������ŵ������������top��Ӧ���뵽�ж��Ƿ���empty
			//     {
			//         return false;

			//     }
			//     else
			//     {
			//         st.pop();
			//     }
			// }
			// else if(s[i]==']')
			// {
			//     if(st.empty()||st.top()!='[')
			//     {
			//         return false;

			//     }
			//     else
			//     {
			//         st.pop();
			//     }
			// }
			// else
			// {
			//     if(st.empty()||st.top()!='{')
			//     {
			//         return false;

			//     }
			//     else
			//     {
			//         st.pop();
			//     }
			// }
		}
		return st.empty() ? true : false;
	}
};

//��ϰ���򵥣�һ��ac
class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		if (s.empty())
		{
			return true;
		}
		for (int i = 0; i<s.size(); ++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				st.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
			{
				if (st.empty())
				{
					return false;
				}
				if (s[i] == ')'&&st.top() != '(')
				{
					return false;
				}
				if (s[i] == ']'&&st.top() != '[')
				{
					return false;
				}
				if (s[i] == '}'&&st.top() != '{')
				{
					return false;
				}
				st.pop();
			}
			else
			{
				return false;
			}
		}
		return st.empty();
	}
};