//同剑指offer 65
class Solution {
public:
	int getSum(int a, int b) {
		int sum = 0, carry = 0;
		while (b)
		{
			sum = a^b;
			carry = (a&b & 0x7fffffff) << 1;// LeetCode 自己的编译器比较 strict，不能对负数进行左移，就是说最高位符号位必须要为0
			a = sum;
			b = carry;
		}
		return sum;
	}
};