class Solution {
public:
	int longestValidParentheses(string s) {
		//(())这种也算有两个有效的
		//将下标加入栈而不是括号本身
		//举例子(())就能懂了，先压入栈下标0，再压入1，然后弹出1，par不为空，res=2-0，然后弹出0，par为空，res=3-0+1
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