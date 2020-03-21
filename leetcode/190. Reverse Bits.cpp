//把要翻转的数从右向左一位位的取出来，如果取出来的是1，将结果 res 左移一位并且加上1；
//如果取出来的是0，将结果 res 左移一位，然后将n右移一位即可
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for (int i = 0; i<32; ++i)
		{
			res = (res << 1) | (n & 1);
			//上面一行代替下面几行
			// if(n&1==1)
			// {
			//     res=res<<1+1;
			// }
			// else
			// {
			//     res=res<<1;
			// }
			n >>= 1;
		}
		return res;
	}
};