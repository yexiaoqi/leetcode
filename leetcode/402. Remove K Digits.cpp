//�Լ��ķ���
class Solution {
public:
	string removeKdigits(string num, int k) {
		stack<char> s;
		s.push(num[0]);
		for (int i = 0; i<int(num.length() - 1); ++i)
		{
			while (!s.empty() && ((num[i + 1] - '0')<s.top() - '0') && k>0)//ע��!s.empty()���������Ϊ����ô����s.top()���������!s.empty()�����һ���ж�
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
			res.append(1, revers.top());//��Ӽ�����ͬ���ַ�:��str1.append(5, '.');ע��,������ǰ�ַ��ں�.����Ĵ�����˼Ϊ��str1�������5��".".
			revers.pop();
		}
		return res;
	}
};

//��vectorʵ��ջ������vector���Ա�������������������������һ��
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
			res.append(1, s[i]);//��Ӽ�����ͬ���ַ�:��str1.append(5, '.');ע��,������ǰ�ַ��ں�.����Ĵ�����˼Ϊ��str1�������5��".".
		}
		if (res == "")
		{
			return "0";//ע���������
		}
		return res;
	}
};