/* ��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��*/
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int orilen = 0;
		int numblank = 0;
		for (int i = 0; i<strlen(str); ++i)
		{
			++orilen;
			if (str[i] == ' ')
			{
				++numblank;
			}
		}
		int newlen = orilen + 2 * numblank;
		int oriptr = orilen;//ע��Ҫ���ƽ�����'\0'�����Ա�strlen(str)Ҫ��1
		int newptr = newlen;
		while (oriptr >= 0)
		{
			if (str[oriptr] == ' ')
			{
				str[newptr--] = '0';//i++����ԭ����ֵ��++i ���ؼ�1���ֵ��
				str[newptr--] = '2';
				str[newptr--] = '%';
			}
			else {
				str[newptr--] = str[oriptr];
			}
			--oriptr;
		}

	}
};


//��ϰ���޸�һ��������ʽ
class Solution {
public:
	void replaceSpace(vector<char> str, int length)
		//void replaceSpace(char *str,int length) 
	{
		int cnt = 0;
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] == ' ')
			{
				++cnt;
			}
		}
		int n = str.size() - 1;
		str.insert(str.end(), 2 * cnt, "");
		int i = str.size() - 1;
		while (i >= 0)
		{
			if (str[n] != ' ')
			{
				str[i--] = str[n--];
			}
			else
			{
				str[i--] = '0';
				str[i--] = '2';
				str[i] = '%';
				n--;
			}
		}
	}
};

//��ϰ
class Solution {
public:
	void replaceSpace(char *str, int length)
	{
		int cnt = 0;
		for (int i = 0; i<strlen(str); ++i)
		{
			if (str[i] == ' ')
			{
				++cnt;
			}
		}
		int n = strlen(str);//ע��Ҫ���ƽ�����'\0'�����Բ���strlen(str)-1
		int i = n + 2 * cnt;
		while (i >= 0)
		{
			if (str[n] != ' ')
			{
				str[i--] = str[n--];
			}
			else
			{
				str[i--] = '0';
				str[i--] = '2';
				str[i--] = '%';
				n--;
			}
		}
	}
};


//��ϰ
class Solution {
public:
	string replaceSpace(string s) {
		if (s.size() == 0)
		{
			return s;
		}
		int cnt = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			if (s[i] == ' ')
			{
				++cnt;
			}
		}
		int i = s.size() - 1;
		int j = s.size() + 2 * cnt - 1;
		s.insert(s.end(), 2 * cnt, ' ');//ע��Ҫ����俪�¿ռ�
		while (i >= 0)
		{
			if (s[i] != ' ')
			{
				s[j--] = s[i--];
			}
			else
			{
				s[j--] = '0';
				s[j--] = '2';
				s[j--] = '%';
				--i;
			}
		}
		return s;
	}
};