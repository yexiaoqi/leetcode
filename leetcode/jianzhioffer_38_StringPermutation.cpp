//��Ŀ����
//����һ���ַ���, ���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc, ���ӡ�����ַ�a, b, c�������г����������ַ���abc, acb, bac, bca, cab��cba��
//�������� :
//����һ���ַ���, ���Ȳ�����9(�������ַ��ظ�), �ַ�ֻ������Сд��ĸ��


//������leetcode47һ��
class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> res;
		if (str.length() == 0)
		{
			return res;
		}
		set<string> res_set;
		string  path;
		vector<int> visited(str.length(), 0);
		sort(str.begin(), str.end());
		dfs(str, res_set, path, 0, visited);
		return vector<string>(res_set.begin(), res_set.end());
	}
	void dfs(string str, set<string> &res, string  &s, int level, vector<int> &visited)
	{
		if (level == str.length())
		{
			res.insert(s);
			return;
		}
		for (int i = 0; i<int(str.length()); ++i)
		{
			if (visited[i] == 1)
			{
				continue;
			}
			s = s + str[i];
			visited[i] = 1;
			dfs(str, res, s, level + 1, visited);
			s.pop_back();
			visited[i] = 0;
		}
	}
};


//��ϰ
class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.size() == 0)
		{
			return vector<string>();
		}//Ҫ���пգ�����յ�ʱ�����[""]
		string one;
		set<string> res_set;
		vector<int> marker(str.size(), 0);
		Permu(str, one, res_set, marker, 0);
		return vector<string>(res_set.begin(), res_set.end());
	}
	void Permu(string str, string &one, set<string> &res, vector<int> &marker, int pos)
	{
		if (pos == str.size())
		{
			res.insert(one);
			return;
		}
		for (int i = 0; i<str.size(); ++i)
		{
			if (marker[i] == 1)
			{
				continue;
			}
			marker[i] = 1;
			one += str[i];
			Permu(str, one, res, marker, pos + 1);
			one.pop_back();//û��-=
			marker[i] = 0;
		}
	}

};