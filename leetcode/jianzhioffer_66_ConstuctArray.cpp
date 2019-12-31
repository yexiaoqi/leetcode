class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		if (A.size() <= 1)
		{
			return vector<int>();
		}
		vector<int> res(A.size(), 0);
		vector<int> B(A.size(), 1);
		vector<int> C(A.size(), 1);
		for (int i = 1; i<A.size(); ++i)
		{
			B[i] = B[i - 1] * A[i - 1];
		}
		for (int i = A.size() - 2; i >= 0; --i)
		{
			C[i] = C[i + 1] * A[i + 1];
		}
		for (int i = 0; i<A.size(); ++i)
		{
			res[i] = B[i] * C[i];
		}
		return res;
	}
};