//分解因子
class Solution {
public:
	int trailingZeroes(int n) {
		int res = 0;
		while (n)
		{
			res += n / 5;//例如125！，有25个数字包含了一个5，用125/5=25，25/5=5；说明其中5个数字包含了2个5（25,50,75,100,125），5/5=1，说明其中有一个数字包含3个5（125）
			n /= 5;
		}
		return res;
	}
};