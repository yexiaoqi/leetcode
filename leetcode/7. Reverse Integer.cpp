class Solution {
public:
	int reverse(int x) {
		int res = 0;//ע��res�����ʼ��Ϊ0������leetcodeͨ����
		while (x != 0)
		{
			if (abs(res)>INT_MAX / 10)
			{
				return 0;
			}
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};