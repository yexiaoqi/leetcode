//我们从2开始遍历到根号n，先找到第一个质数2，然后将其所有的倍数全部标记出来，然后到下一个质数3，
//标记其所有倍数，一次类推，直到根号n，此时数组中未被标记的数字就是质数。
//我们需要一个 n - 1 长度的 bool 型数组来记录每个数字是否被标记，
//长度为 n - 1 的原因是题目说是小于n的质数个数，并不包括n。 然后来实现埃拉托斯特尼筛法
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