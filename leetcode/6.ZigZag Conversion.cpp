//����һ����СΪ numRows ���ַ������飬Ϊ�ľ��ǰ�֮���ε������������ȥ��Ȼ���ٰ�ÿһ�е��ַ�ƴ��������
//������Ҫ�Ľ���ˡ�˳����ǰ��н��б���������ǰ numRows ���ַ����ǰ�˳�����ÿ�еĵ�һ��λ�ã�
//Ȼ����� ��֮�� ���ε�����λ���ˣ����Է�����ʵ��������������[1, numRows - 2] �ڣ�ֻҪ��˳��ȥȡ�ַ��Ϳ�����
//������ÿ�ж�ƴ��������Ϊ����
class Solution {
public:
	string convert(string s, int numRows) {
		vector<string> vec(numRows);
		int i = 0, n = s.size();
		while (i<n)
		{
			for (int pos = 0; pos<numRows&&i<n; ++pos)
			{
				vec[pos] += s[i++];
			}
			for (int pos = numRows - 2; pos >= 1 && i<n; --pos)
			{
				vec[pos] += s[i++];
			}
		}
		string res;
		for (int i = 0; i<vec.size(); ++i)
		{
			res += vec[i];
		}
		return res;
	}
};