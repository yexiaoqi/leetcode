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
			switch (c)//注意switch中的内容加{}
			{
			case '(':
			case '[':
			case '{':par.push(c); break;//这四个break一个不能少，比如这里如果没有break，就会执行下面一个if而不判断case ')'
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
		}*///空字符串是有效的
		for (int i = 0; i<s.size(); ++i)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				parentheses.push(s[i]);
			}
			else
			{
				if (parentheses.empty()) return false;//针对没有左括号就出现右括号的情况
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