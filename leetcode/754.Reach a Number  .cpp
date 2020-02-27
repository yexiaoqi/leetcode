//我们的第二个 trick 就是，当超过目标值的差值d为偶数时，只要将第 d / 2 步的距离取反，就能得到目标值，此时的步数即为到达目标值的步数。那么，如果d为奇数时，且当前为第n步，那么我们看下一步 n + 1 的奇偶，如果 n + 1 为奇数，那么加上 n + 1 再做差，得到的差值就为偶数了，问题解决，如果 n + 1 为偶数，那么还得加上 n + 2 这个奇数，才能让差值为偶数，这样就多加了两步。分
class Solution {
public:
	int reachNumber(int target) {
		target = abs(target);
		long n = ceil((-1.0 + sqrt(1 + 8.0*target)) / 2);//要用8.0，否则乘上去超过int了
		long sum = n*(n + 1) / 2;
		cout << sum;
		if (sum == target)
		{
			return n;
		}
		long resi = sum - target;
		if (!(resi & 0x1))
		{
			return n;
		}
		else
		{
			if (n & 0x1)
			{
				return n + 2;
			}
			else
			{
				return n + 1;
			}
		}
	}
};