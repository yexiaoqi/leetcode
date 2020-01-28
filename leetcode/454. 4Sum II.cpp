//�Լ��ķ�����ͨ��
class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int size = A.size();
		int bigsize = size*size;
		// sort(A.begin(),A.end());
		// sort(B.begin(),B.end());
		// sort(C.rbegin(),C.rend());
		// sort(D.rbegin(),D.rend());
		vector<int> sum1(bigsize, 0);
		for (int i = 0; i<size; ++i)
		{
			for (int j = 0; j<size; ++j)
			{
				sum1[i*size + j] = A[i] + B[j];
			}
		}
		sort(sum1.begin(), sum1.end());
		vector<int> sum2(bigsize, 0);
		for (int i = 0; i<size; ++i)
		{
			for (int j = 0; j<size; ++j)
			{
				sum2[i*size + j] = C[i] + D[j];
			}
		}
		sort(sum2.rbegin(), sum2.rend());
		int i = 0, j = 0, cnt = 0;
		while (i<bigsize&&j<bigsize)
		{
			int bigsum = sum1[i] + sum2[j];
			if (bigsum>0)
			{
				++j;
			}
			else if (bigsum<0)
			{
				++i;
			}
			else
			{
				//++cnt;
				int numi = 1, numj = 1;
				while (i + 1<bigsize&&sum1[i + 1] == sum1[i])
				{
					++i;
					++numi;
				}
				while (j + 1<bigsize&&sum2[j + 1] == sum2[j])
				{
					++j;
					++numj;
				}
				cnt += numi*numj;
				++i;
				++j;
				//������ôдҲ�Ǵ�ģ�cntӦ����numi*numj������numi+numj
				// while(i+1<bigsize&&sum1[i+1]==sum1[i])
				// {
				//     ++cnt;
				//     ++i;
				// }
				// ++i;
				// while(j+1<bigsize&&sum2[j+1]==sum2[j])
				// {
				//     ++cnt;
				//     ++j;
				// }
				// ++j;
				//����ֱ��++i,++j;����sum1��sum2��������0������Բ����ĸ���϶���������
				// ++i;
				// ++j;
			}
		}
		return cnt;
	}
};


class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> m;
		int size = A.size();
		for (int i = 0; i<size; ++i)
		{
			for (int j = 0; j<size; ++j)
			{
				int sum = A[i] + B[j];
				++m[sum];
			}
		}
		int cnt = 0;
		for (int i = 0; i<size; ++i)
		{
			for (int j = 0; j<size; ++j)
			{
				int sum = -(C[i] + D[j]);
				cnt += m[sum];
			}
		}
		return cnt;
	}
};