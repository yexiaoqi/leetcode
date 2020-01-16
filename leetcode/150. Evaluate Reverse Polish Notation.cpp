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
				S.push(op(op1, op2, tokens[i][0]));//����tokens[i]������tokens[i]��"/",tokens[i][0]��/
			}
			else
			{
				S.push(stoi(tokens[i]));//תΪint
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
				//���벻��+����+"
			{
				res.push(stoi(tokens[i]));//stoi()�������ַ���ת����int�����������Χ��飬Ĭ�Ϸ�Χ����int�ķ�Χ�ڵģ����������Χ�Ļ����runtime error
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


//��ϰ���Լ�����
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
			if (tokens[i] != "+"&&tokens[i] != "-"&&tokens[i] != "*"&&tokens[i] != "/")//�����жϸ�����
			//if(tokens[i]>="0"&&tokens[i]<="9"||tokens[i].size()>1)//tokens[i].size()>1��Ը����ͳ���һλ������
			{
				s.push(stoi(tokens[i]));//ע��ת��Ϊint
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