//ͬ��ָoffer65
class Solution {
public:
	int getSum(int a, int b) {
		int res = a;
		while (b)
		{
			int tmp = (a&b & 0x7fffffff) << 1;//Ҫ��(),<<�����㼶���
			a = a^b;
			b = tmp;
			cout << a << " " << b << endl;
		}
		return a;
	}
};