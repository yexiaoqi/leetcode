//ͬleetcode137
//����1
class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int ones = 0, twos = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			ones = (ones^nums[i])&~twos;
			twos = (twos^nums[i])&~ones;
		}
		return ones;
	}
};
//����2
class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int result = 0;
		int count[32] = { 0 };//��������ʼ��������count��ֵ��֪����ʲô
		for (int i = 0; i<32; ++i)
		{
			for (int j = 0; j<nums.size(); ++j)
			{
				count[i] += (nums[j] >> i) & 1;//&1,1��ʵ��0000000...1 (ǰ��31λ0�����1λ1)������˵ֻ��nums[j]�ĵ�iλ�ǲ���1������&1������
				count[i] = count[i] % 3;
			}
			result |= (count[i] << i);//��λ��
		}
		return result;
	}
};