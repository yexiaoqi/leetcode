//同剑指offer15
//自己的方法，一遍ac
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

//方法二，更快
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