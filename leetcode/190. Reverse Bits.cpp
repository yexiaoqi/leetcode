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