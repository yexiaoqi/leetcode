/*��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и������� */
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int sizei = int(array.size());
		int sizej = int(array[0].size());
		int i = 0, j = sizej - 1;
		while (i<sizei&&j >= 0)
		{
			if (array[i][j] == target)
			{
				return true;
			}
			else if (array[i][j]>target)
			{
				--j;
			}
			else
			{
				++i;
			}
		}
		return false;
	}
};