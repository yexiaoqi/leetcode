//https://windliang.cc/2019/06/24/%E4%B8%80%E6%96%87%E8%AE%A9%E4%BD%A0%E5%BD%BB%E5%BA%95%E6%98%8E%E7%99%BD%E9%A9%AC%E6%8B%89%E8%BD%A6%E7%AE%97%E6%B3%95/
//�������㷨�ĵ�һ����Ԥ������������ÿһ���ַ������Ҷ�����һ�������ַ���������� '#'
//Ȼ��Ҫ��ǰ������һ���ַ�������ַ�������#�ţ�Ҳ������s�п��ܳ��ֵ��ַ��������������Ҿ�����Ԫ�Ű�
//��Ӵ��ĳ����ǻ��Ĵ��뾶��1����ʼλ�����м�λ�ü�ȥ�뾶�ٳ���2��
//O��n)���Ӷ�
class Solution {
public:
	string longestPalindrome(string s) {
		string t = "$#";
		for (int i = 0; i < s.size(); ++i) {
			t += s[i];
			t += '#';
		}
		//p[i] ��ʾ�� t[i] �ַ�Ϊ���ĵĻ����Ӵ��İ뾶
		int p[t.size()] = { 0 }, id = 0, mx = 0, resId = 0, resMx = 0;
//��Ҫ���������������� mx �� id������ id Ϊ�����쵽���Ҷ˵�λ�õ��Ǹ������Ӵ������ĵ�λ�ã�
//mx �ǻ��Ĵ������쵽�����Ҷ˵�λ�ã���Ҫע����ǣ���� mx λ�õ��ַ������ڻ��Ĵ�
//�����Բ����� mx - i ������ p[i] �ĳ��ȶ����ü�1
		for (int i = 1; i < t.size(); ++i) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;//����R������߽�ʱ��ѡmx-i
			//���� mx <= i ��������޷��� P[i] ������ļ��裬ֻ�� P[i] = 1��Ȼ����ȥƥ���ˡ�

//�� mx - i > P[j] ��ʱ���� S[j] Ϊ���ĵĻ����Ӵ��������� S[id] Ϊ���ĵĻ����Ӵ��У����� i �� j �Գƣ�
//�� S[i] Ϊ���ĵĻ����Ӵ���Ȼ�������� S[id] Ϊ���ĵĻ����Ӵ��У����Ա��� P[i] = P[j]������ j = 2 * id - i��
//��Ϊ j �� id ֮�䵽������� id �� i ֮�䵽���룬Ϊ i - id������ j = id - (i - id) = 2 * id - i


//�� P[j] >= mx - i ��ʱ���� S[j] Ϊ���ĵĻ����Ӵ���һ����ȫ�������� S[id] Ϊ���ĵĻ����Ӵ��У�
//���ǻ��ڶԳ��Կ�֪����ͼ�������̿�����Χ�Ĳ�������ͬ�ģ�Ҳ����˵�� S[i] Ϊ���ĵĻ����Ӵ���
//���������ٻ����ŵ� mx ��λ�ã�Ҳ����˵ P[i] = mx - i������ mx ֮��Ĳ����Ƿ�Գƣ���ֻ������ʵʵȥƥ���ˣ�
//����Ǻ�������� while ѭ�������á�
			while (t[i + p[i]] == t[i - p[i]]) ++p[i];//������߽�ʱ���ұ߻����Լ�����չ
			//��Ϊp[i] ��ʾ�� t[i] �ַ�Ϊ���ĵĻ����Ӵ��İ뾶������p[i]�϶�С��i�����Բ���i - p[i]>=0&&;Ȼ��Ҳ��i�����1��ʼ��ԭ�򣬷���i=0,p=1,���ǻ�Խ���
			//���i��0��ʼ��ôwhile(i-p[i]>=0&&t[i+p[i]]==t[i-p[i]])
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

//������ O(n^2)���Ӷȣ���Ҫ��ÿһ���ַ�Ϊ���ģ���������ɢ��Ѱ�һ��Ĵ�������ż����
//��ÿһ���ַ�Ϊ���ģ���������ɢ��Ѱ�һ��Ĵ�������㷨��ʱ�临�Ӷ��� O(n*n)������ͨ�� OJ��
//����Ҫע����ż��������ڻ��Ĵ��ĳ��ȿ����ż������ "bob" ��������ʽ�Ļ��ģ�"noon" ����ż����ʽ�Ļ��ģ�
//������ʽ�Ļ��Ķ�Ҫ����������������ʽ�ģ����Ǿʹӱ�������λ��Ϊ���ģ������߽�����ɢ������ż�������
//���ǾͰѵ�ǰλ�ú���һ��λ�õ���ż���л��ĵ����м������ַ���Ȼ�������߽�������
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size()<2)
		{
			return s;
		}
		int n = s.size(), maxlen = 0, start = 0;
		for (int i = 0; i<n - 1; ++i)
		{
			FindPalinrome(s, i, i, start, maxlen);
			FindPalinrome(s, i, i + 1, start, maxlen);
		}
		return s.substr(start, maxlen);
	}

	void FindPalinrome(string s, int left, int right, int &start, int &maxlen)
	{
		while (left >= 0 && right<s.size() && s[left] == s[right])
		{
			--left;
			++right;
		}
		if (maxlen<right - left - 1)
		{
			start = left + 1;
			maxlen = right - left - 1;
		}
	}
};


//��ϰ
class Solution {
public:
	string longestPalindrome(string s) {
		string t = "$#";
		for (int i = 0; i<s.size(); ++i)
		{
			// //t+='#'+s[i];//����д�Ǵ��
			t += s[i];
			t += '#';
		}
		int mx = 0, id = 0, resmx = 0, resid = 0;
		vector<int> p(t.size(), 0);
		for (int i = 0; i<t.size(); ++i)
		{
			p[i] = mx>i ? min(p[2 * id - i], mx - i) : 1;
			while (i - p[i] >= 0 && t[i + p[i]] == t[i - p[i]])
			{
				++p[i];
			}
			if (mx<i + p[i])
			{
				mx = i + p[i];
				id = i;
			}
			if (resmx<p[i])
			{
				resmx = p[i];
				resid = i;
			}
		}
		return s.substr((resid - resmx) / 2, resmx - 1);
	}
};


//��ϰ���Լ�д�Ľⷨ
class Solution {
public:
	string longestPalindrome(string s) {
		int maxcnt = 0;
		string maxstr = "";
		for (int i = 0; i<s.size(); ++i)
		{
			int cnt = 1;
			int begin = i - 1, end = i + 1;
			while (begin >= 0 && end<s.size() && s[begin] == s[end])
			{
				cnt += 2;
				--begin;
				++end;
			}

			int cnt2 = 0;
			int begin2 = i, end2 = i + 1;
			if (end2<s.size() && s[begin2] == s[end2])
			{
				cnt2 = 2;
				--begin2;
				++end2;
				while (begin2 >= 0 && end2<s.size() && s[begin2] == s[end2])
				{
					cnt2 += 2;
					--begin2;
					++end2;
				}
			}
			if (maxcnt<cnt)
			{
				maxcnt = cnt;
				maxstr = s.substr(begin + 1, maxcnt);
			}
			if (maxcnt<cnt2)
			{
				maxcnt = cnt2;
				maxstr = s.substr(begin2 + 1, maxcnt);
			}
		}
		return maxstr;
	}
};


//��ϰ
class Solution {
public:
	string longestPalindrome(string s) {
		string t = "$";
		for (int i = 0; i<s.size(); ++i)
		{
			t += '#';
			t += s[i];
		}
		t += '#';
		int id = 0, mx = 0, resid = 0, resmx = 0;
		vector<int> p(t.size(), 0);
		for (int i = 0; i<t.size(); ++i)
		{
			p[i] = mx>i ? min(p[id * 2 - i], mx - i) : 1;
			while (i - p[i] >= 0 && i + p[i]<t.size() && t[i + p[i]] == t[i - p[i]])
			{
				++p[i];
			}
			if (mx<i + p[i])
			{
				mx = i + p[i];
				id = i;
			}
			if (resmx<p[i])
			{
				resmx = p[i];
				resid = id;
			}
		}
		return s.substr((resid - resmx) / 2, resmx - 1);
	}
};

//��ϰ���Լ���д��
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 0)
		{
			return s;
		}
		string res = "";
		int maxcnt = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			string str = palindrome(s, i - 1, i + 1);
			int cnt = str.size();
			if (maxcnt<cnt)
			{
				maxcnt = cnt;
				res = str;
			}
			str = palindrome(s, i, i + 1);
			cnt = str.size();
			if (maxcnt<cnt)
			{
				maxcnt = cnt;
				res = str;
			}
		}
		return res;
	}
	string palindrome(string s, int begin, int end)
	{
		while (begin >= 0 && end<s.size() && s[begin] == s[end])
		{
			--begin;
			++end;
		}
		if (begin + 1 >= s.size())
		{
			return "";
		}
		return s.substr(begin + 1, end - begin - 1);
	}
};