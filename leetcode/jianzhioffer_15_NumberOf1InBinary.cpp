//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
class Solution {
public:
	int  NumberOf1(int n) {
		int cnt = 0;
		while (n)
		{
			++cnt;
			n = n&(n - 1);
		}
		return cnt;
	}
};

//复习，一遍ac
class Solution {
public:
	int  NumberOf1(int n) {
		int cnt = 0;
		while (n)
		{
			n = n&(n - 1);
			++cnt;
		}
		return cnt;
	}
};