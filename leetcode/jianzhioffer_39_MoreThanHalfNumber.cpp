//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{ 1,2,3,2,2,2,5,4,2 }����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
//�Լ�д�ķ���
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