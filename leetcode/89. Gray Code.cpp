//The gray code is a binary numeral system where two successive values differ in only one bit.
//
//Given a non - negative integer n representing the total number of bits in the code, print the sequence of gray code.A gray code sequence must begin with 0.
//
//For example, given n = 2, return[0, 1, 3, 2].Its gray code sequence is :
//
//00 - 0
//01 - 1
//11 - 3
//10 - 2
//Note :
//	For a given n, a gray code sequence is not uniquely defined.
//
//	For example, [0, 2, 3, 1] is also a valid gray code sequence according to the above definition.
//
//	For now, the judge is able to judge based on one instance of gray code sequence.Sorry about that.
//
//

class Solution
	//迭代处理，n=3的结果是以n=2为基础得到的，00 01 11 10和100按位或，即000 001 011 010逆序与100按位或，
	//则最高位得到1，其余位不变，即又push_back 110  111 101 100，且010和110也只有1位不一样
{
public:
	vector<int> grayCode(int n)
	{
		vector<int>res(1, 0);
		for (int i = 0;i<n;++i)
		{
			for (int j = res.size() - 1;j >= 0;--j)
			{
				res.push_back(res[j] | 1 << i);//1左移i位
			}
		}
		return res;
	}
};

//https://www.cnblogs.com/grandyang/p/4315649.html