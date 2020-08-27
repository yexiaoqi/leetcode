class Solution {
public:
	int minAddToMakeValid(string str) {
		int left = 0, right = 0;
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] == '(')
			{
				++right;
			}
			else
			{
				if (right>0)
				{
					--right;
				}
				else
				{
					++left;
				}
			}
		}
		return left + right;
	}
};