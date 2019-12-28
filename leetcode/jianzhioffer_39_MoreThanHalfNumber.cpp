//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{ 1,2,3,2,2,2,5,4,2 }。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
//自己写的方法
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		map<int, int> mapping;
		int size = numbers.size();
		set<int> numset(numbers.begin(), numbers.end());
		for (int i = 0; i<size; ++i)
		{

			if (numset.find(numbers[i]) == numset.end())
			{
				mapping[numbers[i]] = 1;
			}
			else {
				++mapping[numbers[i]];
			}
			if (mapping[numbers[i]]>(size / 2))
			{
				return numbers[i];
			}
		}
		return 0;
	}
};