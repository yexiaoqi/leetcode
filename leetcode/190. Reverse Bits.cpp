//��Ҫ��ת������������һλλ��ȡ���������ȡ��������1������� res ����һλ���Ҽ���1��
//���ȡ��������0������� res ����һλ��Ȼ��n����һλ����
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for (int i = 0; i<32; ++i)
		{
			res = (res << 1) | (n & 1);
			//����һ�д������漸��
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