//ͬ��ָoffer15
//�Լ��ķ�����һ��ac
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int res = 0;
		for (int i = 0; i<32; ++i)
		{
			if ((1 << i)&n)
			{
				++res;
			}
		}
		return res;
	}
};

//������������
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int res = 0;
		while (n)
		{
			++res;
			n = n&(n - 1);
		}
		return res;
	}
};