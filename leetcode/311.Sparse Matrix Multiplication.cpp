//ĳ��Ԫ��C[i][j]����ô���ģ���ʼ��A[i][0] * B[0][j] + A[i][1] * B[1][j] + ... + A[i][k] * B[k][j]��
//��ôΪ�˲��ظ�����0��0���������ȱ���A���飬Ҫȷ��A[i][k]��Ϊ0���ż������㣬Ȼ�����Ǳ���B����ĵ�k�У�
//���B[K][J]��Ϊ0�������ۼӽ������res[i][j] += A[i][k] * B[k][j];



//���⿼�����Ҫ��sparse������ԣ����û��������ԣ�һ��m*n�ľ����һ��n*p�ľ������˷�������ҪO(mnp)��ʱ�临�Ӷȡ�
//���ǣ��������A��sparse�ģ�BҲ���ԣ�������������һ��������ô�ڼ����п�������sparse�����ԣ�
//ֻ����A��ÿһ���еķ�������B��ÿһ���еĶ�Ӧ����ˣ��������B��sparse�����ԣ�����Ҳ���ơ�
//���ԣ������ϣ�ʱ�临�Ӷȿ�����O(kmp)������k��һ��ϡ���ϵ����
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
	//ע��template<typename T>��Ӧ�÷���class����
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