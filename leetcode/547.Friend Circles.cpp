//��Ŀ�ж�������Ȧ�Ķ����ǿ��Դ��ݵģ�����A��B�Ǻ��ѣ�B��C�Ǻ��ѣ���ô��ʹA��C���Ǻ��ѣ�
//��ô��������Ҳ����һ������Ȧ����ô�Ƚ�ֱ�ӵĽⷨ���� DFS ����������ĳ���ˣ���������ѣ�
//Ȼ���ٱ�������ѵĺ��ѣ���ô���ܰ�����ͬһ������Ȧ���˶�����һ�飬ͬʱ��ǳ��Ѿ����������ˣ�
//Ȼ���ۻ�����Ȧ�ĸ�������ȥ����û�б�������������������Ȧ���ˣ������������������
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		if (M.size() == 0 || M[0].size() == 0)
		{
			return 0;
		}
		int n = M.size();
		vector<int> marker(n, 0);
		int cnt = 0;
		for (int j = 0; j<n; ++j)
		{
			if (marker[j] == 0)
			{
				DFS(M, marker, j);
				++cnt;
			}
		}
		return cnt;
	}
	void DFS(vector<vector<int>>& M, vector<int> &marker, int y)
	{
		marker[y] = 1;
		for (int i = 0; i<M.size(); ++i)
		{
			if (M[y][i] && marker[i] == 0)
			{
				DFS(M, marker, i);
			}
		}
	}
	void testall()
	{
		vector<vector<int>> a1{ { 1,1,0 },{ 1,1,0 },{ 0,0,1 } };
		test(a1);
	}
	void test(vector<vector<int>>& M)
	{
		cout << findCircleNum(M);
	}
};