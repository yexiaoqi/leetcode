//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are + , -, *, / .Each operand may be an integer or another expression.
//
//Some examples :
//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution
{
public:
	int evalRPN(vector<string>& tokens)
	{
		int len = tokens.size();
		stack<int> S;
		for (int i = 0;i<tokens.size();++i)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				int op1 = S.top();S.pop();
				int op2 = S.top();S.pop();
				S.push(op(op1, op2, tokens[i][0]));//不是tokens[i]，比如tokens[i]是"/",tokens[i][0]是/
			}
			else
			{
				S.push(stoi(tokens[i]));//转为int
			}
		}
		return S.top();
	}
	int op(int op1, int op2, char optor)
	{
		if (optor == '+')
		{
			return op1 + op2;
		}
		if (optor == '-')
		{
			return op2 - op1;
		}
		if (optor == '*')
		{
			return op1*op2;
		}
		if (optor == '/')
		{
			return op2 / op1;
		}
	}
};



class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> res;
		for (int i = 0; i<tokens.size(); ++i)
		{
			if ((tokens[i] != "+") && (tokens[i] != "-") && (tokens[i] != "*") && (tokens[i] != "/"))
				//输入不是+而是+"
			{
				res.push(stoi(tokens[i]));//stoi()把数字字符串转换成int输出，会做范围检查，默认范围是在int的范围内的，如果超出范围的话则会runtime error
			}
			else
			{
				int one = res.top();
				res.pop();
				int two = res.top();
				res.pop();
				if (tokens[i] == "+")
				{
					res.push(one + two);
				}
				if (tokens[i] == "-")
				{
					res.push(two - one);
				}
				if (tokens[i] == "*")
				{
					res.push(one*two);
				}
				if (tokens[i] == "/")
				{
					res.push(two / one);
				}
			}
		}
		return res.top();
	}
};


//复习，自己做出
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		if (tokens.size() == 0)
		{
			return 0;
		}
		for (int i = 0; i<tokens.size(); ++i)
		{
			if (tokens[i] != "+"&&tokens[i] != "-"&&tokens[i] != "*"&&tokens[i] != "/")//这种判断更清晰
			//if(tokens[i]>="0"&&tokens[i]<="9"||tokens[i].size()>1)//tokens[i].size()>1针对负数和超过一位的正数
			{
				s.push(stoi(tokens[i]));//注意转化为int
			}
			else
			{
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				int sum = 0;
				if (tokens[i] == "+")
				{
					sum = num1 + num2;
				}
				else if (tokens[i] == "-")
				{
					sum = num2 - num1;
				}
				else if (tokens[i] == "*")
				{
					sum = num2*num1;
				}
				else
				{
					sum = num2 / num1;
				}
				s.push(sum);
			}
		}
		return s.top();
	}
};