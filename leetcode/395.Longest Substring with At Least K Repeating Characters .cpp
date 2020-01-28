//�Լ��ķ���������ʱ������
class Solution {
public:
	int longestSubstring(string s, int k) {
		if (s.size()<k)
		{
			return 0;
		}
		int res = 0;
		for (int i = 0; i<s.size() - k + 1; ++i)
		{
			unordered_map<char, int> m;
			//bool judge=true;
			for (int j = i; j<s.size(); ++j)
			{
				bool judge = true;//Ӧ�÷�������жϣ�������һ��Ϊfalse�ⲻ����
				++m[s[j]];
				unordered_map<char, int>::iterator a;
				if (j - i + 1 >= k)
				{
					for (a = m.begin(); a != m.end(); ++a)
					{
						if ((*a).second<k)
						{
							judge = false;
							break;//ֱ��break������continue����һ��
						}
					}
					if (judge == false)
						//if(a!=m.end())//������������Ϊ��������һ�����ϸ�Ҳ�ǲ��ϸ�ȴû��continue
					{
						continue;
					}
					if (res<j - i + 1)
					{
						res = j - i + 1;
					}
				}
			}
		}
		return res;
	}
};

//����ͨ�������map�����ǳ�ʱ
class Solution {
public:
	int longestSubstring(string s, int k) {
		if (s.size()<k)
		{
			return 0;
		}
		int res = 0;
		for (int i = 0; i<s.size() - k + 1; ++i)
		{
			int m[26] = { 0 };
			//unordered_map<char,int> m;
			//bool judge=true;
			for (int j = i; j<s.size(); ++j)
			{
				bool judge = true;//Ӧ�÷�������жϣ�������һ��Ϊfalse�ⲻ����
				++m[s[j] - 'a'];
				// unordered_map<char,int>::iterator a;
				if (j - i + 1 >= k)
				{
					for (int a = 0; a<26; ++a)
					{
						if (m[a] != 0 && m[a]<k)
						{
							judge = false;
							break;
						}
					}
					// for(a=m.begin();a!=m.end();++a)
					// {
					//     if((*a).second<k)
					//     {
					//         judge=false;
					//         continue;
					//     }
					// }
					if (judge == false)
						//if(a!=m.end())//������������Ϊ��������һ�����ϸ�Ҳ�ǲ��ϸ�ȴû��continue
					{
						continue;
					}
					if (res<j - i + 1)
					{
						res = j - i + 1;
					}
				}
			}
		}
		return res;
	}
};


//o(n^2)����
class Solution {
public:
	int longestSubstring(string s, int k) {
		int res = 0, i = 0, n = s.size();
		while (i + k <= n)
			{
				int m[26] = { 0 }, mask = 0, max_idx = i;
				for (int j = i; j < n; ++j) {
					int t = s[j] - 'a';
					++m[t];
					if (m[t] < k)
						mask |= (1 << t);//�����С��k���� mask �Ķ�Ӧλ��Ϊ1
					else
						mask &= (~(1 << t));//������ڵ���k���� mask ��Ӧλ��Ϊ0
					if (mask == 0)
					{
						res = max(res, j - i + 1);
						max_idx = j;//����baaacbbbb��k=2����һ��max_idx��a��λ�ã�Ȼ��i��c�ٿ�ʼ��֮���ܷ��ָ�����bbbb
					}
				}
				i = max_idx + 1;
			}
		return res;
	}
};


//���η�
class Solution {
public:
	int longestSubstring(string s, int k) {
		int n = s.size(), res = 0, max_idx = 0;
		int m[26] = { 0 };
		bool judge = true;
		for (int i = 0; i<s.size(); ++i)
		{
			++m[s[i] - 'a'];
		}
		for (int i = 0; i<n; ++i)
		{
			if (m[s[i] - 'a']<k)
			{
				res = max(res, longestSubstring(s.substr(max_idx, i - max_idx), k));
				judge = false;
				max_idx = i + 1;
			}
		}
		return judge ? n : max(res, longestSubstring(s.substr(max_idx, n - max_idx), k));
	}
};