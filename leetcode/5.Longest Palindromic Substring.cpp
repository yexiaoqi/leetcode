//https://windliang.cc/2019/06/24/%E4%B8%80%E6%96%87%E8%AE%A9%E4%BD%A0%E5%BD%BB%E5%BA%95%E6%98%8E%E7%99%BD%E9%A9%AC%E6%8B%89%E8%BD%A6%E7%AE%97%E6%B3%95/
class Solution {
public:
	string longestPalindrome(string s) {
		string t = "$#";
		for (int i = 0; i < s.size(); ++i) {
			t += s[i];
			t += '#';
		}
		int p[t.size()] = { 0 }, id = 0, mx = 0, resId = 0, resMx = 0;
		for (int i = 1; i < t.size(); ++i) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;//����R������߽�ʱ��ѡmx-i
			while (t[i + p[i]] == t[i - p[i]]) ++p[i];//������߽�ʱ���ұ߻����Լ�����չ
			if (mx < i + p[i]) //������� P [ i ] ���ұ߽���ڵ�ǰ�ұ߽�mxʱ
			{
				mx = i + p[i];
				id = i;
			}
			if (resMx < p[i]) //resMx�ǰ뾶
			{
				resMx = p[i];
				resId = i;
			}
		}
		return s.substr((resId - resMx) / 2, resMx - 1);//��Ӵ��ĳ����ǰ뾶��1����ʼλ�����м�λ�ü�ȥ�뾶�ٳ���2��
	}
};