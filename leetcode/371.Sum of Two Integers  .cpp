//ͬ��ָoffer 65
class Solution {
public:
	int getSum(int a, int b) {
		int sum = 0, carry = 0;
		while (b)
		{
			sum = a^b;
			carry = (a&b & 0x7fffffff) << 1;// LeetCode �Լ��ı������Ƚ� strict�����ܶԸ����������ƣ�����˵���λ����λ����ҪΪ0
			a = sum;
			b = carry;
		}
		return sum;
	}
};