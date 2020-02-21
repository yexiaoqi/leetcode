class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0, istar = -1, jstar = -1, m = s.size(), n = p.size();
		while (i<m)
		{
			if (j<n && (p[j] == s[i] || p[j] == '?'))
			{
				++i, ++j;
			}
			else if (j<n&&p[j] == '*')
			{
				istar = i;//istar���� (p[j] == s[i] || p[j] == '?')ƥ���ϵ�λ��
				jstar = j;//jstar��*��λ��
				++j;
			}
			else if (istar >= 0)
			{
				i = istar;
				++istar;
				j = jstar + 1;
			}
			else
			{
				return false;
			}
		}
		while (j<n&&p[j] == '*')
		{
			++j;
		}
		return j == n;
	}
};