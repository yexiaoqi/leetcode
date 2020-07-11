//ͬ��ָoffer 19
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
		{
			return s.empty();
		}
		if (p.size() == 1)
		{
			return (s.size() == 1) && (s[0] == p[0] || p[0] == '.');
		}
		if (p[1] != '*')
		{
			if (s.empty())
			{
				return false;
			}
			return(s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		if (!s.empty() && (s[0] == p[0] || p[0] == '.'))
		{
			return isMatch(s, p.substr(2)) || isMatch(s.substr(1), p);
		}
		return isMatch(s, p.substr(2));
	}
};


//��ϰ
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0)
		{
			return s.size() == 0 ? true : false;
		}
		if (p.size() == 1)
		{
			if ((s.size() == 1) && (p[0] == s[0] || (p[0] == '.')))//ע��s.size()==1��ÿ��&��Ҫ�ģ�����s="aa",p="a"
																   //if(p[0]==s[0]||((p[0]=='.')&&(s.size()==1)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (p[1] != '*')
		{
			if (p[0] == s[0] || ((p[0] == '.') && (s.size() >= 1)))
			{
				return isMatch(s.substr(1), p.substr(1));
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (p[0] == s[0] || ((p[0] == '.') && (s.size() >= 1)))
			{
				return isMatch(s, p.substr(2)) || isMatch(s.substr(1), p);
			}
			else
			{
				return isMatch(s, p.substr(2));
			}
		}
	}
};


//��ϰ2
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0)
		{
			return s.size() == 0;
		}
		if (p.size() == 1)
		{
			return (s.size() == 1 && (p[0] == s[0] || p[0] == '.'));
		}
		if (p[1] != '*')
		{
			if (s.empty())
			{
				return false;
			}
			return (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		else
		{
			if (s.size() >= 1 && (p[0] == s[0] || p[0] == '.'))
			{
				return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
			}
			else
			{
				return isMatch(s, p.substr(2));
			}
		}
	}
};

//��ϰ3
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
		{
			return s.empty();
		}
		else if (p.size() == 1)
		{
			return s.size() == 1 && (p[0] == s[0] || p[0] == '.');
		}
		else if (p[1] != '*')
		{
			if (s.size() >= 1 && (p[0] == s[0] || p[0] == '.'))
			{
				return isMatch(s.substr(1), p.substr(1));
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (s.size() >= 1 && (p[0] == s[0] || p[0] == '.'))
			{
				return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
				//p.substr(2)��ȥƥ��0����p��ȥƥ����
			}
			else
			{
				return isMatch(s, p.substr(2));
			}
		}
	}
};


//��ϰ
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0)
		{
			return s.size() == 0;
		}
		if (p.size() == 1)
		{
			if (s.size() != 1 || !(p[0] == s[0] || p[0] == '.'))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		if (p[1] != '*')
		{
			if (s.size()<1 || !(p[0] == s[0] || p[0] == '.'))
			{
				return false;
			}
			else
			{
				return isMatch(s.substr(1), p.substr(1));
			}
		}
		else
		{
			if (s.size() >= 1 && (s[0] == p[0] || p[0] == '.'))
			{
				return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
			}
			else
			{
				return isMatch(s, p.substr(2));
			}
		}
	}
};