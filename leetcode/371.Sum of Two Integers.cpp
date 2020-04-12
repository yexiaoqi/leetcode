//同剑指offer65
class Solution {
public:
	int getSum(int a, int b) {
		int res = a;
		while (b)
		{
			int tmp = (a&b & 0x7fffffff) << 1;//要加(),<<的运算级别高
			a = a^b;
			b = tmp;
			cout << a << " " << b << endl;
		}
		return a;
	}
};