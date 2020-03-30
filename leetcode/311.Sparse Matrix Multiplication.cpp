//某个元素C[i][j]是怎么来的，起始是A[i][0] * B[0][j] + A[i][1] * B[1][j] + ... + A[i][k] * B[k][j]，
//那么为了不重复计算0乘0，我们首先遍历A数组，要确保A[i][k]不为0，才继续计算，然后我们遍历B矩阵的第k行，
//如果B[K][J]不为0，我们累加结果矩阵res[i][j] += A[i][k] * B[k][j];

class Solution {
public:
	vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		int m = A.size(), n = B[0].size(), size = A[0].size();
		vector<vector<int>> res(m, vector<int>(n, 0));
		for (int i = 0; i<m; ++i)
		{
			for (int k = 0; k<size; ++k)
			{
				if (A[i][k] != 0)
				{
					for (int j = 0; j<n; ++j)
					{
						if (B[k][j] != 0)
						{
							res[i][j] += A[i][k] * B[k][j];
						}
					}
				}
			}
		}
		return res;
	}
};


//template
class Solution
{
public:
	//注意template<typename T>不应该放在class外面
	template<typename T>
	vector<vector<T>> multiply(vector<vector<T>>& A, vector<vector<T>>& B) {
		int m = A.size(), n = B[0].size(), size = A[0].size();
		vector<vector<T>> res(m, vector<T>(n, 0));
		for (int i = 0; i<m; ++i)
		{
			for (int k = 0; k<size; ++k)
			{
				if (A[i][k] != 0)
				{
					for (int j = 0; j<n; ++j)
					{
						if (B[k][j] != 0)
						{
							res[i][j] += A[i][k] * B[k][j];
						}
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	vector<vector<int>> A{ { 1,1 },{ 2,2 } };
	vector<vector<int>> B{ { 1,1 },{ 2,2 } };
	vector<vector<double>> A2{ { 1.0,1.0 },{ 2.0,2.0 } };
	vector<vector<double>> B2{ { 1.0,1.0 },{ 2.0,2.0 } };
	Solution s;
	vector<vector<int>> res1 = s.multiply<int>(A, B);
	vector<vector<double>> res2 = s.multiply<double>(A2, B2);
	return 0;
}