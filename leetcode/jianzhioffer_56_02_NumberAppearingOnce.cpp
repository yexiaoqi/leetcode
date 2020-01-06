//同leetcode137
//方法1
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
//方法2
class Solution {
public:
	int singleNumber(vector<int>& nums)
	{
		int result = 0;
		int count[32] = { 0 };//这里必须初始化，否则count的值不知道是什么
		for (int i = 0; i<32; ++i)
		{
			for (int j = 0; j<nums.size(); ++j)
			{
				count[i] += (nums[j] >> i) & 1;//&1,1其实是0000000...1 (前面31位0，最后1位1)，就是说只看nums[j]的第i位是不是1，所以&1不能少
				count[i] = count[i] % 3;
			}
			result |= (count[i] << i);//按位或
		}
		return result;
	}
};