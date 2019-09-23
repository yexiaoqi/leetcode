class Solution {
public:
	int longestValidParentheses(string s) {
		//(())����Ҳ����������Ч��
		//���±����ջ���������ű���
		//������(())���ܶ��ˣ���ѹ��ջ�±�0����ѹ��1��Ȼ�󵯳�1��par��Ϊ�գ�res=2-0��Ȼ�󵯳�0��parΪ�գ�res=3-0+1
		stack<int> par;
		int res = 0, start = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			if (s[i] == '(')
			{
				par.push(i);
			}
			else
			{

				if (par.empty())
				{
					start = i + 1;
				}
				else
				{
					par.pop();
					res = par.empty() ? max(res, i - start + 1) : max(res, i - par.top());
				}

			}
		}
		return res;
	}
};