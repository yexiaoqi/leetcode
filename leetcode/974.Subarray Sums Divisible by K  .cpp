//通常，涉及连续子数组问题的时候，我们使用前缀和来解决。我们令 P[i] = A[0] + A[1] + ... + A[i]。那么，每个连续子数组的和 sum(i, j) 就可以写成 P[j] - P[i - 1] （其中 j > i 且 i > 0） 的形式。那么判断子数组的和能否被 K 整除就可以写成(P[j] - P[i - 1]) % K == 0，根据 同余定理 ，只要 P[j] % K == P[i - 1] % K，就可以保证上面的式子成立。
//
//根据上面的思路，我们只需要一次遍历计算所有前缀和模 K 的值的数量，然后用排列组合的方法来计算答案即可。
//1, C
//2
//​
//= 1, C
//4
//​
//= 4：
//
//对于 C_4 = 4C
//4
//​
//= 4（P[0]P[0]、P[1]P[1]、P[2]P[2]、P[4]P[4]），这表示一共有 \binom{ 4 }{2} = 6(
//	2
//	4
//	​
//	) = 6 个连续子数组的和能被 KK 整除，分别是 A[1:2]A[1:2]、A[1:3]A[1:3]、A[1:5]A[1:5]、A[2:3]A[2:3]、A[2:5]A[2:5]、A[3:5]A[3:5] （A[i:j]A[i:j] 表示下标从 ii 到 j - 1j−1）。
//	上面的算法没有考虑到 P[i]P[i] 本身就能被 K 整除，我们可以在数组 P 前面加一个 0 处理这种情况。
//
//	注意：不同的语言负数取模的值不一定相同，有的语言为负数，对于这种情况需要特殊处理。
class Solution {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		int n = A.size();
		vector<int> sum(n, 0);
		int tmpsum = 0;
		unordered_map<int, int> m;
		int res = 0;
		for (int i = 0; i<n; ++i)
		{
			tmpsum += A[i];
			//sum[i]=tmpsum%K;
			sum[i] = (tmpsum%K + K) % K;//注意余数要是正的
			cout << tmpsum%K << " " << (tmpsum%K + K) % K << endl;
			++m[sum[i]];
		}
		++m[0];
		for (auto a = m.begin(); a != m.end(); ++a)
		{
			// cout<<(*a).first<<(*a).second<<endl;
			res += (*a).second*((*a).second - 1) / 2;
		}
		return res;
	}
};

