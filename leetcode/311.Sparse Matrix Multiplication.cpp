//某个元素C[i][j]是怎么来的，起始是A[i][0] * B[0][j] + A[i][1] * B[1][j] + ... + A[i][k] * B[k][j]，
//那么为了不重复计算0乘0，我们首先遍历A数组，要确保A[i][k]不为0，才继续计算，然后我们遍历B矩阵的第k行，
//如果B[K][J]不为0，我们累加结果矩阵res[i][j] += A[i][k] * B[k][j];



//本题考查的主要是sparse这个特性，如果没有这个特性，一个m*n的矩阵和一个n*p的矩阵做乘法运算需要O(mnp)的时间复杂度。
//但是，如果矩阵A是sparse的（B也可以，两个至少其中一个），那么在计算中可以利用sparse的特性，
//只考虑A的每一行中的非零项与B的每一列中的对应项相乘；如果利用B的sparse的特性，过程也类似。
//所以，理论上，时间复杂度可以是O(kmp)，其中k是一个稀疏的系数。
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