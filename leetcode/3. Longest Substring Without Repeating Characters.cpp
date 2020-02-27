//���ڴ����ڲ�ͣ���һ���������ֻ����ÿ���ַ������ֵ�λ�ã�������ӳ�䡣���ڵ��ұ߽���ǵ�ǰ���������ַ���λ�ã�
//Ϊ��������ڵĴ�С����Ҫһ������ left ��ָ�򻬶����ڵ���߽磬�����������ǰ���������ַ���δ���ֹ���
//��ôֱ�������ұ߽磬���֮ǰ���ֹ�����ô�ͷ�����������ڻ��ڻ��������ڣ�������ڻ��������ڣ���ô��û�£�
//��ǰ�ַ����Լӽ���������ڵĻ�������Ҫ���ڻ���������ȥ������Ѿ����ֹ����ַ��ˣ�
//ȥ���ķ���������Ҫ����߽� left һλһλ���ұ������ң����� HashMap �Ѿ������˸��ظ��ַ������ֵ�λ�ã�
//����ֱ���ƶ� left ָ��Ϳ����ˡ�ά��һ����� res��ÿ���ó��ֹ��Ĵ��ڴ�С�����½�� res���Ϳ��Եõ����ս������
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<int, int> m;
		int left = -1;
		int res = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			if (m.count(s[i]) && m[s[i]]>left)
			{
				left = m[s[i]];
			}
			m[s[i]] = i;
			res = max(res, i - left);
		}
		return res;
	}
};



//�Լ�д��
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxlen = 0;
		unordered_map<char, int> mapping;//ע����unordered_map������map��unordered_map���ҿ�
		int len = 0;
		int index = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			if (mapping[s[i]] == 0)//�ж�value������key
								   //����������if�����ԣ���Ϊmap���ҵ���key�����硰tmmzuxt������Ȼ�ڵڶ���m��ʼ��mapping[t]�Ѿ���0��value��0�������ǻ�����t��key��Ϊ0�����������һ��t�㲻��ȥ
								   //if (mapping.count(s[i]) == 0)
								   //if (mapping.find(s[i]) == mapping.end())
			{
				++len;
				mapping[s[i]] = 1;
				if (maxlen<len)
				{
					maxlen = len;
				}
			}
			else
			{
				while (s[index] != s[i])
				{
					--mapping[s[index]];
					++index;
				}
				len = i - index;
				++index;
			}
		}
		return maxlen;
	}
};



class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int begin = 0;
		int result = 0;
		string word = "";
		int char_map[128] = { 0 };//ע���ʼ��Ϊ0
		for (int i = 0; i<s.length(); ++i)
		{
			++char_map[s[i]];
			if (char_map[s[i]] == 1)
			{
				word += s[i];
				if (result<word.length())
				{
					result = word.length();
				}
			}
			else
			{
				while (char_map[s[i]]>1)
				{
					--char_map[s[begin]];
					++begin;
				}

				word = "";
				for (int j = begin; j <= i; ++j)
				{
					word += s[j];
				}
			}
		}
		return result;
	}
};


//��ϰ
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<int, int> m;
		int maxlen = 0, index = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			if (m[s[i]] == 0)
			{
				++m[s[i]];
				if (maxlen<i - index + 1)
				{
					maxlen = i - index + 1;
				}
			}
			else
			{
				int k = index;
				for (; k<i; ++k)
				{
					if (m[s[i]] != 0)
					{
						--m[s[k]];
					}
					else
					{
						break;
					}
				}
				index = k;
				++m[s[i]];
			}
		}
		return maxlen;
	}
};


//��ϰ
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<int, int> m;
		int left = -1, res = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			if (m.count(s[i]) && m[s[i]]>left)
			{
				left = m[s[i]];
			}
			m[s[i]] = i;
			if (res<i - left)
			{
				res = i - left;
			}
		}
		return res;
	}
};