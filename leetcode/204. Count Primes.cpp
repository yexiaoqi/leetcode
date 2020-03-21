//���Ǵ�2��ʼ����������n�����ҵ���һ������2��Ȼ�������еı���ȫ����ǳ�����Ȼ����һ������3��
//��������б�����һ�����ƣ�ֱ������n����ʱ������δ����ǵ����־���������
//������Ҫһ�� n - 1 ���ȵ� bool ����������¼ÿ�������Ƿ񱻱�ǣ�
//����Ϊ n - 1 ��ԭ������Ŀ˵��С��n��������������������n�� Ȼ����ʵ�ְ�����˹����ɸ��
class Solution {
public:
	int countPrimes(int n) {
		if (n<2)
		{
			return 0;
		}
		int res = 0;
		vector<bool> prime(n, true);
		for (int i = 2; i<n; ++i)
		{
			if (!prime[i])
			{
				continue;
			}
			++res;
			for (int j = 2; i*j<n; ++j)
			{
				prime[i*j] = false;
			}
		}
		return res;
	}
};