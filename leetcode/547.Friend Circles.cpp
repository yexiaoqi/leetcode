//题目中对于朋友圈的定义是可以传递的，比如A和B是好友，B和C是好友，那么即使A和C不是好友，
//那么他们三人也属于一个朋友圈。那么比较直接的解法就是 DFS 搜索，对于某个人，遍历其好友，
//然后再遍历其好友的好友，那么就能把属于同一个朋友圈的人都遍历一遍，同时标记出已经遍历过的人，
//然后累积朋友圈的个数，再去对于没有遍历到的人在找其朋友圈的人，这样就能求出个数。
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