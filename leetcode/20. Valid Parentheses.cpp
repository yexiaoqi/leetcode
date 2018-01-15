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