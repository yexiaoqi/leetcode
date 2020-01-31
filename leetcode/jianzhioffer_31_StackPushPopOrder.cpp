//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳������4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		int j = 0;
		for (int i = 0; i<int(pushV.size()); ++i)
		{
			if (pushV[i] != popV[j])
			{
				s.push(pushV[i]);
			}
			else
			{
				++j;
			}
		}
		for (j; j<int(pushV.size()); ++j)
		{
			if (s.top() == popV[j])
			{
				s.pop();
			}
		}
		if (s.empty())
		{
			return true;
		}
		return false;
	}
};

//��ϰ���Լ��ķ���
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		int i = 0;
		int j = 0;
		while (i<pushV.size())
		{
			/*if (!s.empty() && s.top() == popV[j])
			{
				s.pop();
				++j;
				continue;
			}*/
			if (pushV[i] != popV[j])
			{
				s.push(pushV[i]);
				++i;
				continue;
			}
			if (i >= pushV.size())
			{
				return false;
			}
			++i;
			++j;
		}
		while (!s.empty())
		{
			if (s.top() != popV[j])
			{
				return false;
			}
			s.pop();
			++j;
		}
		return true;
	}
};