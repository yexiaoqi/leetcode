//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes, �������No���������������������������ֶ�������ͬ��
//���ﲻ�ѿ������ɶ��������������ӡ�����
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int size = sequence.size();
		if (size == 0)
		{
			return false;
		}
		return Verify(sequence, 0, size);
	}
	bool Verify(vector<int> sequence, int start, int end)
	{
		int root = sequence[end - 1];
		int i = 0;
		for (; i<end; ++i)
		{
			if (sequence[i]>root)
			{
				break;
			}
		}
		for (int j = i; j<end; ++j)
		{
			if (sequence[j]<root)
			{
				return false;
			}
		}
		--end;
		bool left = true, right = true;
		if (i>1)
		{
			left = Verify(sequence, 0, i - 1);
		}
		if (i<end - 1)
		{
			right = Verify(sequence, i, end);
		}
		return left&&right;
	}
};